@echo off
TITLE Compiling and Making ELF...

set ERRORLEVEL=0

setlocal
	
	call using %AGBToolchain% q
	
	echo Compiling test...
	cd res
		gcc -c background/*.c
		gcc -c bitmap/*.c
		gcc -c font/*.c
		gcc -c map/*.c
		gcc -c sprite/*.c
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	echo Compiling library source...
	cd src
		gcc -c *.c
		gcc -c gfx/*.c
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	if %ERRORLEVEL% GTR 0 goto crash
	
	echo Linking, generating executable elf, gba
	cd obj
		gcc -o comp.elf *.o
		
		if %ERRORLEVEL% GTR 0 goto crash
		echo ELF generated.
		
		
		objcopy -O binary comp.elf comp.gba
		
		if %ERRORLEVEL% GTR 0 goto crash
		echo GBA generated.
		
		echo %ERRORLEVEL%
		move comp.elf ../bin
		move comp.gba ../bin
		echo %ERRORLEVEL%
	cd ..
	
	if %ERRORLEVEL% GTR 0 goto crash 
	goto end
	
endlocal

:crash
	endlocal
	set ERRORLEVEL=1
	echo Failed.

:end
	echo Done.

