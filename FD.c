#include <stdlib.h>
#include <stdio.h>
#include "Certificado.h"
#include "FD.h"
Fila *cria_fila() 
{
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}
void pushfila(Fila *f, Certificado *x) 
{
    nodo *novo = (nodo *) malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;

    if (f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;

    if (f->inicio == NULL)
        f->inicio = novo;
}
Certificado *popfila(Fila *f) 
{
    if (filavazia(f)) return NULL;

    nodo *removido = f->inicio;
    Certificado *x = removido->info;

    f->inicio = removido->prox;
    if (f->inicio == NULL)
        f->fim = NULL;

    free(removido);
    return x;
}
int filavazia(Fila *f) 
{
    return f->inicio == NULL;
}
int filaCheia(Fila *f) 
{
    return 0;
}
void liberafila(Fila *f) 
{
    free(f);
}
int tamanhoFila(Fila *f) 
{
    int t = 0;
    nodo *atual = f->inicio;
    while (atual != NULL) {
        t++;
        atual = atual->prox;
    }
    return t;
}
