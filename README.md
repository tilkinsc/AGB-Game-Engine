# AGB-Game-Engine
A simple game engine for a simple device, built only with compilers from devkitadv.
No libraries from devkitadv is used.

Trying to avoid standard libraries and the like. The reason goes back to 'what can I not clutter the program with'.
If you want to use a standard library by all means do it. However, it is unnecessary in this low-level library.

This includes a build batch file and a test module to work with my environment. You can build in your own environment by
* Compiling to objects
* Linking objects
* Outputting your elf, gba
