#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int  min;
int  max;
int  ave;
int *arrayPointer[];

void collatz(int init);
void average_func(void * size);
void min_func(void * size);
void max_func(void * size);

int main(){
  int n;
  /*
   *This is question 2 right here
  */
  int size;
  printf("please input the size of the array\n");
  scanf("%d", &size);
  int array[size];
  printf("Please input the numbers to the array\n");
  for(int i = 0; i < size; i ++){
    int num;
    scanf("%d", &num);
    array[i] = num;
  }

  *arrayPointer = &array[0];

  pthread_t threads[3];
  
  pthread_create(&threads[0], NULL, average_func,(void *)&size);
  pthread_create(&threads[1], NULL, min_func,(void *)&size);
  pthread_create(&threads[2], NULL, max_func,(void *)&size);
  
  pthread_join(threads[0],NULL);
  pthread_join(threads[1],NULL);
  pthread_join(threads[2],NULL);
  
  printf("average of the array is: %d\n", ave);
  printf("minimum value of the array is: %d\n", min);
  printf("maximum value of the array is: %d\n", max);
}

void average_func(void * size){
  int s =*((int*)size);
  int sum = 0;
  for(int i = 0; i < s; i ++){
    sum = sum + arrayPointer[0][i];
  }
  int res = sum/s;
  ave = res;
  pthread_exit(NULL);
}

void min_func(void * size){
  int s =*((int*)size);
  int threadMin = arrayPointer[0][0];
  for(int j = 0; j < s - 1; j ++){
    if(arrayPointer[0][j + 1] < arrayPointer[0][j]){
      threadMin = arrayPointer[0][j + 1];
    }
  }
  min = threadMin;
  pthread_exit(NULL);
}

void max_func(void * size){
  int s =*((int*)size);
  int threadMax = arrayPointer[0][0];
  for(int k = 0; k < s - 1; k ++){
    if(arrayPointer[0][k + 1] > arrayPointer[0][k]){
      threadMax = arrayPointer[0][k + 1];
    }
  }
  max = threadMax;
  pthread_exit(NULL);
}
