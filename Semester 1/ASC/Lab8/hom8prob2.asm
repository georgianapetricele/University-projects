bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, scanf, fopen, fprintf,fclose
import exit msvcrt.dll            
import fopen msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name2 db "afisare.txt", 0
    access_mode2 db "w", 0
    fdw resd 1
    format dd "%s", 0
    format_w dd "%s", 0
    cuv resd 2
    space dd ' '
    found resb 1
; our code starts here
segment code use32 class=code
    start:
        ;A file name (defined in data segment) is given. Create a file with the given name, then read words from the keyboard until character '$' is read. Write only the words that contain at least one lowercase letter to file.
         
         
        push access_mode2
        push file_name2
        call [fopen]
        add esp, 4*2
        mov [fdw], eax
        cmp eax, 0
        je theend
        
        repeat1:
        
        push cuv
        push format
        call [scanf]
        add esp, 4*2
        
        cld
        mov byte[found], 0 
        mov esi, 0
        cmp byte[cuv+esi], 24h  ; daca am $
        je theend
                   
        
        mov ecx, 3
        repeat2:            ;verific pentru fiecare caracter din word ul curent
        cmp byte[cuv+esi], 61h   
        inc esi
        jge updatefound
        jb passover
        updatefound:
        mov byte[found], 1
        passover:
        loop repeat2      ;trec la alta litera
        
        cmp byte[found],1  ;daca nu am litera mica in cuvant
        je foundlcletter
        jb nextword
        
        foundlcletter: ;am gasit o litera mica in cuvant
        mov byte[cuv+esi], ' ' 
        
        push dword cuv
        push dword format_w
        push dword[fdw]
        call [fprintf]
        add esp, 4*3
       ;am gasit o litera mica => trec la alt cuvant
        nextword:       
        jmp repeat1
        
        theend:
        push dword[fdw]
        call [fclose]
        add esp, 4*1
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
