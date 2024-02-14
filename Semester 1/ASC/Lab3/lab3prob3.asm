bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ; a,b,c-byte; e-doubleword; x-qword
    a DB 6
    b DB 5
    c DB 2
    e DD 5
    x DQ 10
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 22. a/2 + b*b - a*b*c + e+x -unsigned
        mov al, [a]
        mov ah,0
        mov bl, 2
        div bl
        mov bx,ax     ;bx=3
        mov al, [b]     
        mov ah,0        
        mul byte [b]        ;ax=19h
        add ax,bx        ;ax=3+19=1C
        mov ebx, 0         ;ecx:ebx clear
        mov bx,ax       ;bx=1C
        mov al, [a]     
        mov ah,0     ;ax=6
        mul byte [b]  ;ax=a*b
        mul byte [c]       ;ax=6*5*2= 3C
        sub bx, ax    ;bx=1C - 3C = -20
        mov ax, 0
        mov eax, [e]
        mov edx,0
        clc
        add eax, [x+0]
        adc edx, [x+4]   ;edx:eax= 5+A=F
        mov ecx, 0
        clc
        add ebx,eax  ;ecx:ebx=-20-F -FFFD
        adc ecx,edx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
