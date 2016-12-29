@echo off
TITLE Running GBA test emulator...

setlocal

set name=comp.elf

call using %AGBToolchain% q

echo Running...

agbvba %name%

endlocal

echo Done.