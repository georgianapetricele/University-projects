bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fprintf,fopen               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll 

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    numar dd 0
    format_dec db "%d",0
    file_name db "practic5.txt",0
    access_mode db "a+",0
    spatiu dd ' '
    format_char db "%c",0
    file_desc dd 0
    nr_biti db 0

; our code starts here
segment code use32 class=code
    start:
        ; Read natural numbers until you reach 0. Write in a file numbers separated by space that are negative and have an odd number of bits set to 1
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc], eax
        
        repeta:
            ;citire
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 4*2
            
            cmp dword [numar], 0
            je the_end
            jl negative
            jg move_on
            
            mov ebx, 0
            mov ebx, dword [numar]
            negative:
                cmp ebx, 0
                je verifica
                shr ebx,1
                jc aduna
                jnc negative
                aduna:
                    inc byte [nr_biti]
                    jmp negative
            
            verifica:
                mov eax, 0
                mov al, [nr_biti]
                mov ebx, 0
                mov bl, 2
                div bl
                cmp ah, 1
                je afisare
                jne move_on
                
            afisare:
                push dword [numar]
                push dword format_dec
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                push dword [spatiu]
                push dword format_char
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                jmp repeta
                
            move_on:
            jmp repeta
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
