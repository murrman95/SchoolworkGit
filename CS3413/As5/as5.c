#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <time.h>

pthread_t threads[10];

typedef struct list{
  int id;
  int start;
  int end;
  stuct list *next;
} List;

void allocator();
void allocate(int id, int numBytes);
void release(int id);
int heapSize;

int main(int argc,char ** argv){
  if(argc != 2){
    printf("Please enter the size of the heap in the command line\n");
    return 1;
  }

  heapSize = atoi(argv[1]);
  List * freeP = malloc(sizeof(struct list));
  freeP -> start = 0;
  freeP -> end = heapsize;


}
