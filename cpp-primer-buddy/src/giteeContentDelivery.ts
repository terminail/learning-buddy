import * as vscode from 'vscode';
import * as crypto from 'crypto';
import * as os from 'os';
import * as path from 'path';
import * as https from 'https';
import { LicenseInfo } from './contentProtection';

// Simple HTTPS request function as an alternative to fetch
function httpsRequest(url: string, options: any = {}): Promise<any> {
    return new Promise((resolve, reject) => {
        const urlObj = new URL(url);
        const requestOptions = {
            hostname: urlObj.hostname,
            port: urlObj.port,
            path: urlObj.pathname + urlObj.search,
            method: options.method || 'GET',
            headers: options.headers || {}
        };

        const req = https.request(requestOptions, (res) => {
            let data = '';
            
            res.on('data', (chunk) => {
                data += chunk;
            });
            
            res.on('end', () => {
                try {
                    const jsonData = JSON.parse(data);
                    resolve({
                        ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                        status: res.statusCode || 0,
                        statusText: res.statusMessage || '',
                        json: () => Promise.resolve(jsonData),
                        text: () => Promise.resolve(data)
                    });
                } catch (error) {
                    resolve({
                        ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                        status: res.statusCode || 0,
                        statusText: res.statusMessage || '',
                        text: () => Promise.resolve(data)
                    });
                }
            });
        });
        
        req.on('error', (error) => {
            reject(error);
        });
        
        if (options.body) {
            req.write(options.body);
        }
        
        req.end();
    });
}

/**
 * GiteeContentDelivery handles fetching content from Gitee private repositories
 * and tracking license usage through centralized Gitee repositories.
 */
export class GiteeContentDelivery {
    private context: vscode.ExtensionContext;
    private trackingToken: string;

    constructor(context: vscode.ExtensionContext) {
        this.context = context;
        // In a real implementation, this would be a secure token for tracking usage
        // This should be kept secret and not included in the license
        this.trackingToken = this.getTrackingToken();
    }

