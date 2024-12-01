section .text
bits 64
default rel
global asmVectorDistance
extern printf

asmVectorDistance:
    ; rcx has n
    ; rdx has x1
    ; r8 has x2
    ; r9 has y1
    mov r10, [rsp + 48] ;get the parameter for y2
    mov r11, [rsp + 40] ;get the parameter for z
    
    calculate:
        movsd xmm0, [rdx]
        movsd xmm1, [r8]
        movsd xmm2, [r9]
        movsd xmm3, [r10]
        
        subsd xmm1, xmm0 ;(x2-x1)
        subsd xmm3, xmm2 ;(y2-y1)
        
        mulsd xmm1, xmm1 ;(x2-x1)^2 
        mulsd xmm3, xmm3 ;(y2-y1)^2
        
        addsd xmm1, xmm3 ; (x2-x1)^2 + (y2-y1)^2
        
        sqrtsd xmm1, xmm1 ; square root
        
        movsd [r11], xmm1 ; move the answer into z
        
        ;move the pointers to the next elements in the array
        add rdx, 8
        add r8, 8
        add r9, 8
        add r10, 8
        add r11, 8
        
        dec rcx ;decrement counter n
        jnz calculate
    
    
    xor rax, rax
    ret