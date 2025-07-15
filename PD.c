#include <stdio.h>
#include <stdlib.h>
#include "PD.h"
#include "Certificado.h"
Pilha *cria_pilha() 
{
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
void push(Pilha *p, Certificado *x) 
{
    nodo *novo = (nodo *) malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = p->topo;
    p->topo = novo;
}
Certificado *pop(Pilha *p) 
{
    if (vazia(p)) return NULL;
    nodo *topo_antigo = p->topo;
    Certificado *x = topo_antigo->info;
    p->topo = topo_antigo->prox;
    free(topo_antigo);
    return x;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

int cheia(Pilha *p) 
{
    return 0; 
}
void libera(Pilha *p) 
{
    free(p);
}

int tamanho(Pilha *p) 
{
    int t = 0;
    nodo *atual = p->topo;
    while (atual != NULL) {
        t++;
        atual = atual->prox;
    }
    return t;
}