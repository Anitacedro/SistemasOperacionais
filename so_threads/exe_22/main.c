#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUMBER 10

int vetpar[10],vet_t[10],i;
volatile int s_par = 0, k=0, j=1;

int gera_numero(void)
{
    int aux = rand() % 100;
    return aux;

}

int verifica_par (int num, int i, int tid)
{
    if (num % 2 == 0 && vetpar[i-1]== num -2)
    {
        vetpar[i] = num;
        vet_t[i] = tid;
        return 1;
    }
    else
        return 0;

}

void imprime (int v[])
{
    int i;
    printf("\n | ");
    for (i=0; i<10; i++)
    {
        printf("%d | ", v[i]);
    }
    printf("\n");
}

void * preencher_par (int tid)
{
    int num;

    while (k<10)
    {
        if(s_par == 0)
        {
            s_par = 1;
            if (k == 0)
            {
                num = rand() % 80;
                if (num % 2 == 0)
                {
                    vetpar [k] = num;
                    vet_t[k] = tid;
                    k++;
                }

            }
            else
            {
                if (verifica_par(rand()%100, k, tid))
                {

                    k++;
                    sleep(rand()%3);
                }
            }

            s_par = 0;
            sleep(1);
        }
    }
}




int main(int argc, char *agv[])
{
    srand(time(NULL));
    pthread_t threads[NUMBER];
    int  i;



    for(i = 0; i < 100; i++)
    {
        pthread_create(&threads[i], NULL, preencher_par, i);
    }


    for(i=0; i<100; i++)
    {
        pthread_join(threads[i],NULL);
    }

    printf("\nvetor:");
    imprime(vetpar);
    printf("\nthread");
    imprime(vet_t);
    return 0;
}
