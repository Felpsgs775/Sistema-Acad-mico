#ifndef PE_H
#define PE_H
#define MAX_PILHA 50
#include "Certificado.h"
typedef struct{
    Certificado *elementos[MAX_PILHA];
    int topo;
}Pilha;
Pilha *cria_pilha();
void push(Pilha *p, Certificado *x);
Certificado *pop(Pilha *p);
int vazia(Pilha *p);
void libera(Pilha *p);
int cheia(Pilha *p);
int tamanho(Pilha *p);
#endif