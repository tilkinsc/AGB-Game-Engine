@echo off
TITLE Compiling and Making ELF...

setlocal
	
	echo Deleting test stuff...
	
	cd test
	
		del /Q bin\*.elf
		del /Q bin\*.gba
		
		rmdir /S /Q include\gbage
		del /Q lib\libgbage.a
		
	cd ..
	
	goto end
	
endlocal

:end
	echo Done.
