#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int * min;
int * max;
int * ave;
int *arrayPointer[];

void collatz(int init);
void average_func(void * size);
void min_func();
void max_func();

int main(){
  int n;
  /*
   * This is question 1 right here
  */
  printf("Please insert a number to seed the collatz conjecture\n");
  if(scanf("%d", &n) == 1 && n > 0){
    collatz(n);
  }
  else{
    printf("please insert a positive number\n");
  }
}

void collatz(int init){
  pid_t childPID;
  int n = init;

  childPID = fork();
  if(childPID == 0){
    printf("%d, ", n);
    while (n != 1){
      if(n % 2 == 0){
        n /= 2;
        printf("%d, ", n);
      }
      else{
        n = (3*n) + 1;
        printf("%d, ", n);
      }
    }
    printf("\n");
  }
  else{
    wait();
      /*
       *This is question 2 right here
      */
      int size;
      printf("Please enter the size of array you will pass numbers into\n");
      scanf("%d", &size);
      int array[size];
      for(int i = 0; i < size; i ++){
        int num;
        scanf("%d", &num);
        array[i] = num;
      }

      printf("Setting up arrayPointer\n");
      *arrayPointer = &array[0];
      for(int i = 0; i < size; i++){
        printf("%d\n", arrayPointer[0][i]);
      }

      printf("creating pthread\n");
      pthread_t mythread;
      pthread_create(&mythread, NULL, &average_func,(void *)&size);
      pthread_join(mythread,NULL);
      printf("average is: %d\n", *ave);
  }
}

void average_func(void * size){
  printf("Inside pthread func\n");
  int s =*((int*)size);
  int sum = 0;
  printf("starting to calculate sum\n");
  for(int i = 0; i < s; i ++){
    printf("%d, ", arrayPointer[0][i]);
    sum = sum + arrayPointer[0][i];
  }
  printf("calculated the sum\n");
  printf("%d\n", s);
  int res = sum/s;
  printf("res is: %d address is: %d\n", res, &res);
  ave = &res;
  printf("ave is %d address is: %d\n", *ave, ave);
  pthread_exit(NULL);
}
