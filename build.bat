@echo off
TITLE Compiling and Making ELF...

set ERRORLEVEL=0

setlocal
	
	call using %AGBToolchain% q
	
	echo Compiling library source...
	cd src
		gcc -O -Wall -c *.c
		if %ERRORLEVEL% GTR 0 goto crash
		
		gcc -O -Wall -c gfx/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ../obj
	cd ..
	
	echo Creating static library...
	cd obj
		ar rcs libgbage.a *.o
		if %ERRORLEVEL% GTR 0 goto crash
		
		del /Q *.o
		move /Y *.a ..
	cd ..
	
	
	
	echo Loading library into test...
	copy /Y *.a test\lib\
	
	mkdir test\include\gbage
	mkdir test\include\gbage\gfx
	copy /Y src\*.h test\include\gbage\
	copy /Y src\gfx\*.h test\include\gbage\gfx\
	
	
	
	echo Compiling test...
	cd test
	cd res
		gcc -O -Werror -Wall -I../include/ -c ../src/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		
		gcc -O -Werror -Wall -I../include/ -c background/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		gcc -O -Werror -Wall -I../include/ -c bitmap/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		gcc -O -Werror -Wall -I../include/ -c font/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		gcc -O -Werror -Wall -I../include/ -c map/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		gcc -O -Werror -Wall -I../include/ -c sprite/*.c
		if %ERRORLEVEL% GTR 0 goto crash
		
		move /Y *.o ..\..\obj
	cd ..
	cd ..
	
	echo Linking test...
	cd obj
		gcc -static -O -Werror -Wall -I../test/include/ -L../test/lib/ -o comp.elf *.o -lgbage
		if %ERRORLEVEL% GTR 0 goto crash
		
		del /Q *.o
		
		objcopy -O binary comp.elf comp.gba
		if %ERRORLEVEL% GTR 0 goto crash
		
		move comp.elf ../test/bin
		move comp.gba ../test/bin
	cd ..
	
	goto end
	
endlocal

:crash
	endlocal
	set ERRORLEVEL=1
	echo Failed.

:end
	echo Done.

