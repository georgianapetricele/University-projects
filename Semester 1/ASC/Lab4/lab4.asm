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
    ;Given the word A and the byte B, compute the doubleword C:
            ;the bits 0-3 of C have the value 1
            ;the bits 4-7 of C are the same as the bits 0-3 of A
            ;the bits 8-13 of C have the value 0
            ;the bits 14-23 of C are the same as the bits 4-13 of A
            ;the bits 24-29 of C are the same as the bits 2-7 of B
            ;the bits 30-31 have the value 1
    a dw 10
    b db 10
    c dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ebx, 0
        
        ;the bits 0-3 of C have the value 1
        or ebx, 00000000000000000000000000001111b
        
        ;the bits 4-7 of C are the same as the bits 0-3 of A
        mov eax, 0
        mov ax, [a]
        and al, 00001111b
        mov cl, 4
        rol eax,cl
        or ebx, eax
        
        ;the bits 8-13 of C have the value 0
        and ebx, 11111111111111111100000011111111b
        
        ;the bits 14-23 of C are the same as the bits 4-13 of A
        mov eax, 0
        mov ax, [a]
        and eax, 00000000000000000011111111110000b
        mov cl, 10
        rol eax, cl
        or ebx, eax
        
        ;the bits 24-29 of C are the same as the bits 2-7 of B
        mov eax, 0
        mov al, [b]
        and eax, 00000000000000000000000011111100b
        mov cl, 22
        rol eax, cl
        or ebx, eax
        
        ;the bits 30-31 have the value 1
        or ebx, 11000000000000000000000000000000b
        
        mov [c],ebx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
