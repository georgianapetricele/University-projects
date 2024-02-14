bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fscanf,fprintf,fclose,fopen               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll 
import fopen msvcrt.dll  
import fscanf msvcrt.dll                        ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode2 db "w",0
    access_mode1 db "r",0
    format_string db "%s",0
    format_char db "%c",0
    format_dec db "%d",0
    file_desc1 dd 0
    file_desc2 dd 0
    file_name db "input.txt",0
    file_name2 db "output.txt",0
    caract db 0
    number dd 0
    sir times 20 db 0
    sir_final times 20 db 0

; our code starts here
segment code use32 class=code
    start:
        ;citesc caractere pana la ! si afiseaza primele n consoane
        mov esi,0
        mov ebx,0
        repeta:
            push dword caract
            push dword format_char
            call [scanf]
            add esp, 4*2
            
            cmp byte [caract], '!'
            je end_repeta
            
            mov bl, byte [caract]
            mov byte [sir+esi], bl
            inc esi
            jmp repeta
        end_repeta:
        ;citesc din fisier n
        push dword access_mode1
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax,0
        je the_end
        mov dword [file_desc1],eax
        
        push dword number
        push dword format_dec
        push dword [file_desc1]
        call [fscanf]
        add esp, 4*3
        
        push dword access_mode2
        push dword file_name2
        call [fopen]
        add esp, 4*2
        cmp eax,0
        je the_end
        mov dword [file_desc2],eax
        
        mov esi, sir
        mov edi, sir_final
        mov ecx, dword [number] 
        repeta1:
            lodsb 
            cmp al, 'a'
            je move_on
            jne verif_e
            
            verif_e:
            cmp al, 'e'
            je move_on
            jne verif_i
            
             verif_i:
            cmp al, 'i'
            je move_on
            jne verif_o
            
              verif_o:
            cmp al, 'o'
            je move_on
            jne verif_u
            
             verif_u:
            cmp al, 'e'
            je move_on
            jne atribuire
            
            atribuire:
            stosb
            move_on:
        loop repeta1
        
        push dword sir_final
        push dword format_string
        push dword [file_desc2]
        call [fprintf]
        add esp, 4*3
        
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
