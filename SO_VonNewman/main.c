#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bib_newman.h"

/*Enviar o programa que simule pelo menos uma das arquiteturas do Von Newman.
O usuário fornecerá os valores das posições de memória, posteriormente a equação e,
finalmente, ele fará a escolha da arquitetura a será utilizada.
Mostre na tela a resolução do problema de acordo com a arquitetura escolhida. */


int main()
{
    char exp[100], c, var[10];
    int i=0;

    printf("\n#########################################################################\n");
   printf("\nArquitetura de Von Newman utilizando a arquitetura de 0 enderecos\n");
   printf("\n##########################################################################\n");
   printf("Agora informe a operacao desejada (SEM ESPACOS), COM PARENTESES E MINUSCULO: \n");
   printf("\nExemplo: (b*c)+(b/c)\n");
    scanf("%s", exp);

    printf("\nAgora informe os valores de cada endereco em ordem de insercao:\n");
    scanf("%s",var);

    int tam = calc_tam(exp);
    char exp_pos[tam]; /*expressão pós-fixada*/

    printf("\nOrdem da expressao na pilha infixada:\n ");
    In2Pos(exp, exp_pos);

printf("Ja na Arquitetura de Newman: \n");
    for (i=0; i<tam-1; i++){
        c = exp_pos[i];
        imprime(c);
        printf("\n\n");
    }
    printf("->  HALT\t\n\n");
    /*char op[3];
    printf("informe a equacao:");
        scanf("%c",&op[3]);
for(i=0;i<sizeof(op);i++){
    switch(op[i]){
    case '+':
        printf("\nADD C %c %c", a1,a2);
        break;
    case '-':
        printf("\nSUB C %c %c",a1,a2);
        break;
    case '*':
        printf("\nMUL C %c %c",a1,a2);
        break;
    case '/':
        printf("\nDIV C %c %c",a1,a2);
        break;
    default:
        printf("\nOperação invalida\n");
    }*/


}



