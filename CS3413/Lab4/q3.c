//Yes, I do see memory being reallocated again. Run the program and see

#include <stdio.h>
#include <stdlib.h>

#define NUM 10
int main(){
  printf("Making %d allocations\n", NUM);
  void * array[NUM];

  for(int i = 0; i < NUM; i ++){
    array[i] = (void *)malloc(1024);
    printf("block %d is located at %d\n", i, (int)array[i]);
  }

  for(int i = 0; i < NUM/2; i ++){
    free(array[i]);
    array[i] = (void *)malloc(1024);
    printf("block %d now is located at %d\n", i, (int)array[i]);
  }
  return 0;
}
