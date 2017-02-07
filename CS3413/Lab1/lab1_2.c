#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void printStuff(){
  printf("Hey this is a thread! My ID is: %d\n", pthread_self());
  pthread_exit(NULL);
}

int main(){
  pid_t childPID;
  int var = 7;

  childPID = fork();
  if(childPID >= 0){ //fork was successful
    if(childPID == 0){
      printf("Child Output:\n");
      printf("This is my child process, my ID is: %d\n", getpid());
      var ++;
      printf("The calue of the integer in the child process is: %d\n\n", var);

      pthread_t mythread;
      pthread_create(&mythread, NULL, &printStuff, NULL);
      pthread_join(mythread,NULL);
    }
    else{
      printf("Parent Output: \n");
      printf("This is my parent process, my ID is: %d\n", getpid());
      printf("The calue of the integer in the parent process is: %d\n\n", var);
    }
  }
}
