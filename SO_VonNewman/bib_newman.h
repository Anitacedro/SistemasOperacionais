#include<stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista
{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct pilha
{
    Lista *topo;
};
typedef struct pilha Pilha;

Pilha *pilha_cria(void);

Pilha *pilha_push(Pilha *p, char val); // insere elemento no inicio da pilha

int pilha_pop(Pilha *p); // retira o primeiro elemento da pilha

void In2Pos(char exp[], char exp_pos[]); //transforma a expressão infixada em pós- fixada
int Prioridade(char c, char t); //define qual simbolo matemático é a prioridade
int confere(char exp[]); //confere quantidade de caracteres na expressão matemática inserida
void imprime(char c); //printa na tela as operações que são feitas de acordo com a arquitetura
