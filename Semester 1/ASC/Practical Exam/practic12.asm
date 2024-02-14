bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fprintf,gets,fopen              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import gets msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll                         ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode db "w",0
    file_name db "output.txt",0
    format_string db "%s",0
    file_desc dd 0
    sir times 50 db 0
    cuvant times 50 db 0
    sec_letter db 0
    penul_letter db 0
    ult_letter db 0
    pozitie db 0

; our code starts here
segment code use32 class=code
    start:
        ; mi a picat sa citesc cuvinte separate de * si sa afisez pe cele care au a doua litera egala cu penultima, de ex marian
        push dword sir
        call [gets]
        add esp, 4
        
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax,0
        je the_end
        mov dword [file_desc], eax
        
        mov esi,sir
        mov edi, cuvant
        mov ebx, 0
        repeta:
        
            mov bl, byte [esi]
            mov byte [penul_letter], bl
            
            inc byte [pozitie]
            
            lodsb
            mov byte [ult_letter],al
            
            cmp al, 0
            je the_end
            
            cmp byte [esi], '*'
            je comparare
            
            stosb
            
            cmp byte [pozitie], 2
            je actualizare_second
            
            actualizare_second:
            mov byte [sec_letter], al 
            jmp repeta
            
            
            comparare:
            mov bl, byte [sec_letter]
            cmp byte [penul_letter],bl
            je afisare
            mov byte [sec_letter], 0
            mov byte [penul_letter], 0
            jmp repeta
            
            afisare:
            push dword cuvant
            push dword format_string
            push dword [file_desc]
            add esp, 4*3
            jmp repeta
            
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
