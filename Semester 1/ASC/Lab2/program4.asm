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
    ;a,b,c-byte, d-word
    a DB 5
    d DW 11
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 22. 300-[5*(d-2*a)-1]
        mov ax, 0
        mov bx, 0
        mov bx, 12Ch ;bx=300
        mov ax, 2h
        mov cx, 0
        mov cl, [a]
        mul cl     ;ax=10
        mov cx, 0
        mov cx, [d]
        sub cx,ax    ;cx=11-10=1
        mov ax, 0
        mov ax, 5h  ;ax=5
        cwd
        mul cx       ;ax=5*1=5 
        sub ax, 1h   ;ax=4
        sub bx, ax    ;bx=128h
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
