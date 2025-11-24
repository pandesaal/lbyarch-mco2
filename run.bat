nasm -f win64 asmfuncs.asm
gcc -c main.c -o main.obj -m64
gcc main.obj asmfuncs.obj -o proj.exe -m64
proj.exe
