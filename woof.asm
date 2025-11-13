section .data
    msg db "bark: %d, %d, %d, %d, %d", 0

section .text

default rel
bits 64


global main

extern printf




main:
    ;write your code here
    sub rsp, 8*7
    lea rcx, [msg]
    mov rdx, 69
    mov r8, 420
    mov r9, 1
    mov qword[rsp+32], 2
    mov qword[rsp+40], 3
    
    
    call printf
    
    add rsp, 8*7
    
    
    
    
    
    
    xor rax, rax
    ret