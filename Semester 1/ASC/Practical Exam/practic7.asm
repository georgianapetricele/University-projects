bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf,fscanf,fopen              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fopen msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll 
import scanf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    file_desc dd 0
    format_string db "%s",0
    access_mode db "r",0
    file_name db "practic7.txt",0
    sir1 times 50 db -1
    sir2 times 50 db -1
    
    

; our code starts here
segment code use32 class=code
    start:
        ; 3. Se citeste o propozitie din fisier. Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc],eax
        
        repeta:
            push dword sir1
            push dword format_string
            push dword [file_desc]
            call [fscanf]
            add esp, 4*3
            cmp eax, -1
            je the_end
            
            
            mov esi, sir1
            mov edi, sir2
            repeta2:
                cld
                lodsb 
                cmp eax,-1
                je move_on
                std
                stosb
            jmp repeta2
            
            move_on:
            push dword sir2
            push dword format_string
            call [printf]
            add esp, 4*2
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
