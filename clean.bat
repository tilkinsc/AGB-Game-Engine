@echo off
TITLE Compiling and Making ELF...

setlocal
	
	echo Deleting possible extra objects
	
	del /Q src\*.o
	del /Q src\gfx\*.o
	del /Q src\res\background\*.o
	del /Q src\res\bitmap\*.o
	del /Q src\res\sprite\*.o
	del /Q src\res\font\*.o
	del /Q src\res\map\*.o
	del /Q src\res\sprite\*.o
	
	echo Deleting trash test compilation objects
	
	del /Q obj\*.o
	
	if [%1] EQU [t] (
	
		echo Deleting trash test binaries
		
		del /Q bin\*.elf
		del /Q bin\*.gba
	
	)
	
endlocal

echo Done.