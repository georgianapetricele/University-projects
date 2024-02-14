bits 32 ; assembling for the 32 bits architecture

;A string containing n binary representations on 8 bits is given as a character string.
;Obtain the string containing the numbers corresponding to the given binary representations.
;Example:
;Given: '10100111b', '01100011b', '11111111b', '101011b'
;Obtain: 10100111, 01100011, 110, 101011

global start

extern exit,fopen,fprintf,fclose              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll 

extern _stringtobinary
                       

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    sir db '10100111b', '01111111b', '1111111b', '101011b'
    lensir equ $-sir
    access_mode db "w", 0
    file_name db "afiscuvant.txt", 0
    fdesc dd 0
    char_format db "%c", 0
    decimal_format db "%d", 0
    caract dd 0
    digit db 0
; our code starts here
segment code use32 class=code
    start:
        ; deschid fisierul pt afisare
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        mov [fdesc], eax
        cmp eax, 0
        je the_end
        
        ; parcurg fiecare cuvant pana la 0 si dupa cu esi pentru fiecare cuvant vad pentru fiecare caracter daca e 1 sau 0 sau b si il schimb in numar
        mov esi, 0
        mov ecx, 0
        mov ebx, 0
        mov ebx, lensir
        repeat1:
                mov ecx, 0
                mov cl, [sir+esi]
                inc esi
                call _stringtobinary
                mov dword [caract], ecx
                cmp cl, 32h
                je next_word
                push dword [caract]
                push decimal_format
                push dword [fdesc]
                call [fprintf]
                add esp, 4*3
        dec ebx
        cmp ebx, 0
        je the_end
        jne repeat1
                next_word:
                mov dword [caract], ' '
                push dword [caract]
                push char_format
                push dword [fdesc]
                call [fprintf]
                add esp, 4*3
        dec ebx
        cmp ebx, 0
        je the_end
        jne repeat1    
               
        
        the_end:
        push dword[fdesc]
        call [fclose]
        add esp, 4*1
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
