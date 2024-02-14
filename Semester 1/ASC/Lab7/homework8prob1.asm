bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import printf msvcrt.dll
import scanf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    format db "%d"
    message db "The maximum number is= %d", 0
    x resd 1

; our code starts here
segment code use32 class=code
    start:
        ;Read numbers (in base 10) in a loop until the digit '0' is read from the keyboard. Determine and display the biggest number from those that have been read.
        
        mov ebx, 0     ;retin in ebx maximul
        
        repeat1:  
        push x
        push format
        call [scanf]  ;citesc fiecare numar
        add esp, 4*2
        cmp dword[x], 0
        je theend
        
        mov eax,0
        mov eax, [x]
            
            cmp ebx,eax  ;bl -al
            jle maxim    
            jmp repeat1
                ;daca nr curent nu e mai mare sau egal cu maximul nu actualizez maximul
            maxim:
                mov ebx,eax
        jmp repeat1
        
        theend:
        
        push ebx
        push dword message
        call [printf]
        add esp, 4*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program