#ifndef PD_H
#define PD_H
#include "Certificado.h"
typedef struct Nodo
{
    int info;
    struct Nodo *prox;
}nodo;
typedef struct
{
    nodo *topo;
}Pilha;
Pilha *cria_pilha();
void push(Pilha *p, Certificado *x);
Certificado *pop(Pilha *p);
void libera(Pilha *p);
int vazia(Pilha *p);
int cheia(Pilha *p);
int tamanho(Pilha *p);
#endif
