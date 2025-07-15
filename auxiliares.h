#ifndef auxiliares_H
#define auxiliares_H
#include "Certificado.h"
typedef struct
{
    char nome[MAX_NOME]; //<-----Struct para guardar os alunos no sistema
    int horas;
} Sistemaacademico;
void converte_emmaiusculas(char *destino, const char *origem);
int antidiferenciacaodenomes(const char *a, const char *b);
#endif          