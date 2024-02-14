bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fscanf,fopen,fprintf,scanf,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import fscanf msvcrt.dll 
import scanf msvcrt.dll
import fopen msvcrt.dll 
import fprintf msvcrt.dll
import printf msvcrt.dll  ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    format_sir db "%s", 0 
    format_char db "%c", 0
    format_dec db "%d", 0
    mod_access db "r",0
    file_desc dd 0
    numar dd 0
    aux dd 0
    spatiu dd 0
    file_name times 50 dd 0
    cuvant times 50 dd 0
; our code starts here
segment code use32 class=code
    start:
        ; 21.Sa se citeasca de la tastatura un nume de fisier si un numar. 
        ;   Sa se citeasca din fisierul dat cuvintele separate prin spatii si sa se afiseze in consola cuvintele care sunt pe pozitiile multiplii de numarul citit de la tastatura.
        
        push dword file_name
        push dword format_sir
        call [scanf]
        add esp, 4*2
        
        push dword spatiu
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 4*2
       
        ;deschid
        push dword mod_access
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax,0 
        je the_end
        mov dword [file_desc], eax
        
        ;citesc cuvintele
        mov esi, 0
        repeta:
            push dword cuvant
            push dword format_sir
            push dword [file_desc]
            call [fscanf]
            add esp, 4*3
            cmp eax, 0FFFFFFFFh
            je the_end
            inc esi
            
            verificare:
                mov eax, 0
                mov ebx, 0
                mov eax, esi
                mov ebx, dword [numar]
                div bl
                cmp ah, 0
                jne move_on
            
            push dword cuvant
            push dword format_sir
            call [printf]
            add esp, 4*2
            push dword [spatiu]
            push dword format_char
            call [printf]
            add esp, 4*2
         
        move_on:
        jmp repeta
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
