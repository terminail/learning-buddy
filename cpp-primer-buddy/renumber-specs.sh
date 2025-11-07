#!/bin/bash

# This script renumbers the specifications from 001 onwards
# Current mapping:
# 001 -> 011-generic-learning-buddy
# 002 -> 012-multi-course-support
# 003 -> 014-course-content-provider
# 004 -> 014a-course-catalog-management
# 005 -> 014b-content-downloading
# 006 -> 014c-license-management
# 007 -> 014d-anti-bulk-copying
# 008 -> 015-course-structure-tool
# 009 -> 016-course-learning-buddy
# 010 -> 021-course-structure-navigation
# 011 -> 022-progress-tracking
# 012 -> 023-license-management
# 013 -> 024-wechat-integration
# 014 -> 025-development-tools
# 015 -> 026-wechat-pay-integration

echo "Renumbering specifications from 001 onwards..."

# Create temporary directory for renaming
mkdir -p .specify/specs/temp_renumber

# Move directories to temporary location with new names
mv .specify/specs/011-generic-learning-buddy .specify/specs/temp_renumber/001-generic-learning-buddy
mv .specify/specs/012-multi-course-support .specify/specs/temp_renumber/002-multi-course-support
mv .specify/specs/014-course-content-provider .specify/specs/temp_renumber/003-course-content-provider
mv .specify/specs/014a-course-catalog-management .specify/specs/temp_renumber/004-course-catalog-management
mv .specify/specs/014b-content-downloading .specify/specs/temp_renumber/005-content-downloading
mv .specify/specs/014c-license-management .specify/specs/temp_renumber/006-license-management
mv .specify/specs/014d-anti-bulk-copying .specify/specs/temp_renumber/007-anti-bulk-copying
mv .specify/specs/015-course-structure-tool .specify/specs/temp_renumber/008-course-structure-tool
mv .specify/specs/016-course-learning-buddy .specify/specs/temp_renumber/009-course-learning-buddy
mv .specify/specs/021-course-structure-navigation .specify/specs/temp_renumber/010-course-structure-navigation
mv .specify/specs/022-progress-tracking .specify/specs/temp_renumber/011-progress-tracking
mv .specify/specs/023-license-management .specify/specs/temp_renumber/012-license-management
mv .specify/specs/024-wechat-integration .specify/specs/temp_renumber/013-wechat-integration
mv .specify/specs/025-development-tools .specify/specs/temp_renumber/014-development-tools
mv .specify/specs/026-wechat-pay-integration .specify/specs/temp_renumber/015-wechat-pay-integration

# Move everything back to the original location
mv .specify/specs/temp_renumber/* .specify/specs/

# Remove temporary directory
rmdir .specify/specs/temp_renumber

echo "Specifications have been renumbered from 001 onwards."