    /**
     * Fetch content from Gitee private repository
     * @param licenseInfo License information containing Gitee access details
     * @param filePath Path to the file in the repository
     * @returns Content as string, or null if failed
     */
    public async fetchContent(licenseInfo: LicenseInfo, filePath: string): Promise<string | null> {
        try {
            // Check if Gitee information is available
            if (!licenseInfo.gitee) {
                vscode.window.showErrorMessage('License does not contain Gitee access information');
                return null;
            }

            // Check if download is allowed
            const canDownload = await this.canDownload(licenseInfo);
            if (!canDownload.allowed) {
                vscode.window.showErrorMessage(`Download limit exceeded. ${canDownload.remaining} downloads remaining.`);
                return null;
            }

            // Get user's content access token from license
            const contentToken = this.decryptToken(licenseInfo.gitee.accessToken);
            
            // Fetch content from Gitee
            const contentUrl = `https://gitee.com/api/v5/repos/${licenseInfo.gitee.contentRepo}/contents/${filePath}`;
            
            const response = await httpsRequest(contentUrl, {
                headers: {
                    'Authorization': `token ${contentToken}`,
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                const data: any = await response.json();
                const content = Buffer.from(data.content, 'base64').toString('utf-8');
                
                // Record successful download
                await this.recordDownload(licenseInfo, filePath);
                
                return content;
            } else {
                vscode.window.showErrorMessage(`Failed to fetch content from Gitee: ${response.status} ${response.statusText}`);
            }
        } catch (error) {
            vscode.window.showErrorMessage(`Error fetching content from Gitee: ${error}`);
            console.error('Error fetching content from Gitee:', error);
        }
        
        return null;
    }

    /**
     * Check if a license can download content (respects download limits)
     * @param licenseInfo License information
     * @returns Object with allowed status and remaining downloads
     */
    private async canDownload(licenseInfo: LicenseInfo): Promise<{allowed: boolean, remaining: number}> {
        try {
            // Check if Gitee information is available
            if (!licenseInfo.gitee) {
                return { allowed: false, remaining: 0 };
            }

            // Create a unique user identifier
            const userId = await this.generateUserId();
            
            // Check usage from tracking repository
            const usageUrl = `https://gitee.com/api/v5/repos/${licenseInfo.gitee.trackingRepo}/contents/usage/${licenseInfo.id}.json`;
            
            const response = await httpsRequest(usageUrl, {
                headers: {
                    'Authorization': `token ${this.trackingToken}`,
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                const data: any = await response.json();
                const usageData = JSON.parse(Buffer.from(data.content, 'base64').toString('utf-8'));
                const currentDownloads = usageData.downloadCount || 0;
                const maxDownloads = licenseInfo.limits?.maxDownloads || 3;
                const remaining = maxDownloads - currentDownloads;
                
                return {
                    allowed: remaining > 0,
                    remaining: remaining
                };
            } else if (response.status === 404) {
                // New license, no usage recorded yet
                return {
                    allowed: true,
                    remaining: licenseInfo.limits?.maxDownloads || 3
                };
            }
        } catch (error) {
            console.error('Error checking license usage:', error);
            // Fail safe: allow download if tracking fails
            return { allowed: true, remaining: 3 };
        }
        
        return { allowed: false, remaining: 0 };
    }

    /**
     * Record a download in the tracking repository
     * @param licenseInfo License information
     * @param filePath Path to the file that was downloaded
     */
    private async recordDownload(licenseInfo: LicenseInfo, filePath: string): Promise<void> {
        try {
            // Check if Gitee information is available
            if (!licenseInfo.gitee) {
                return;
            }

            const userId = await this.generateUserId();
            
            // Get current usage data
            let usageData = {
                licenseId: licenseInfo.id,
                downloadCount: 1,
                downloads: [{
                    timestamp: new Date().toISOString(),
                    filePath: filePath,
                    userId: userId
                }]
            };
            
            // Try to get existing data
            const usageUrl = `https://gitee.com/api/v5/repos/${licenseInfo.gitee.trackingRepo}/contents/usage/${licenseInfo.id}.json`;
            const getResponse = await httpsRequest(usageUrl, {
                headers: {
                    'Authorization': `token ${this.trackingToken}`,
                    'Accept': 'application/json'
                }
            });
            
            if (getResponse.ok) {
                const existingData: any = await getResponse.json();
                const parsedData = JSON.parse(Buffer.from(existingData.content, 'base64').toString('utf-8'));
                usageData.downloadCount = parsedData.downloadCount + 1;
                usageData.downloads = [...parsedData.downloads, {
                    timestamp: new Date().toISOString(),
                    filePath: filePath,
                    userId: userId
                }];
            }
            
            // Update the file using Gitee's API
            await httpsRequest(usageUrl, {
                method: 'PUT',
                headers: {
                    'Authorization': `token ${this.trackingToken}`,
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    message: `Update usage for ${licenseInfo.id}`,
                    content: Buffer.from(JSON.stringify(usageData, null, 2)).toString('base64')
                })
            });
        } catch (error) {
            console.error('Error recording usage:', error);
        }
    }

    /**
     * Generate a unique but anonymous user identifier
     * @returns User identifier as string
     */
    private async generateUserId(): Promise<string> {
        // Generate a hash based on machine-specific information
        const machineId = await this.getMachineId();
        const hash = crypto.createHash('sha256');
        hash.update(machineId);
        return hash.digest('hex').substring(0, 16);
    }

    /**
     * Get machine-specific identifier
     * @returns Machine identifier as string
     */
    private async getMachineId(): Promise<string> {
        // Get machine-specific information
        const networkInterfaces = os.networkInterfaces();
        
        // Use the first MAC address as identifier
        for (const interfaceName in networkInterfaces) {
            const networkInterface = networkInterfaces[interfaceName];
            if (networkInterface) {
                for (const interfaceInfo of networkInterface) {
                    if (!interfaceInfo.internal && interfaceInfo.mac) {
                        return interfaceInfo.mac;
                    }
                }
            }
        }
        
        // Fallback to hostname
        return os.hostname();
    }

    /**
     * Decrypt a token (in a real implementation, this would use proper encryption)
     * @param encryptedToken Encrypted token
     * @returns Decrypted token
     */
    private decryptToken(encryptedToken: string): string {
        // In a real implementation, this would decrypt the token
        // For now, we'll just return the token as-is
        return encryptedToken;
    }

    /**
     * Get the tracking token (in a real implementation, this would be securely stored)
     * @returns Tracking token
     */
    private getTrackingToken(): string {
        // In a real implementation, this would be securely stored and retrieved
        // For now, we'll return a placeholder
        return 'YOUR_TRACKING_TOKEN_HERE';
    }
}