#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


void collatz(int init);

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
  }
}
