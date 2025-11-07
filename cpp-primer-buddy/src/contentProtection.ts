import * as vscode from 'vscode';
import * as crypto from 'crypto';
import * as fs from 'fs';
import * as path from 'path';

/**
 * ContentProtectionManager handles the protection and access control for course content.
 * It manages license verification and determines which content is accessible.
 */
export class ContentProtectionManager {
    private context: vscode.ExtensionContext;
    private protectedChapters: Set<string>;
    private validLicenses: Map<string, LicenseInfo>;
    private publicKey: string;

    constructor(context: vscode.ExtensionContext) {
        this.context = context;
        this.protectedChapters = new Set([
            '7_classes',
            '8_io',
            // Additional protected chapters can be added here
        ]);
        this.validLicenses = new Map();
        
        // Load the public key for license verification
        this.publicKey = this.loadPublicKey();
        console.log('Public key loaded:', this.publicKey ? 'YES' : 'NO');
        this.loadLicenses();
    }

    /**
     * Load the public key from the license-keys directory
     * @returns The public key as a string
     */
    private loadPublicKey(): string {
        try {
            const extensionPath = this.context.extensionPath;
            const publicKeyPath = path.join(extensionPath, 'licence-keys', 'public-key.txt');
            console.log('Loading public key from:', publicKeyPath);
            const publicKey = fs.readFileSync(publicKeyPath, 'utf8');
            console.log('Public key loaded successfully, length:', publicKey.length);
            return publicKey;
        } catch (error) {
            console.error('Error loading public key:', error);
            // Fallback to a simple verification for development
            return '';
        }
    }

    /**
     * Check if a chapter is protected and requires a license
     * @param chapterPath The path of the chapter to check
     * @returns true if the chapter is protected, false otherwise
     */
    public isChapterProtected(chapterPath: string): boolean {
        return this.protectedChapters.has(chapterPath);
    }

    /**
     * Check if a chapter is accessible (either not protected or has valid license)
     * @param chapterPath The path of the chapter to check
     * @returns true if the chapter is accessible, false otherwise
     */
    public isChapterAccessible(chapterPath: string): boolean {
        // If chapter is not protected, it's always accessible
        if (!this.isChapterProtected(chapterPath)) {
            return true;
        }

        // If chapter is protected, check if we have any valid license
        return this.hasValidLicense();
    }

    /**
     * Add a license key to the system
     * @param licenseKey The license key to add
     * @returns true if the license is valid and was added, false otherwise
     */
    public async addLicense(licenseKey: string): Promise<boolean> {
        try {
            console.log('Attempting to add license key');
            const licenseInfo = await this.verifyLicense(licenseKey);
            if (licenseInfo) {
                console.log('License verified successfully');
                this.validLicenses.set(licenseInfo.id, licenseInfo);
                this.saveLicenses();
                return true;
            } else {
                console.log('License verification failed');
            }
        } catch (error) {
            console.error('Error adding license:', error);
        }
        return false;
    }

    /**
     * Remove a license from the system
     * @param licenseId The ID of the license to remove
     */
    public removeLicense(licenseId: string): void {
        this.validLicenses.delete(licenseId);
        this.saveLicenses();
    }

    /**
     * Get all valid licenses
     * @returns Array of valid licenses
     */
    public getValidLicenses(): LicenseInfo[] {
        return Array.from(this.validLicenses.values());
    }

    /**
     * Check if we have any valid license
     * @returns true if we have at least one valid license, false otherwise
     */
    private hasValidLicense(): boolean {
        return this.validLicenses.size > 0;
    }

    /**
     * Verify a license key using cryptographic signature verification
     * @param licenseKey The license key to verify
     * @returns LicenseInfo if valid, null otherwise
     */
    private async verifyLicense(licenseKey: string): Promise<LicenseInfo | null> {
        try {
            console.log('Verifying license key, length:', licenseKey.length);
            
            // Parse the license key (format: data|signature)
            const parts = licenseKey.split('|');
            if (parts.length !== 2) {
                console.log('Invalid license key format: incorrect number of parts', parts.length);
                return null;
            }

            const licenseData = parts[0];
            const signature = parts[1];
            
            console.log('License data length:', licenseData.length);
            console.log('Signature length:', signature.length);

            // Check if public key is loaded
            if (!this.publicKey) {
                console.log('Public key not loaded');
                return null;
            }

            // Verify the signature using the public key
            const verifier = crypto.createVerify('SHA256');
            verifier.update(licenseData);
            verifier.end();

            const isVerified = verifier.verify(this.publicKey, signature, 'base64');
            console.log('Signature verification result:', isVerified);
            
            if (!isVerified) {
                return null;
            }

            // Parse the license data (JSON format)
            const dataString = Buffer.from(licenseData, 'base64').toString('utf8');
            console.log('Decoded license data:', dataString);
            
            const data = JSON.parse(dataString);
            
            // Check expiration date
            const expirationDate = new Date(data.expiresAt);
            if (expirationDate < new Date()) {
                console.log('License expired');
                return null;
            }

            // Create and return the license info
            return {
                id: data.id,
                key: licenseKey,
                createdAt: new Date(data.createdAt),
                expiresAt: expirationDate,
                contentPermissions: data.contentPermissions || ['all_chapters']
            };
        } catch (error) {
            console.error('Error verifying license:', error);
            return null;
        }
    }

    /**
     * Load saved licenses from storage
     */
    private loadLicenses(): void {
        try {
            const licenses = this.context.globalState.get<LicenseInfo[]>('validLicenses', []);
            licenses.forEach(license => {
                this.validLicenses.set(license.id, license);
            });
        } catch (error) {
            console.error('Error loading licenses:', error);
        }
    }

    /**
     * Save licenses to storage
     */
    private saveLicenses(): void {
        try {
            const licenses = Array.from(this.validLicenses.values());
            this.context.globalState.update('validLicenses', licenses);
        } catch (error) {
            console.error('Error saving licenses:', error);
        }
    }
}

/**
 * Interface for license information
 */
export interface LicenseInfo {
    id: string;
    key: string;
    createdAt: Date;
    expiresAt: Date;
    contentPermissions: string[];
    gitee?: {
        accessToken: string;
        contentRepo: string;
        trackingRepo: string;
        branch: string;
    };
    limits?: {
        maxDownloads: number;
    };
}
