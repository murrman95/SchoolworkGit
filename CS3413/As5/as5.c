#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <time.h>

#define NUMTHREADS 10

int threadCounter = 0;
int heapsize;
pthread_t threads[NUMTHREADS];
sem_t lockFree;
sem_t lockAllocated;
sem_t counterL;



typedef struct list{
  int id;
  int start;
  int end;
  struct list *next;
} List;

List * freeP;
List * allocated;

void allocator();
int allocate(int id, int numBytes);
void addAList(List * newNode);
void release(int id);
int main(int argc,char ** argv){

  //You done goofed
  if(argc != 2){
    printf("Please enter the size of the heap in the command line\n");
    return 1;
  }

  srand(time(NULL));

  sem_init(&lockFree,0,1);
  sem_init(&lockAllocated,0,1);
  sem_init(&counterL,0,1);

  heapsize = atoi(argv[1]);
  freeP = malloc(sizeof(struct list));
  freeP -> id = 0;
  freeP -> start = 0;
  freeP -> end = heapsize;
  freeP -> next = NULL;

  for(int i = 0; i < NUMTHREADS; i ++){
    pthread_create(&threads[i],NULL,allocator,NULL);
  }

  for(int i = 0; i < NUMTHREADS; i ++){
    pthread_join(threads[i],NULL);
  }

  //deleteList(freeP);
  //deleteList(allocated);
  return 0;
}

void printLists(){

  sem_wait(&lockAllocated);
  printf("Allocated Memory:\nID\t\tSize\t\tStartAddress\t\tEndAddress\n");
  List * head = allocated;
  while(head != NULL){
    printf("%d\t\t%d\t\t%d\t\t%d\n",head->id,(head->end - head->start)
                                  ,head->start,head->end);
    head = head -> next;
  }
  sem_post(&lockAllocated);

  sem_wait(&lockFree);
  printf("Free Memory:\nID\t\tSize\t\tStartAddress\t\tEndAddress\n");
  List * head2 = freeP;
  while(head2 != NULL){
    printf("%d\t\t%d\t\t%d\t\t%d\n",head2->id,(head2->end - head2->start)
                                  ,head2->start,head2->end);
    head2 = head2 -> next;
  }
  sem_post(&lockFree);
}

void release(int id){
  sem_wait(&lockAllocated);
  List * head = allocated;
  int Nstart;
  int Nend;

  //First in the list is released
  if(head -> id == id){
    Nstart = head -> start;
    Nend = head -> end;
    allocated = head->next;
    free(head);
  }
  else{
    while(head -> next != NULL){
      if(head -> next -> id == id){
        break;
      }
      head = head -> next;
    }
    List * temp = head -> next;
    Nstart = temp -> start;
    Nend = temp -> end;
    head -> next = temp -> next;
    free(temp);
  }
  sem_post(&lockAllocated);

  //Now time to fix the FreeMemery list
  sem_wait(&lockFree);
  List * freeH = freeP;

  if(freeH == NULL){
    List * newNode = malloc(sizeof(struct list));
    newNode -> id = 0;
    newNode -> start = Nstart;
    newNode -> end = Nend;
    newNode -> next = NULL;
    freeP = newNode;
  }

  //There are nodes to take care of B^)
  else{
    while(freeH != NULL){
      //if(freeH -> start > Nend){
      //  List newNode =
      //}
      if(freeH -> end == Nstart){
        if(freeH -> next != NULL){
          if(freeH -> next -> start == Nend){
            List * temp = freeH -> next;
            freeH -> next = temp -> next;
            freeH -> end = temp -> end;
            free(temp);
          }
        }
        freeH -> end = Nend;
      }
      else{
        freeH = freeH -> next;
      }
    }
  }
  sem_post(&lockFree);
}

void addAList(List * newNode){
  sem_wait(&lockAllocated);
  List * temp = newNode;

  //If the list is empty
  if(allocated == NULL){
    allocated = temp;
  }
  else{
    List * head = allocated;

    //If the new node goes before the first element in the list
    if(head -> start > temp -> end){
      temp -> next = head;
      allocated = temp;
    }

    //Traverses the list untill it is appropiate to instert
    else{
      while(head -> next != NULL){
        if(head -> next -> start > temp -> end){
          break;
        }
        else{
          head = head -> next;
        }
      }
      temp -> next = head -> next;
      head -> next = temp;
    }
  }
  sem_post(&lockAllocated);
}

//This is the helper function I guess for the Allocator
int allocate(int id, int numBytes){
  sem_wait(&lockFree);
  List * head = freeP;
  while(head != NULL){
    int start = head->start;
    int end = head->end;
    if(numBytes <= (end - start)){
      List * newNode = malloc(sizeof(struct list));
      newNode -> start = start;
      newNode -> end = start + numBytes;
      newNode -> id = id;
      newNode -> next = NULL;
      addAList(newNode);
      sem_post(&lockFree);
      head->start = head->start + numBytes;
      return 0;
    }
    head = head->next;
  }
  sem_post(&lockFree);
  return 1;
}

void allocator(){
  int id;
  sem_wait(&counterL);
  threadCounter ++;
  id = threadCounter;
  sem_post(&counterL);

  int sizeRequest = rand() % heapsize;
  if(allocate(id,sizeRequest) == 0){
    sleep(rand() % 10);
    printLists();
    release(id);
    pthread_exit(NULL);
  }
  else{
    printf("Memory could not be allocated for process %d, size %d\n"
            ,id ,sizeRequest);
    pthread_exit(NULL);
  }
}
