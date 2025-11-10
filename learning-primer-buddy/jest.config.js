module.exports = {
    preset: 'ts-jest',
    testEnvironment: 'node',
    roots: ['<rootDir>/tests', '<rootDir>/src'],
    testMatch: ['**/*.test.ts'],
    testPathIgnorePatterns: [
        '<rootDir>/tests/integration/real/',
        '<rootDir>/node_modules/'
    ],
    moduleFileExtensions: ['ts', 'js', 'json', 'node'],
    collectCoverage: true,
    coverageDirectory: '<rootDir>/coverage',
    coverageReporters: ['text', 'lcov', 'html'],
    verbose: true,
    moduleNameMapper: {
        '^vscode$': '<rootDir>/tests/__mocks__/vscode'
    }
};