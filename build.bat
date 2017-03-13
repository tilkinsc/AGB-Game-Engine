@echo off
TITLE Compiling and Making ELF...

set ERRORLEVEL=0

setlocal
	
	call using %AGBToolchain% q
	
	echo Compiling test...
	cd res
		gcc -O -Wall -c background/*.c
		gcc -O -Wall -c bitmap/*.c
		gcc -O -Wall -c font/*.c
		gcc -O -Wall -c map/*.c
		gcc -O -Wall -c sprite/*.c
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	echo Compiling library source...
	cd src
		gcc -O -Wall -c *.c
		gcc -O -Wall -c gfx/*.c
		
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	if %ERRORLEVEL% GTR 0 goto crash
	
	echo Linking, generating executable elf, gba
	cd obj
		gcc -O -Wall -o comp.elf *.o
		
		if %ERRORLEVEL% GTR 0 goto crash
		echo ELF generated.
		
		
		objcopy -O binary comp.elf comp.gba
		
		if %ERRORLEVEL% GTR 0 goto crash
		echo GBA generated.
		
		move comp.elf ../bin
		move comp.gba ../bin
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

