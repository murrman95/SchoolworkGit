#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

char * buffer;
int i = 0;
int buffercounter = 0;

#define SIZE 5

char nextProduced();
void *producer();
void *consumer();
sem_t full;
sem_t empty;
sem_t lock;
pthread_t pthreads[10];
pthread_t cthreads[10];

int main(){


  sem_init(&full,0,0);
  sem_init(&empty,0,SIZE);
  sem_init(&lock,0,1);

  buffer = malloc(sizeof(char) * SIZE);

  for(int i = 0; i < 10; i ++){
    pthread_create(&pthreads[i], NULL, producer, NULL);
    pthread_create(&cthreads[i], NULL, consumer, NULL);
  }

  for(int j = 0; j < 10; j ++){
    pthread_join(pthreads[j], NULL);
    pthread_join(cthreads[j], NULL);
  }

  sem_destroy(&full);
  sem_destroy(&empty);
  sem_destroy(&lock);
  return 0;
}

char nextProduced(){
  char c = (char)('A' + (i % 26));
  i ++;
  return c;
}

void *producer(){

  sem_wait(&empty);
  sem_wait(&lock);

  buffer[buffercounter % 5] = nextProduced();
  printf("nexProduced is: %c\n", buffer[buffercounter % 5]);
  buffercounter ++;

  sem_post(&lock);
  sem_post(&full);

  pthread_exit(NULL);
}

void *consumer(){
  sem_wait(&full);
  sem_wait(&lock);

  buffercounter --;
  printf("nextConsumed is: %c\n", buffer[buffercounter % 5]);


  sem_post(&lock);
  sem_post(&empty);

  pthread_exit(NULL);
}
