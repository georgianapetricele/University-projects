bits 32 ; assembling for the 32 bits architecture

;Count the letters from each word and print the numbers on the screen.
  
global _asmCountletters 

; declare external functions needed by our program


; our data is declared here (the variables needed by our program)
segment data public data use32
    adresa_sir_cuv dd 0
    

; codul scris in asamblare este dispus intr un segment public, posibil a fi partajat cu alt cod extern
segment code public code use32

    _asmCountletters:
        ;Codul de intrare
        push ebp
        mov ebp, esp
        
        mov eax, [ebp+8]
        mov [adresa_sir_cuv], eax
        mov ecx, [ebp +12]
        mov esi, [adresa_sir_cuv]
        mov eax, 0
        mov ebx, 0
        repeta:
            ;vad daca e litera
            ;if c >'A' elif c<'Z' elif c>'a' elif c<'z'
            lodsb 
            cmp al, 'A'
            jae litera_mare
            jb not_letter
            litera_mare:
                cmp al, 'Z'
                jbe e_litera
                ja litera_mica1
            litera_mica1:
                cmp al, 'a'
                jae litera_mica_2
                jb not_letter
            litera_mica_2:
                cmp al, 'z'
                jbe e_litera
                ja not_letter
            e_litera:
                inc bl
            not_letter:
        loop repeta
        the_end:
        
        ;Iesire
        
        mov eax, 0
        mov al, bl;pun rezultatul in eax pentru a fi returnat in subprogramul c
        
        mov esp, ebp
        pop ebp
        
        ret 2*4
