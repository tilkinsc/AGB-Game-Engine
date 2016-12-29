@echo off
TITLE Compiling and Making ELF...

setlocal

call using %AGBToolchain% q

echo Compiling...

gcc -o comp.elf background/*.c bitmap/*.c map/*.c sprite/*.c *.c -lm

echo Making gba from elf...
objcopy -O binary comp.elf comp.gba

endlocal

echo Done.