bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
;(e + g) * 2 / (a * c) + (h – f) + b * 3
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 1
    b db 1
    c db 1
    d db 1
    e dw 1
    f dw 1
    g dw 1
    h dw 1
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ; (a * c)
        mov ah, [a]
        mov al, [c]
        mul ah ; ax = al * ah
        mov cx, ax ; => (a * c) e in cx
        mov bl, ah
        mov bl, al
        
        ;(e + g) * 2
        mov ax, [e]
        mov dx, [g]
        add ax, dx ; ax = e+g
        mov bx, dx
        mov dx, 2
        mul dx ; (dx)2 * ax = dx:ax
        
        ; (e + g) * 2 / (a * c)
        div cx ; dx:ax : cx = ax (c) + dx (r) => rez = ax
        mov bx, dx
        
        ; (h – f)
        mov dx, [h]
        sub dx, [f] ; => dx = h - f
        
        ;(e + g) * 2 / (a * c) + (h – f)
        add ax, dx
        mov bx, dx
        mov bx, cx
        mov cx, ax ; => rez e in cx
        
        ; b * 3
        mov ah, [b]
        mov al, 3
        mul ah ; => ax = al * ah => rez = ax
        
        ; (e + g) * 2 / (a * c) + (h – f) + b * 3
        add ax, cx ; => rezultatul e in ax
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program