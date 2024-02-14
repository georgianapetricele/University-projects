bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fprintf,fopen,gets
import exit msvcrt.dll 
import scanf msvcrt.dll                ; tell nasm that exit exists even if we won't be defining it
import fopen msvcrt.dll 
import fprintf msvcrt.dll
import gets msvcrt.dll        ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "afisare.txt",0
    file_desc dd 0
    dec_format db "%d",0
    string_format db "%s",0
    char_format db "%c",0
    access_mode db "w",0
    caract db 0
    last_letter db 0
    count db 0
    cuvant db 0
    len equ 100
    sir times len db 0
    n db 0

; our code starts here
segment code use32 class=code
    start:
        ; 1.Sa se citeasca de la tastatura un numar n, apoi sa se citeasca mai multe cuvinte, pana cand se citeste cuvantul/caracterul "#". Sa se scrie intr-un fisier text toate cuvintele citite care incep si se termina cu aceeasi litera si au cel putin n litere.
        
        ;scanf ("%d", n)
        

        Push șir 
        Call [gets]
        Add esp, 4
        CMP eax, 0
        je the_end

        the_end
                
        push dword n
        push dword char_format
        call [scanf]
        add esp, 4*2
        mov dl, byte [n]
        
        ;citesc si spatiul dupa n
        push dword n
        push dword char_format
        call [scanf]
        add esp, 4*2
        
        ;deschid fisierul
        push dword access_mode
        push dword file_name
        call [fopen]
        
        mov dword [file_desc], eax
        cmp eax, 0
        je the_end
        
        mov ebx, 0
        mov esi, 0
        ;citesc cuvintele
        repeat1:
            cmp bh, 0
            jne modif_litera
            je continua
            
            modif_litera:
                mov bh, byte [caract]
                mov byte [last_letter], bh
            
            continua:
                push dword caract
                push dword char_format
                call [scanf]
                add esp, 4*2
                cmp dword [caract], '#'
                je the_end
                
                mov bh, byte [caract]
                mov byte [cuvant+esi], bh
                ;cand am spatiu stiu ca incepe alt cuvant si reinitializez lg si retin prima litera si verific pt prima si ultima litera a cuv anterior
                cmp bl, 0
                je new_word
                jne continua_cuv
            
            new_word:
                cmp byte [count], dl
                je verif_litere
                mov bl, 0
                mov byte [count], 0
                inc byte [count]
                mov esi, 0
                jmp repeat1
                
            verif_litere:
                cmp byte [last_letter], bh
                je afisare
                
            continua_cuv:
                inc bh
                inc byte [count]
                jmp repeat1
            
            afisare:
                push dword cuvant
                push dword string_format
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                jmp repeat1
                
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
