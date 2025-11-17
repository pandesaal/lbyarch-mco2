section .data
    vector1 db 1, 2, 3, 4       ; First vector
    vector2 db 5, 6, 7, 8       ; Second vector
    sdot dd 0.0

section .text
default rel
bits 64

global sdotComp

sdotComp:
    ;write your code here
    
    sub rsp, 8*5
    xor r8, r8 ; r8 as counter
    movss xmm5, [sdot] ; zmm4 = 0.0s

comp:
    cmp r8, rcx
    jz compEnd
    
    xor r9, r9
    xor r10, r10
    mov r9b, byte[vector1+r8] ;expand to 64bit
    mov r10b, byte[vector2+r8] ;expand to 64bit
    imul r9, r10
    cvtsi2ss xmm4, r9
    addss xmm5, xmm4
    
    inc r8
    jmp comp
    
compEnd:
    movss [sdot], xmm5
    movss xmm0, [sdot]
    
    add rsp, 8*5
    
    xor rax, rax
    ret
