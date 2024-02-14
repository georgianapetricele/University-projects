bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fscanf,fprintf,fopen,fclose             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode1 db "r",0
    access_mode2 db "w",0
    file_desc1 dd 0
    file_desc2 dd 0
    file_name1 db "input.txt",0
    file_name2 db "output.txt",0
    format_string db "%s",0
    format_string2 db "%s ",0
    format_char db "%c",0
    format_dec db "%d",0
    caracter_spec dd 0
    space dd 0
    number dd 0
    cuvant times 50 db 0
    cuvant_nou times 50 db 0

; our code starts here
segment code use32 class=code
    start:
        ;citesc file spec de
        push dword file_name1
        push dword format_string
        call [scanf]
        add esp, 4*2
        
        push dword space
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword caracter_spec
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword space
        push dword format_char
        call [scanf]
        add esp, 4*2
        
        push dword number
        push dword format_dec
        call [scanf]
        add esp, 4*2
        
        ;deschid
        push dword access_mode1
        push dword file_name1
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc1],eax
        
        push dword access_mode2
        push dword file_name2
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc2],eax
        
        repeta:
            push dword cuvant
            push dword format_string
            push dword [file_desc1]
            call [fscanf]
            add esp, 4*3
            
            cmp eax, 0FFFFFFFFh
            je the_end
            
            mov esi, cuvant
            mov edi, cuvant_nou
            mov ebx, dword [number]
            repeta2:
                lodsb 
                cmp dword [number],0
                je move_on
                cmp al,0
                je complete_with_spec
                stosb
                dec dword [number]
                jmp repeta2
            
                
            
            complete_with_spec:
                push dword cuvant_nou
                push dword format_string
                push dword [file_desc2]
                call [fprintf]
                add esp, 4*3
                
                
                repeta3:
                    cmp dword [number], 0
                    je actualizare
                    dec dword [number]
                    push dword [caracter_spec]
                    push dword format_char
                    push dword [file_desc2]
                    call [fprintf]
                    add esp, 4*3
                    
                jmp repeta3
                
                
            move_on:
            push dword cuvant_nou
            push dword format_string
            push dword [file_desc2]
            call [fprintf]
            add esp, 4*3
        
        actualizare:
        push dword [space]
        push dword format_char
        push dword [file_desc2]
        call [fprintf]
        add esp, 4*3
        mov dword [number], ebx
        jmp repeta
            
            
        the_end:
        push dword [file_desc2]
        call [fclose]
        add esp, 4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
