nasm -f win64 asmfuncs.asm
gcc -c cprog.c -o cprog.obj -m64
gcc cprog.obj asmfuncs.obj -o proj.exe -m64
proj.exe
