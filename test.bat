@echo off
TITLE Running GBA test emulator...

if %ERRORLEVEL% GTR 0 goto crash

setlocal

	set name=test/bin/comp.gba

	call using %AGBToolchain% q

	echo Running...

	agbvba %name%
	
	goto end
	
endlocal

:crash
	endlocal
	echo Didn't run because previous error.
	exit /b

:end
	echo Done.
