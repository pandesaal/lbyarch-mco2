section .data
    msg db "bark", 0

section .text

default rel
bits 64


global hewo

extern printf

hewo:
    ;write your code here
    sub rsp, 8*5
    lea rcx, [msg]
    
    
    call printf
    
    add rsp, 8*5
    
    
    
    
    
    
    xor rax, rax
    ret