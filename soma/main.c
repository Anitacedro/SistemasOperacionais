#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd1[2], /* Pai vai escrever e Filho ler por esse file descriptor */
        fd2[2], /* Pai vai ler e o Filho escrever por esse file descriptor */
        turn=0; /* Vai definir o que cada um vai fazer (ler, escrever, aguardar...) */
    pid_t pid;   /* Armazena o pid, para o tratamento de pai e filho */

    /* Cria o pipe 1 */
    if(pipe(fd1)<0)
    {
        perror("pipe") ;
        return -1 ;
    }
    /* Cria o pipe 2 */
    if(pipe(fd2)<0)
    {
        perror("pipe") ;
        return -1 ;
    }

    /* Cria processo filho. */
    pid = fork();

    if(pid == -1)
    {
        perror("fork") ;
        return -1 ;
    }

    if(pid > 0)      /* Processo pai pid>0*/
    {
        int vetor[5],i, soma;

        /* Fechando o descritor LEITURA no primeiro pipe. */
        close(fd1[0]);
        /* Fechando o descritor ESCRITA no segundo pipe. */
        close(fd2[1]);



        while(1)
        {
            if(turn==0)   /* Pai vai escreever */
            {
                for (i=0; i<5; i++)
                {
                    printf("Insira o elemento %d do vetor: ",i);
                    scanf("%d", &vetor[i]);
                }

                write(fd1[1], &vetor, sizeof(vetor)); /* Enviando o vetor pro filho */
                turn=1; /* Passa para o próximo passo, que é o pai ler a soma do filho */
            }
            else if(turn==1)   /* Pai vai ler a soma */
            {
                read(fd2[0], &soma, sizeof(soma)); /* Pai leu o resultado da soma, e armazenou no inteiro 'soma' */
                printf("soma: %d\n\n", soma);
                turn=0;  /* Retorna pro passo anterior, pra começar tudo de novo */
            }
        }

        close(fd2[0]);
        close(fd1[1]);
    }
    else
    {
        int vetor[5],
            soma,i;

        /* Fechando o descritor ESCRITA no primeiro pipe. */
        close(fd1[1]);
        /* Fechando o descritor LEITURA no segundo pipe. */
        close(fd2[0]);
        while (1)
        {
            if(turn==0)  /* Filho vai ler o vetor de numeros do pai */
            {
                read(fd1[0], &vetor, sizeof(vetor) ); /* Recebeu o vetor de inteiros do pai e colocou no vetor */
                turn=1;  /* Passa para o próximo passo, que é o filho somar e escrever o resultado da soma */
            }
            else if(turn==1)   /* Filho calcula a soma e retorna pro pai */
            {
                for (i=0, soma=0; i < 5; i++)
                {
                    soma += vetor[i];

                }
                write(fd2[1], &soma, sizeof(soma)); /* Envia a soma, qúe está na variável 'soma', para o pai */
                turn=0; /* Volta para o passo anterior, que é esperar vetor de inteiros do pai */
            }
        }
        close(fd2[1]);
        close(fd1[0]);
    }

    return 0 ;

}



