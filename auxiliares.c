#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Certificado.h"
#include "auxiliares.h"
void converte_emmaiusculas(char *destino, const char *origem)
{
    int i = 0;
    while(origem[i])
    {
        destino[i] = toupper((unsigned char) origem[i]);     //Funcao que converte nomes pra maiusculas
        i++;
    }
    destino[i] = '\0';
}
int antidiferenciacaodenomes(const char *a, const char *b)          
{                           
    while(*a && *b)//funcao para comparar nomes ignorando se o nome esta em maiusculo ou minusculo
    {
        if (tolower((unsigned char) *a) != tolower((unsigned char) * b))                 
            return 0;
        a++;
        b++;
    }
    return *a == *b;
}