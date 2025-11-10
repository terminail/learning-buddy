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