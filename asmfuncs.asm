
section .data
    sdot dd 0.0
    init dd 0.0

section .text
default rel
bits 64

global sdotComp

sdotComp:
    ;write your code here
    ; rcx = arr1, rdx = arr2, r8 = size
    
    sub rsp, 8*5
    xor r11, r11 ; r11 as counter
    movss xmm5, [init] ; zmm5 = 0.0s

comp:
    cmp r11, r8
    jz compEnd
    
    movss xmm6, [sdot]
    movss xmm7, [sdot]
    movss xmm6, dword[rcx+r11*4]
    movss xmm7, dword[rdx+r11*4]
    mulss xmm6, xmm7
    addss xmm5, xmm6
    
    movss [sdot], xmm5
    movss xmm5, [init] ; zmm5 = 0.0s
    movss xmm5, [sdot]
    
    inc r11
    jmp comp
    
compEnd:
    movss xmm0, [sdot]
    
    add rsp, 8*5
    
    xor rax, rax
    ret
