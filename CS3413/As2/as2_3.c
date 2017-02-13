#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int val = 0;

void increment();

int main(){

  printf("Value is initially set to 0\n");
  printf("Going to greate 5 threads which each increment val by 250\n");
  
  pthread_t threads[5];
  
  pthread_create(&threads[0], NULL, increment,NULL);
  pthread_create(&threads[1], NULL, increment,NULL);
  pthread_create(&threads[2], NULL, increment,NULL);
  pthread_create(&threads[3], NULL, increment,NULL);
  pthread_create(&threads[4], NULL, increment,NULL);
    
  pthread_join(threads[0],NULL);
  pthread_join(threads[1],NULL);
  pthread_join(threads[2],NULL);
  pthread_join(threads[3],NULL);
  pthread_join(threads[4],NULL);

  printf("Expected value of val is 1250\n");
  printf("Actual value of val is: %d\n", val);
}

void increment(){
  for(int i = 0; i < 250; i ++){
    val ++;
  }
  pthread_exit(NULL);
}