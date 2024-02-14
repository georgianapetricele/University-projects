#include <stdio.h>
#include <string.h>

// Dacă utilizăm compilatorul C din Microsoft Visual Studio 2015, 2017, 2019
// este necesar să includem librăria legacy_stdio_definitions.lib la linkeditare
#pragma comment(lib, "legacy_stdio_definitions.lib")

// Această librărie este necesară doar pentru Microsoft Visual Studio 2019
// #pragma comment(lib, "legacy_stdio_wide_specifiers.lib")

// Forțăm linkeditorul să includă definiției funcției printf()
// în executabilul final, deoarece o vom apela din modulul ASM
#pragma comment(linker, "/INCLUDE:_printf")


// declararea procedurii definite in limbaj de asamblare
int asmCountletters(char cuvant[], int lenght);

// declararea functiei C folosite pentru a citi un sir de la tastatura
void citireSirC(char sir[]);

// definirea sirului global care va fi accesat din asmConcat
char str3[] = "0011223344";

//Read a sentence from the keyboard. Count the letters from each word and print the numbers on the screen.

int main()
{
    int lencuv;
    int length;
    char sir[101];
    printf("Sirul citit in modulul C este: ");
    gets(sir);
    //despart sirul in cuvinte
    char* cuvant = strtok(sir, " ");
    while (cuvant != NULL)
    {
        length = strlen(cuvant);
        lencuv = asmCountletters(cuvant, length);
        printf("\n%d", lencuv);
        cuvant = strtok(NULL," ");
    }

    return 0;
}

// definirea functiei C folosite pentru a citi un sir de la tastatura
void citireSirC(char sir[])
{
    scanf("%s", sir);
}

// cd C:\asm_work\asmc2
// nasm asmCountletters.asm -fwin32 -o asmCountletters.obj
// cl main.c /link asmCountletters.obj