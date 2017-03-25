//This gives killed. Good enough


#include <stdio.h>
#include <stdlib.h>

#define NUM 1000000
int main(){
  printf("Making %d allocations\n", NUM);
  void * array[NUM];

  for(int i = 0; i < NUM; i ++){
    array[i] = (void *)malloc(20240000);
  }
  printf("Sleeping\n");
  sleep(5);

  return 0;
}
