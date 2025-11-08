#!/bin/bash

# This script renumbers the specifications from 001 onwards
# Current mapping:
# 010-podman-environment -> 001-podman-environment
# 011-generic-learning-buddy -> 002-generic-learning-buddy
# 012-multi-course-support -> 003-multi-course-support
# 013-course-podmanfile-support -> 004-course-podmanfile-support
# 014-course-content-provider -> 005-course-content-provider
# 014a-course-catalog-management -> 006-course-catalog-management
# 014b-content-downloading -> 007-content-downloading
# 014c-license-management -> 008-license-management
# 014d-anti-bulk-copying -> 009-anti-bulk-copying
# 015-course-structure-tool -> 010-course-structure-tool
# 016-course-learning-buddy -> 011-course-learning-buddy
# 021-course-structure-navigation -> 012-course-structure-navigation
# 022-progress-tracking -> 013-progress-tracking
# 023-license-management -> 014-license-management
# 024-wechat-integration -> 015-wechat-integration
# 025-development-tools -> 016-development-tools
# 026-wechat-pay-integration -> 017-wechat-pay-integration

echo "Renumbering specifications from 001 onwards..."

# Create temporary directory for renaming
mkdir -p .specify/specs/temp_renumber

# Move directories to temporary location with new sequential names
mv .specify/specs/010-podman-environment .specify/specs/temp_renumber/001-podman-environment
mv .specify/specs/011-generic-learning-buddy .specify/specs/temp_renumber/002-generic-learning-buddy
mv .specify/specs/012-multi-course-support .specify/specs/temp_renumber/003-multi-course-support
mv .specify/specs/013-course-podmanfile-support .specify/specs/temp_renumber/004-course-podmanfile-support
mv .specify/specs/014-course-content-provider .specify/specs/temp_renumber/005-course-content-provider
mv .specify/specs/014a-course-catalog-management .specify/specs/temp_renumber/006-course-catalog-management
mv .specify/specs/014b-content-downloading .specify/specs/temp_renumber/007-content-downloading
mv .specify/specs/014c-license-management .specify/specs/temp_renumber/008-license-management
mv .specify/specs/014d-anti-bulk-copying .specify/specs/temp_renumber/009-anti-bulk-copying
mv .specify/specs/015-course-structure-tool .specify/specs/temp_renumber/010-course-structure-tool
mv .specify/specs/016-course-learning-buddy .specify/specs/temp_renumber/011-course-learning-buddy
mv .specify/specs/021-course-structure-navigation .specify/specs/temp_renumber/012-course-structure-navigation
mv .specify/specs/022-progress-tracking .specify/specs/temp_renumber/013-progress-tracking
mv .specify/specs/023-license-management .specify/specs/temp_renumber/014-license-management
mv .specify/specs/024-wechat-integration .specify/specs/temp_renumber/015-wechat-integration
mv .specify/specs/025-development-tools .specify/specs/temp_renumber/016-development-tools
mv .specify/specs/026-wechat-pay-integration .specify/specs/temp_renumber/017-wechat-pay-integration

# Move everything back to the original location
mv .specify/specs/temp_renumber/* .specify/specs/

# Remove temporary directory
rmdir .specify/specs/temp_renumber

echo "Specifications have been renumbered from 001 onwards."