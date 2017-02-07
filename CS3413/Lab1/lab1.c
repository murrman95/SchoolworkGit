#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

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
    }
    else{
      printf("Parent Output: \n");
      printf("This is my parent process, my ID is: %d\n", getpid());
      printf("The calue of the integer in the parent process is: %d\n\n", var);
    }
  }
}
