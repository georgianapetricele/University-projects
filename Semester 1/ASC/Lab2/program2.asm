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
    ;a,b,c,d byte
    a DB 3
    b DB 3
    c DB 3
    d DB 4
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 22. (a+b+b)-(c+d)
        mov ax, 0
        mov al, [a]
        add al, [b]
        add al, [b]
        mov bx, 0
        mov bl, [c]
        add bl, [d]
        sub al, bl
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
