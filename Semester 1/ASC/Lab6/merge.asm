bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf      
import printf msvcrt.dll         ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s1 db "123556"
    lens1 equ $-s1
    s2 db "2348"
    lens2 equ $-s2
    lens3 equ lens1+lens2
    s3 times lens3 db 0
    
; our code starts here
segment code use32 class=code


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ; Merge
        ;s1= 1 2 3 5 5 6 
        ;s2= 2 3 4 8
        ;s3= 1 2 2 3 3 4 5 5 6 8
        mov esi, 0
        mov eax, 0
        mov ebx, 0
        mov edi, s3
        mov ecx, 0
        mov ecx, lens3
        jecxz theend
        repeat1:
            cmp esi,lens1      ; daca am ajuns la finalul lui s1
            jae continuas1
            cmp ebx, lens2     ; daca am ajuns la finalul lui s2
            jae continuas2
            mov al, [s1+esi]   ; pun in esi contorul pentru s1
            mov ah, [s2+ebx]   ; pun in ebx contorul pentru s2
            cmp al,ah   
            jbe eticheta1          ;adaug in s3 valoarea mai mica  ah pt CF=0
                mov [edi], ah
                inc ebx
                inc edi
                jmp after  ;cand intra pe ramura asta trebuie sa sar peste a doua
            eticheta1:
                stosb              ;adaug in s3  al pt Cf=1    => mov [edi], al   si inc edi
                inc esi
            after:
            loop repeat1
        theend:
        ;loop uri pentru elementele ramase 
        continuas1:
            repeat2:
            mov al, [s2+ebx]  ;adaug elem care au ramas in s2
            stosb
            inc ebx
            loop repeat2
            jmp final
        continuas2:
            repeat3:
            movsb   ;adaug ce a ramas in s1
            stosb
            loop repeat3
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
