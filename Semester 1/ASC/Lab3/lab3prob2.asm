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
    ;a - byte, b - word, c - double word, d - qword - Signed representation
    a DB 20
    b DW 10
    c DD 20
    d DQ 5
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 22. c+b-(a-d+b)
        mov ax, [b]
        cwde
        add eax, [c]    ;eax=30=1Eh
        mov ebx, eax
        push ebx ;ebx=1E
        mov eax, 0
        mov al, [a]
        cbw
        cwde
        cdq  
        clc           ;eax=14h
        sub eax, dword [d]
        sbb edx, dword [d+4] 
        mov ebx, eax
        mov ecx, edx   ;14h-5h= Fh ;ecx=Fh
        mov eax, 0
        mov ax, [b]    
        cwde
        cdq 
        clc
        add ebx, eax  ; ecx: ebx= a-d+b
        adc ecx, edx
        pop eax  ;rezultatul de la c+b
        cdq
        clc
        sub eax,ebx
        sbb edx, ecx  ; edx:eax= c+b - (a-d+b) 
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
