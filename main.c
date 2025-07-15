#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PE.h"
#include "FE.h"
#include "Certificado.h"
#include "auxiliares.h"
#define MAX_ALUNOS 1000
int main()
{
    Pilha *p = cria_pilha();
    Fila *f = cria_fila();
    int alunos_registrados = 0;
    Sistemaacademico sistema[MAX_ALUNOS];
    char linhadecomando[100];
    while(1)
    {
        scanf("%s", linhadecomando);
        //Se o usuario quiser empilhar certificado
        if(strcmp(linhadecomando, "certificado") == 0)
        {
            char nome_completo[MAX_NOME];
            int ch;
            getchar();
            fgets(nome_completo, MAX_NOME, stdin);
            nome_completo[strcspn(nome_completo, "\n")] = 0;
            char *linha = strrchr(nome_completo, ' ');
            if(linha==NULL) continue;
            *linha = '\0';
            ch = atoi(linha + 1);
            Certificado *cert = malloc(sizeof(Certificado));
            strcpy(cert->nome, nome_completo);
            cert->cargaHoraria = ch;
            if(cheia(p))
            {
                printf("Pilha cheia\n");
                free(cert);
            }
            else
            {
                push(p, cert);
                printf("%s empilhou um certificado de %d horas\n",nome_completo, ch);
            }
        }
        //Caso o usuario use o comando coordenador
        else if(strcmp(linhadecomando, "coordenador") == 0)
        {
            int k;
            scanf("%d", &k);
            int processados = 0;
             for (int i = 0; i < k; i++) 
             {
                if (filavazia(f))
                    break;
                Certificado *cert = popfila(f);
                int encontrado = 0;
                for (int j = 0; j < alunos_registrados; j++) 
                {
                    if (antidiferenciacaodenomes(cert->nome, sistema[j].nome)) 
                    {
                        sistema[j].horas += cert->cargaHoraria;
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado && alunos_registrados < MAX_ALUNOS) 
                {
                    strcpy(sistema[alunos_registrados].nome, cert->nome);
                    sistema[alunos_registrados].horas = cert->cargaHoraria;
                    alunos_registrados++;
                }
                free(cert);
                processados++;
            }
            printf("%d certificados processados\n", processados);
        }
        //Caso o usuario use o comando departamento
        else if(strcmp(linhadecomando, "departamento") == 0)
        {
            int k;
            scanf("%d", &k);
            int repassados = 0;
            for(int i = 0; i < k; i++)
            {
                if(vazia(p) || filaCheia(f))
                break;
                Certificado *c = pop(p);
                pushfila(f,c);
                repassados++;
            }
            printf("%d certificados repassados\n", repassados);
        }
        //Caso o usuario use o comando de validar
        else if(strcmp(linhadecomando, "valida") == 0)
        {
            char nome[MAX_NOME];
            getchar();
            fgets(nome,MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = 0;
            int encontrado = 0;
            for(int i = 0; i < alunos_registrados; i++)
            {
                if(antidiferenciacaodenomes(nome, sistema[i].nome))
                {
                    encontrado = 1;
                    if(sistema[i].horas >= 60)
                    {
                        sistema[i].horas -= 60;
                        printf("%s validou 60 horas\n", nome);
                    }
                    else
                    {
                        printf("%s nao tem 60 horas registradas", nome);
                    }
                    break;
                }
            }
            if(!encontrado)
            {
                printf("%s nao tem 60 horas registradas\n", nome);
            }
        }
        //Caso o usuário use o comando sistema
        else if(strcmp(linhadecomando, "sistema") == 0)
        {
            for(int i = 0; i < alunos_registrados; i++)
            {
                if(sistema[i].horas > 0)
                {
                    char nome_emmaiuscula[MAX_NOME];
                    converte_emmaiusculas(nome_emmaiuscula, sistema[i].nome);
                    printf("%s: %d horas totais\n", nome_emmaiuscula, sistema[i].horas);
                }
            }
        }
        //Caso o usuario encerre o programa digitando "F"
        else if(strcmp(linhadecomando, "F") == 0)
        {
            printf("sobraram %d certificados na pilha\n", tamanho(p));
            printf("sobraram %d certificados na fila", tamanhoFila(f)); //imprime na tela quantos certificados sobraram na pilha  e na fila
            //A seguir, fiz laços para esvaziar a pilha e a fila
            while(!vazia(p))
            {
                Certificado *c = pop(p);
                free(c);
            }
            libera(p);
            while(!filavazia(f))
            {
                Certificado *c = popfila(f);
                free(c);
            }
            liberafila(f);
        }
    }
    return 0;
}
