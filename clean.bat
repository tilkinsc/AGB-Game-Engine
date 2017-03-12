@echo off
TITLE Compiling and Making ELF...

setlocal
	
	echo Deleting possible extra objects
	
	del /Q src\*.o
	del /Q src\gfx\*.o
	del /Q res\background\*.o
	del /Q res\bitmap\*.o
	del /Q res\sprite\*.o
	del /Q res\font\*.o
	del /Q res\map\*.o
	del /Q res\sprite\*.o
	
	echo Deleting trash test compilation objects
	
	del /Q obj\*.o
	
	if [%1] EQU [t] (
	
		echo Deleting trash test binaries
		
		del /Q bin\*.elf
		del /Q bin\*.gba
	
	)
	
	goto end
	
endlocal

:end
	echo Done.
