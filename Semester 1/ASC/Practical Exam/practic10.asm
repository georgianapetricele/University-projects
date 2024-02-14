bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fscanf,printf,fopen,fclose              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode db "r",0
    format_string db "%s",0
    format_string2 db "%s ",0
    format_char db "%c",0
    file_desc dd 0
    caract db 0
    space dd 0
    position dw 0
    cuvant times 20 db 0
    file_name times 20 db 0
    is_in_word db 0

; our code starts here
segment code use32 class=code
    start:
        push dword caract
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword space
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword file_name
        push dword format_string
        call [scanf]
        add esp, 4*2
        
        ;deschid
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax,0
        je the_end
        mov dword [file_desc], eax
        
        repeta:
            
            push dword cuvant
            push dword format_string
            push dword [file_desc]
            call [fscanf]
            add esp, 4*3
            
            cmp eax, -1
            je the_end
            
            inc word [position]
            
            mov esi,cuvant
            mov byte [is_in_word],0
            repeta1:
                lodsb
                cmp al, byte [caract]
                je verif_caract
                cmp al, 0
                je repeta
            jmp repeta1
                
            verif_caract:
                mov byte [is_in_word],1
                jmp verif_pos
                
                
            verif_pos:
            
            mov ebx, 0 
            mov eax, 0
            mov ax, word [position]
            mov edx, 0
            mov bx, 2
            div bx
            cmp dx, 1
            je afisare
            jne repeta
            
            
            afisare:
            push dword cuvant
            push dword format_string2
            call [printf]
            add esp, 4*3
        
        jmp repeta
        
       
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
