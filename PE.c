#include<stdio.h>
#include<stdlib.h>
#include "PE.h"
Pilha *cria_pilha()
{
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}
void push(Pilha *p, Certificado *x)
{
    if(!cheia(p))
    {
        p->topo++;
        p->elementos[p->topo] = x;
    }
}
Certificado *pop(Pilha *p)
{
    if(!vazia(p))
    {
        Certificado *x  = p->elementos[p->topo];
        p->topo--;
        return x;
    }
    return NULL;
}

int vazia(Pilha *p)
{
    return (p->topo == -1);
}
void libera(Pilha *p)
{
    free(p);
}
int cheia(Pilha *p)
{
    return (p->topo == MAX_PILHA - 1);
}
int tamanho(Pilha *p) {
    return p->topo + 1;
}
