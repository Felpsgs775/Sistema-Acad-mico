#ifndef FE_H
#define FE_H
#define MAX_FILA 25
#include "Certificado.h"
typedef struct {
Certificado *v[MAX_FILA];
int inicio, fim;
}Fila;
Fila *cria_fila();
int filavazia(Fila *f);
void pushfila(Fila *f, Certificado *x);
Certificado *popfila(Fila *f);
void liberafila(Fila *f);
int tamanhoFila(Fila *f);
int filaCheia(Fila *f);
#endif
