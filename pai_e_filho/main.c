#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    int vetor[5];
    int i;

    pid_t pid1,pid2;

    for(i=0;i<5;i++){
        printf("Informe o valor da posicao %d do vetor: ",i);
        scanf("%d", &vetor[i]);
    }

    pid1 = fork();

    //criacao do filho 1
    if(pid1 == 0){
        int soma=0,j;
        for(j=0;j<5;j++){
            if(vetor[j] % 2 == 0){
                soma += vetor[j];
            }
        }
        printf("Soma dos pares no filho 1: %d\n", soma);
    }else{
        pid2 = fork();
        //criei o 2 filho
        if(pid2 == 0){
            int soma=0,j;
            for(j=0;j<5;j++){
                if(vetor[j] % 2 != 0){
                    soma += vetor[j];
                }
            }
            printf("Soma dos impares no filho 2: %d\n", soma);
        }
    }
    return 0;
}
