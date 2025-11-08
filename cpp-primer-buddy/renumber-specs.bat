@echo off
echo Renumbering specifications from 001 onwards...

REM Create temporary directory for renaming
mkdir .specify\specs\temp_renumber 2>nul

REM Move directories to temporary location with new sequential names
move .specify\specs\010-podman-environment .specify\specs\temp_renumber\001-podman-environment
move .specify\specs\011-generic-learning-buddy .specify\specs\temp_renumber\002-generic-learning-buddy
move .specify\specs\012-multi-course-support .specify\specs\temp_renumber\003-multi-course-support
move .specify\specs\013-course-podmanfile-support .specify\specs\temp_renumber\004-course-podmanfile-support
move .specify\specs\014-course-content-provider .specify\specs\temp_renumber\005-course-content-provider
move .specify\specs\014a-course-catalog-management .specify\specs\temp_renumber\006-course-catalog-management
move .specify\specs\014b-content-downloading .specify\specs\temp_renumber\007-content-downloading
move .specify\specs\014c-license-management .specify\specs\temp_renumber\008-license-management
move .specify\specs\014d-anti-bulk-copying .specify\specs\temp_renumber\009-anti-bulk-copying
move .specify\specs\015-course-structure-tool .specify\specs\temp_renumber\010-course-structure-tool
move .specify\specs\016-course-learning-buddy .specify\specs\temp_renumber\011-course-learning-buddy
move .specify\specs\021-course-structure-navigation .specify\specs\temp_renumber\012-course-structure-navigation
move .specify\specs\022-progress-tracking .specify\specs\temp_renumber\013-progress-tracking
move .specify\specs\023-license-management .specify\specs\temp_renumber\014-license-management
move .specify\specs\024-wechat-integration .specify\specs\temp_renumber\015-wechat-integration
move .specify\specs\025-development-tools .specify\specs\temp_renumber\016-development-tools
move .specify\specs\026-wechat-pay-integration .specify\specs\temp_renumber\017-wechat-pay-integration

REM Move everything back to the original location
move .specify\specs\temp_renumber\* .specify\specs\

REM Remove temporary directory
rmdir .specify\specs\temp_renumber

echo Specifications have been renumbered from 001 onwards.
pause