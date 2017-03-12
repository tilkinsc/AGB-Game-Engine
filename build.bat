@echo off
TITLE Compiling and Making ELF...

set %ERRORLEVEL%=0

setlocal
	
	call using %AGBToolchain% q

	echo Compiling...
	cd src
		gcc -c *.c
		gcc -c background/*.c
		gcc -c bitmap/*.c
		gcc -c font/*.c
		gcc -c gfx/*.c
		gcc -c map/*.c
		gcc -c sprite/*.c
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	if %ERRORLEVEL% GTR 0 goto crash
	
	echo Linking, generating executable elf, gba
	cd obj
		gcc -o comp.elf *.o -lm
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		objcopy -O binary comp.elf ../bin/comp.gba
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move comp.elf ../bin
	cd ..
	
	if %ERRORLEVEL% GTR 0 goto crash 
	
endlocal

:crash
	endlocal
	set ERRORLEVEL=1
	echo Failed.

echo Done.