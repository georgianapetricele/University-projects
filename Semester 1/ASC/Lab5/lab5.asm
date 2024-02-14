bits 32 ; assembling for the 32 bits architecture


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll  ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s1 db "+42a84X5"
    lens1 equ $-s1
    s2 db "a45"
    lens2 equ $-s2
    s3 times 6 db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; 28. Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements found on the positions multiple of 3 from S1 and the elements of S2 in reverse order.
        ;S1: '+', '4', '2', 'a', '8', '4', 'X', '5'
        ;S2: 'a', '4', '5'
        ;D: '+', 'a', 'X', '5', '4', 'a'
        
        ;muta in s3 caract de pe pozitii multiplu de 3 din s1
        mov esi,0
        mov edi,0
        mov ecx, lens1/3+1    ;merg din 3 in 3
        jecxz sfarsit1   ;daca are lungimea 0
    bucla1:
        mov al, [s1+esi]  ;pun in al caract din s2 de pe pozitia esi
        mov [s3+edi], al   ;pun in s3 caract din al pe pozitia edi
        add esi, 3         ;trec la urmatorul caract de pe poz multiplu de 3
        inc edi            ;incrementez pozitia de adaugat in s3
        loop bucla1
        sfarsit1:
        
        ; muta in s3 caract din s2 in ordine inversa
        mov eax, 0
        mov esi, lens2-1 ;initializez index ul lui s2 de la final
        mov ecx, lens2  ;initializez contorul pentru loop cu lens2
        jecxz sfarsit2
    bucla2:
        mov al,[s2+esi]     ;pun in al caract din s2 de pe pozitia esi
        mov [s3+edi], al       ;pun in s3 caract din al pe pozitia edi
        sub esi, 1             ;trec la urmatorul caract din s2 in  ordine inversa
        inc edi                 ;incrementez pozitia de adaugat in s3
        loop bucla2             
        sfarsit2:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
