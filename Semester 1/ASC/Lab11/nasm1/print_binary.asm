bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)      

extern exit,fprintf             
import exit msvcrt.dll    
import fprintf msvcrt.dll   
                 
global _stringtobinary
segment data use32 class=data
    

; our code starts here
segment code use32 class=code
    _stringtobinary:
    sub ecx, '0'          ;transform caracterul in cifra ( 31 --> 1 )
    ret 
     
    ;nasm -fobj print_binary.asm
    ;nasm -fobj mainstringtobinary.asm
    ;alink mainstringtobinary.obj print_binary.obj -oPE -subsys console -entry start