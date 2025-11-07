@echo off
echo Renumbering specifications from 001 onwards...

REM Create temporary directory for renaming
mkdir .specify\specs\temp_renumber 2>nul

REM Move directories to temporary location with new names
move .specify\specs\011-generic-learning-buddy .specify\specs\temp_renumber\001-generic-learning-buddy
move .specify\specs\012-multi-course-support .specify\specs\temp_renumber\002-multi-course-support
move .specify\specs\014-course-content-provider .specify\specs\temp_renumber\003-course-content-provider
move .specify\specs\014a-course-catalog-management .specify\specs\temp_renumber\004-course-catalog-management
move .specify\specs\014b-content-downloading .specify\specs\temp_renumber\005-content-downloading
move .specify\specs\014c-license-management .specify\specs\temp_renumber\006-license-management
move .specify\specs\014d-anti-bulk-copying .specify\specs\temp_renumber\007-anti-bulk-copying
move .specify\specs\015-course-structure-tool .specify\specs\temp_renumber\008-course-structure-tool
move .specify\specs\016-course-learning-buddy .specify\specs\temp_renumber\009-course-learning-buddy
move .specify\specs\021-course-structure-navigation .specify\specs\temp_renumber\010-course-structure-navigation
move .specify\specs\022-progress-tracking .specify\specs\temp_renumber\011-progress-tracking
move .specify\specs\023-license-management .specify\specs\temp_renumber\012-license-management
move .specify\specs\024-wechat-integration .specify\specs\temp_renumber\013-wechat-integration
move .specify\specs\025-development-tools .specify\specs\temp_renumber\014-development-tools
move .specify\specs\026-wechat-pay-integration .specify\specs\temp_renumber\015-wechat-pay-integration

REM Move everything back to the original location
move .specify\specs\temp_renumber\* .specify\specs\

REM Remove temporary directory
rmdir .specify\specs\temp_renumber

echo Specifications have been renumbered from 001 onwards.
pause