bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fscanf,fopen,fprintf,printf,fclose               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll 
import fscanf msvcrt.dll 
import printf msvcrt.dll 
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll                            ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode db "r",0
    space db 0
    caract db 0
    caract1 dd 0
    number dd 0
    file_desc dd 0
    is_found db 0
    ultim db 0
    nr_aparitii db 0
    format_string db "%s",0
    format_char db "%c",0
    format_dec db "%d",0
    format_afisare_1 db "Numarul de aparitii al caracterului %c",0
    format_afisare_12 db " urmat de spatiu este egal cu numarul %d citit",0
    format_afisare_22 db " urmat de spatiu nu este egal cu numarul %d citit",0
    file_name times 20 db 0
    cuvant times 20 db 0
    

; our code starts here
segment code use32 class=code
    ;Se citeste de la tastatura un nume de fisier, un caracter c si un numar n. Sa se determine daca numarul de aparitii ale caracterului c, urmat de un spatiu, in textul fisierului este egal cu numarul n, afisandu-se la consola un mesaj corespunzator (formatati textul ca si in exemplu)./
    
    start:
        push dword file_name
        push dword format_string
        call [scanf]
        add esp,4*2
        
        push dword space
        push dword format_char
        call [scanf]
        add esp,4*2
        
        push dword caract
        push dword format_char
        call [scanf]
        add esp,4*2
        
        push dword space
        push dword format_char
        call [scanf]
        add esp,4*2
        
        push dword number
        push dword format_dec
        call [scanf]
        add esp,4*2
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc],eax
        

        repeta:
            mov byte [is_found],0
            push dword cuvant
            push dword format_string
            push dword [file_desc]
            call [fscanf]
            add esp,4*3
            cmp eax, -1
            je afisare
            
            mov esi, cuvant
            repeta2:
                cmp byte [esi], 0
                je end_repeta2
                lodsb
                mov byte [ultim], al
                cmp al, byte [caract]
                je actualizare
              
                actualizare:
                mov byte [is_found], 1
                jmp repeta2
            
            end_repeta2:
            mov ebx, 0
            mov bl, byte [caract]
            cmp byte [ultim], bl
            je increase
            jmp repeta
            
            increase:
                inc byte [nr_aparitii]
            jmp repeta

        afisare:
        mov ebx, 0
        mov bl, byte [nr_aparitii]
        cmp ebx, dword [number]
        je is_equal
            mov ebx, 0
            mov bl, byte [caract]
            mov dword [caract1], ebx
            
            push dword [caract1]
            push dword format_afisare_1
            call [printf]
            add esp, 4*2
            
            push dword [number]
            push dword format_afisare_22
            call [printf]
            add esp, 4*2
            jmp the_end
            
        is_equal:
            mov ebx, 0
            mov bl, byte [caract]
            mov dword [caract1], ebx
            
            push dword [caract1]
            push dword format_afisare_1
            call [printf]
            add esp, 4*2
            
            push dword [number]
            push dword format_afisare_12
            call [printf]
            add esp, 4*2
            jmp the_end
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
