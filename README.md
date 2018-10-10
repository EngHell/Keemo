# Keemo
GameBoy emulator written in C++ aimed to show how unit testing can improve emulator development workflow.

## Do unit testing improved the development of the emulator?
Related to my first attemp of writing an emulator https://github.com/EngHell/JS-Chip-8, i wrote it debugging each opcode step by step in a rom, and finding which opcoded where missing, then after implementing an opcode it was difficult to find if the implementation was good, by the fact that the only way to know would be to catch a bug in while running a rom, and then check the debugger step by step to see what opcode was causing it, with some opcodes it was easy to catch, but others made it hard. Then I added unit tests to the opcodes at later date that showed some extra errors in implementation and as well turned boring since the main programing was done.
Due to those facts I realized that unit tests were a really important part of writting an emulator thing that does lack important emulation projects as dolphin, or citra with are filled with regresions and usually non automated way of checking.
So while making the process a bit more lengthy unit tests are worth it.
