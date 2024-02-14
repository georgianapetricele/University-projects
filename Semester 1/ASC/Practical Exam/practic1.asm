bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fprintf,scanf,fopen,gets               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fprintf msvcrt.dll 
import gets msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll      ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db "caractere.txt",0
    file_desc dd 0
    mode_afis db "w", 0
    string_type db "%s",0
    caract_type db "%c", 0
    decimal_type db "%d", 0
    caract dd 0
    len equ 100
    sir times len db 0
; our code starts here
segment code use32 class=code
    start:
        ; From keyboard is given a string until character $. Print in caractere.txt cuvintele inlocuind literele mici cu codul lor ascii
        ;deschidere fisier
        push dword mode_afis
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov dword [file_desc], eax
        cmp eax, 0
        je the_end
        
            ;citire sir
            push dword sir
            call [gets]
            add esp, 4*1
            cmp eax, 0
            je the_end
            
            mov esi, 0
            mov ebx, 0
            repeat1:
                cmp byte [sir+esi], '$'
                je the_end
                cmp byte [sir+esi], 'a'
                jae litera_mica
                jb move_on
                
                litera_mica:
                cmp byte [sir+esi], 'z'
                jbe modifica
                ja move_on
                
                modifica:
                mov bl, byte [sir+esi]
                push ebx
                push dword decimal_type
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                inc esi
                jmp repeat1
                
                move_on:
                mov bl, [sir+esi]
                mov [caract], bl
                push dword [caract]
                push dword caract_type
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                inc esi
                jmp repeat1
                
  
            
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
