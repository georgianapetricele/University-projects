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
    ;a - byte, b - word, c - double word, d - qword - Unsigned representation
    a DB 2
    b DW 3
    c DD 5h
    d DQ 10h
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 22. (d+c) - (c+b) - (b+a)
        mov ebx, dword [d+0]   ;1111  edx:eax
        mov ecx, dword [d+4]
        mov eax, [c] 
        mov edx, 0   ;eax ->edx:eax
        clc
        add ebx, eax
        adc ecx, edx 
        mov eax, 0    ;eax=A0    ;ebx=eax=106h
        mov ax, [b]                ;ax=5                     
        add eax, [c]
        mov edx, 0 
        clc            ;eax=5+73=78h
        sub ebx,eax  
        sbb ecx, edx  ;ebx=A0 - 55= 4B
        mov eax, 0
        mov al, [a]
        mov ah, 0
        add ax, [b]
        mov edx, 0    
        clc             ; ax=5+5=Ah
        sub ebx, eax
        sbb ecx, edx    ;ebx=8E-A=84
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
