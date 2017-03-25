//My program returns that the average distance between blocks of data address
//1039 bytes which is a bit more than the size of the blocks themselves


#include <stdio.h>
#include <stdlib.h>

#define NUM 100000
int main(){
  printf("Making %d allocations\n", NUM);

  int total = 0;

  void * array[NUM];
  array[0] = (void *)malloc(1024);

  for(int i = 1; i < NUM; i ++){
    array[i] = (void *)malloc(1024);
    total += (int)array[i] - (int)array[i-1];
  }
  int avg = total/NUM;
  printf("avg difference in address is %d\n", avg);

  return 0;
}
