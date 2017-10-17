#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bib_newman.h"

int j = 0;
/*estrutura da pilha comum*/
Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

Pilha *pilha_push(Pilha *p, char val)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = p->topo;
    p->topo = novo;

    return 0;
}

int pilha_pop(Pilha *p)
{
    Lista* temporaria;
    int val;

    temporaria = p->topo;
    val = temporaria->info;
    p->topo = temporaria->prox;
    free(temporaria);
    return val;
}

/* estrutura da pós fixada*/

void In2Pos(char exp[], char exp_pos[])
{
    Pilha *p;
    int i = 0;
    char c, t;

    p = pilha_cria();
    pilha_push(p, '(');

    do
    {
        c = exp[i];
        i++;
        if(c >= 'a' && c <= 'z')
        {
            printf("%c", c);
            if(c != '(' && c != ')')
            {
                exp_pos[j] = c;
                j++;
            }
        }
        else if(c == '(')
        {
            pilha_push(p, '(');
        }
        else if(c == ')' || c == '\0')
        {
            do
            {
                t = pilha_pop(p);
                if(t != '(')
                    printf("%c", t);
                if(t != '(' && t != ')')
                {
                    exp_pos[j] = t;
                    j++;
                }
            }
            while(t != '(');
        }
        else if(c == '+' || c == '-' ||
                c == '*' || c == '/' ||
                c == '^' )
        {
            while(1)
            {
                t = pilha_pop(p);
                if(Prioridade(c,t))
                {
                    pilha_push(p, t);
                    pilha_push(p, c);
                    break;
                }
                else
                {
                    printf("%c", t);
                }
            }
        }
    }
    while(c != '\0');
    printf("\n\n\n");
    free(p);
}


//qual operação tem prioridade
int Prioridade(char c, char t){
  int pc,pt;

  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;

  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;

  return (pc > pt);
}

int calc_tam(char exp[])
{
    int t=1, k=0;
    char x = exp[k];

    while(x != '\0')
    {
        if(x != '(' && x != ')')
        {
            t++;
        }
        k++;
        x = exp[k];
    }
    return t;
}

void imprime(char c){

    if(c == '*')
        printf("->  MULT\t");
    else if(c == '+')
        printf("->  ADD\t");
    else if(c == '-')
        printf("->  SUB\t");
    else if(c == '/')
        printf("->  DIV\t");
    else
        printf("->  PUSH\t%c", c);


}

