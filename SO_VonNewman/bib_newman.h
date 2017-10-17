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

void In2Pos(char exp[], char exp_pos[]); //transforma a express�o infixada em p�s- fixada
int Prioridade(char c, char t); //define qual simbolo matem�tico � a prioridade
int confere(char exp[]); //confere quantidade de caracteres na express�o matem�tica inserida
void imprime(char c); //printa na tela as opera��es que s�o feitas de acordo com a arquitetura
