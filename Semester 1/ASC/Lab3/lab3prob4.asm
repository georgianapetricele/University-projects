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
        ; 22. a/2 + b*b - a*b*c + e+x - signed
        mov al, [a]
        cbw
        mov bl, 2
        idiv bl  ; ah=1 al=5
        mov bx,ax     ;bx=3
        mov ax, 0
        mov al, [b]     
        cbw         
        imul byte [b]        ;ax=19
        add ax,bx       ;ax=1C
        mov bx,ax       ;bx=1C
        mov ax, 0
        mov al, [a]     
        cbw        ;ax=B
        imul byte [b]  ;convert inainte  
        imul byte [c]       ;ax=3C
        sub bx, ax
        push bx        ;bx=1C - 3C = -32 FFE0
        mov ebx, [e]
        mov ecx,0
        clc
        add ebx, [x+0]
        adc ecx, [x+4]   ;FF78
        pop ax
        cwd
        cdq
        clc
        add eax,ebx  ;ecx:ebx=-32+F =FFEF
        adc edx,ecx
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
