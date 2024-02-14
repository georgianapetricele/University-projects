bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fscanf,printf,fopen
import exit msvcrt.dll              ; tell nasm that exit exists even if we won't be defining it
import fscanf msvcrt.dll 
import printf msvcrt.dll 
import fopen msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    format_hexa db "%x",0
    format_dec db "%d%c",10,13,0
    spatiu dd ' '
    format_char db "%c",0
    numar dd 0
    access_mode db "r", 0
    file_name db "practic6.txt", 0
    file_desc dd 0
    max_digit dw 0
    max_digit2 dw 0

; our code starts here
segment code use32 class=code
    start:
        ; 1. Se dă un șir de 10 numere în baza 16 în fișierul input.txt. 
        ; Să se determine cifra minimă din fiecare număr.
        ; Să se afișeze acest șir al cifrelor minime, în baza 10, pe ecran.
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc], eax
        
        mov ecx, 0
        mov ecx, 10
        repeta:
            mov ebx,0
            pushad
            push dword numar
            push dword format_hexa
            push dword [file_desc]
            call [fscanf]
            add esp, 4*3
            popad
            
            mov ebx, 0
            mov word [max_digit], bx
            mov bl, 10h
            mov eax, 0
            mov edx, 0
            mov eax, dword [numar]
            repeta2:
                div bx
                cmp dx, 0
                je move_on
                cmp dx, word [max_digit]
                jae maxim
                jmp repeta2
                maxim:
                mov word [max_digit], dx
                mov dword [max_digit2], edx
                jmp repeta2
                
            
            move_on:
            pushad
            push dword [spatiu]
            push dword [max_digit2]
            push dword format_dec
            call [printf]
            add esp, 4*3
            popad
            
            
        loop repeta
            
            

        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
