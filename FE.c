#include <stdio.h>
#include <stdlib.h>
#include "FE.h"
#include "Certificado.h"
Fila *cria_fila() 
{
   Fila *f = (Fila *)malloc(sizeof(Fila));
   f->inicio = f->fim = 0;
}

int filavazia(Fila *f)
{
   return f->inicio == f->fim ? 1 : 0;
}

void pushfila(Fila *f, Certificado *x) 
{
   f->v[ f->fim ] = x; 
   f->fim = (f->fim+1)%MAX_FILA;
}

Certificado *popfila(Fila *f) 
{
   if (!filavazia(f)) {
        Certificado *x = f->v[f->inicio];
        f->inicio = (f->inicio + 1) % MAX_FILA;
        return x;
    }
    return NULL;
}
void liberafila(Fila *f)
{
    free(f);
}
int tamanhoFila(Fila *f) {
    return (f->fim - f->inicio + MAX_FILA) % MAX_FILA;
}
int filaCheia(Fila *f) {
    return ((f->fim + 1) % MAX_FILA) == f->inicio;
}