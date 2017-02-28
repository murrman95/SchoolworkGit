#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

#define ID_MIN 300
#define ID_MAX 320
#define SLEEP 3
#define NUM_THREADS 25

int id;
void allocator();
pthread_mutex_t lock;

int main(){
  id = ID_MIN;
  pthread_t threads[ID_MAX + 1];
  pthread_mutex_init(&lock, NULL);

  for(int i = 0; i <25; i ++){
    pthread_create(&threads[i],NULL,allocator,NULL);
  }
  for(int j = 0; j < 25; j ++){
    pthread_join(threads[j],NULL);
  }

  pthread_mutex_destroy(&lock);
  printf("Program ending.\n");

}

void allocator(){
  if(id <= ID_MAX){
    pthread_mutex_lock(&lock);
    int idt = id;
    id ++;
    pthread_mutex_unlock(&lock);
    srand(time(NULL));
    sleep(rand() % 3);
    printf("My thread no is: %d\n", idt);
    pthread_exit(NULL);
  }
  else{
    printf("NO THREADS LEFT\n");
    pthread_exit(NULL);
  }

}
