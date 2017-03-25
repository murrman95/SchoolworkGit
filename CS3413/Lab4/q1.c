//Alright so the amount of free memory dropped while the program was running
//but it was recovered after the program was released

#include <stdio.h>
#include <stdlib.h>

#define NUM 100000
int main(){
  int num;
  //printf("How many allocations of memory would you like to make?\n");
  //scanf("%d", &num);

  //Creates an array of void pointers
  printf("Making %d allocations\n", NUM);
  void * array[NUM];

  for(int i = 0; i < NUM/2; i ++){
    array[i] = (void *)malloc(1024);
  }
  printf("Sleeping\n");
  sleep(5);
  for(int i = NUM/2; i < NUM; i ++){
    array[i] = (void *)malloc(1024);
  }
  return 0;
}
