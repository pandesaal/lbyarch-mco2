section .data
    num dd 3.0
    sdot dd 0.0

section .text
default rel
bits 64

global sdotComp

sdotComp:
    ;write your code here
    sub rsp, 8*5
    cvtsi2ss xmm1, ecx
    addss xmm1, [num]
    movss [sdot], xmm1
    lea rax, [sdot]
    
    add rsp, 8*5
    
    xor rax, rax
    ret
