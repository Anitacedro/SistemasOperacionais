#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd1[2], /* Pai vai escrever e Filho ler por esse file descriptor */
        fd2[2], /* Pai vai ler e o Filho escrever por esse file descriptor */
         turn=0; /* Vai definir o que cada um vai fazer (ler, escrever, aguardar...) */
    pid_t pid;   /* Armazena o pid, para o tratamento de pai e filho */

    /* Cria o pipe 1 */
    if(pipe(fd1)<0) {
        perror("pipe") ;
        return -1 ;
    }

    /* Cria o pipe 2 */
    if(pipe(fd2)<0) {
        perror("pipe") ;
        return -1 ;
    }

    /* Cria processo filho. */
    pid = fork();

    if(pid == -1) {
        perror("fork") ;
        return -1 ;
    }

    if(pid > 0) {    /* Processo pai*/
        int num,  /* Números que o processo pai lê*/
            fat;    /* Resultado do fatorial, recebido pelo filho*/

        /* Fechando o descritor LEITURA no primeiro pipe. */
        close(fd1[0]);
        /* Fechando o descritor ESCRITA no segundo pipe. */
        close(fd2[1]);

         printf("Insira um numero de 1 a 20: "); scanf("%d", &num);

        while(1)
            if(turn==0){ /* Pai vai escreever */

                write(fd1[1], num, sizeof(num)); /* Enviando o vetor de números pro filho */
                turn=1; /* Passa para o próximo passo, que é o pai ler a soma do filho */
            }else

            if(turn==1){ /* Pai vai ler a soma */
                read(fd2[0], &fat, sizeof(fat)); /* Pai leu o resultado da soma, e armazenou no inteiro 'soma' */
                printf("fat: %d\n\n", fat);
                turn=0;  /* Retorna pro passo anterior, pra começar tudo de novo */
            }


        close(fd2[0]);
        close(fd1[1]);

    } else {
        int numeros,
             fat,i;

        /* Fechando o descritor ESCRITA no primeiro pipe. */
        close(fd1[1]);
        /* Fechando o descritor LEITURA no segundo pipe. */
        close(fd2[0]);

        while(1){
            if(turn==0){ /* Filho vai ler o vetor de numeros do pai */
                read(fd1[0], numeros, sizeof(numeros) ); /* Recebeu o vetor de inteiros do pai e colocou no vetor 'numeros' */
                turn=1;  /* Passa para o próximo passo, que é o filho somar e escrever o resultado da soma */
            }else

            if(turn==1){ /* Filho calcula a soma e retorna pro pai */
            for (i=1; i < numeros; i++){
                numeros = numeros * i;
            fat=numeros;

            }
                write(fd2[1], &fat, sizeof(fat)); /* Envia a soma, qúe está na variável 'soma', para o pai */
                turn=0; /* Volta para o passo anterior, que é esperar vetor de inteiros do pai */
            }
        }

        close(fd2[1]);
        close(fd1[0]);
    }

    return 0 ;
}


