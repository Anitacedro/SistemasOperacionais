#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER 10
void *print_hello_world(void *tid){
printf("Hello World. Thread: %d\n",tid);
pthread_exit(NULL);

}

int main(int argc, char *agv[]){

pthread_t threads[NUMBER];
int status, i;

for(i=0; i<NUMBER; i++){

printf("Main here. Creating thread %d\n",i);
status = pthread_create(&threads[i],NULL,print_hello_world,(void *)i);
pthread_join(threads[i],NULL);

//teste de criação de thread
if(status != 0){
printf("Thread não criada, erro %d\n",status);
exit(-1);
}

}
exit(NULL);
}
