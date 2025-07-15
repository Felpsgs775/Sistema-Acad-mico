#ifndef CERTIFICADO_H
#define CERTIFICADO_H
#define MAX_NOME 100
#define HORAS_PRA_VALIDAR 60
typedef struct {
    char nome[MAX_NOME];
    int cargaHoraria;
} Certificado;

#endif
