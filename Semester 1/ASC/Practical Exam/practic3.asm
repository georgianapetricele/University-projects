bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,fprintf,fopen               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll 
import fopen msvcrt.dll 
import fprintf msvcrt.dll     ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    access_mode db "w",0
    string_format db "%s",0
    spatiu dd " ",0
    dec_format db "%d",0
    char_format db "%c", 0
    file_name db "practic3.txt",0
    file_desc dd 0
    n dd 0
    cuvant times 50 db 0
    

; our code starts here
segment code use32 class=code
    start:
         ; 1.Sa se citeasca de la tastatura un numar n, apoi sa se citeasca mai multe cuvinte, pana cand se citeste cuvantul/caracterul "#". Sa se scrie intr-un fisier text toate cuvintele citite care incep si se termina cu aceeasi litera si au cel putin n litere.
         
        ;citesc tastatura:  n cuvinte citesc #
        push dword n
        push dword dec_format
        call [scanf]
        add esp, 4*2
        
        ;deschid fisierul
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je the_end
        mov dword [file_desc], eax
        
        mov eax,0
        mov ebx,0
        
        repeta:
            ;citesc fiecare cuvant
            push dword cuvant
            push dword string_format
            call [scanf]
            add esp, 4*2
            cmp byte [cuvant], "#"
            je the_end
            
            mov esi, 0
            mov ebx, 0
            mov bh, byte [cuvant+esi]
            mov bl, byte [cuvant+esi]
            inc esi
            repeta2:
                cmp byte [cuvant+esi], 0
                je verificare
                mov bl, byte [cuvant+esi]
                inc esi
                jmp repeta2
                
            verificare:
                cmp bh,bl
                je verificare2
                jne repeta
            
            verificare2:
                cmp esi, dword [n]
                je afisare
                jne repeta
                
            ;afisez cuvantul
            afisare:
                push dword cuvant
                push dword string_format
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                
                push dword [spatiu]
                push dword char_format
                push dword [file_desc]
                call [fprintf]
                add esp, 4*3
                jmp repeta
        
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
