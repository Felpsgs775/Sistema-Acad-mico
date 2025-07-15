#ifndef FD_H
#define FD_H
#include "Certificado.h"
typedef struct Nodo {
int info; 
struct Nodo *prox; 
} nodo;
typedef struct {
nodo *inicio;
nodo *fim;
} Fila;
int vazia(Fila *f);
Fila *cria_fila();
void liberafila(Fila *f);
void pushfila(Fila *f, Certificado *x);
Certificado *popfila(Fila *f);
int filavazia(Fila *f);
int tamanhoFila(Fila *f);
#endif