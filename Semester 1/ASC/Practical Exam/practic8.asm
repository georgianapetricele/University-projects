bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fprintf,scanf,fopen               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll                         ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    format_string db "%s",0
    format_dec db "%d",0
    access_mode db "w",0
    file_desc dd 0
    file_name db "practic8.txt",0
    zero db 0
    cuvant times 50 db 0
    cuvant2 times 50 db 0
    numar db 0

; our code starts here
segment code use32 class=code
    start:
        ; 20.	Se citeste de la tastatura un cuvant si un numar. Daca numarul este par se cere criptarea cuvantului prin adunarea la fiecare caracter a numarului 20. Daca numarul este impar se cere criptarea cuvantului prin adaugarea dupa fiecare vocala a gruparii "p"+vocala.Se cere afisarea cuvantului criptat in fisier
        ; ex: arici 3 => aparipicipi

        ;deschid fisierul
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je the_end
        mov dword [file_desc], eax
        
        ;citesc
        push dword cuvant
        push dword format_string
        call [scanf]
        add esp, 4*2
        
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 4*2
        
        mov eax, 0
        mov ebx, 0
        mov edx, 0
        mov eax, dword [numar]
        mov bx, 2
        div bx
        cmp dx, 1
        je impar
        jne par
        
        impar:
        ;dupa vocala adaug p
            mov esi, cuvant
            mov edi,cuvant2
            mov eax,0
            repeta2:
                cmp byte [esi],0
                je afisare
                ;vad daca e vocala a,e,i,o,u
                cmp byte [esi], 'a'
                jne cmpe
                lodsb 
                stosb 
                mov byte [edi], 'p'
                inc edi
                jmp repeta2
                
                cmpe:
                cmp byte [esi], 'e'
                jne cmpi
                lodsb 
                stosb 
                mov byte [edi], 'p'
                inc edi
                jmp repeta2
                
                cmpi:
                cmp byte [esi], 'i'
                jne cmpo
                lodsb 
                stosb 
                mov byte [edi], 'p'
                inc edi
                jmp repeta2
                
                cmpo:
                cmp byte [esi], 'o'
                jne cmpu
                lodsb 
                stosb 
                mov byte [edi], 'p'
                inc edi
                jmp repeta2
                
                cmpu:
                cmp byte [esi], 'u'
                jne move_on
                lodsb 
                stosb 
                mov byte [edi], 'p'
                inc edi
                jmp repeta2
                
                inc esi
                jmp repeta2
                
                move_on:
                lodsb 
                stosb
                jmp repeta2
        
        
        jmp the_end
        par:
            mov esi, 0
            repeta:
                cmp byte [cuvant+esi],0
                je afisare
                add byte [cuvant+esi], 20
                inc esi
                jmp repeta
          
        afisare:
            push dword cuvant2
            push dword format_string
            push dword [file_desc]
            call [fprintf]
            add esp, 4*3
            
        the_end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
