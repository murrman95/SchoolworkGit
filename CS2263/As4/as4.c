#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void swap(int a[], int i1, int i2);
int kmed(int a[], int start, int end, int k);
void sort(int a[], int size);
int main(){
  srand(time(NULL));
  int unsortedArray[SIZE];
  int kmedArray[SIZE];
  int sortArray[SIZE];

  int med = SIZE/2;

  for(int g = 0; g < 100; g ++){
    for(int i = 0; i < SIZE; i ++){
      printf("entering ");
      int num = rand() % 201 - 100;
      unsortedArray[i] = num;
      kmedArray[i] = num;
      sortArray[i] = num;
      printf("exiting \n");
    }

    sort(sortArray,SIZE);
    int kmedVal = kmed(kmedArray,0,SIZE-1,med);

    if(sortArray[med -1] != kmedVal){
      printf("kth-med values do not match. kmed: %d\tsort: %d\n",
            kmedVal,sortArray[med]);

      printf("Unsorted is: ");
      for(int k = 0; k < SIZE; k ++){
        printf("%d ", unsortedArray[k]);
      }
      printf("\n");
    }
    printf("outer loop\n");
  }


  return 0;
}

void swap(int a[], int i1, int i2){
  int temp = a[i2];
  a[i2] = a[i1];
  a[i1] = temp;
}

int kmed(int a[], int start, int end, int k){
  int pivot = a[start];
  int h = start;
  int r = start + 1;
  while(r <= end){
    if(a[r] <= pivot){
      h ++;
      swap(a, r, h);
    }
    r ++;
  }
  swap(a, start, h);
  //Pivot is at point h so L goes from start to h - start
  if(k == h + 1)
    return a[h];
  else if(k > h + 1)
    return kmed(a,h + 1,end,k);
  else
    return kmed(a,start,h,k);
}

void sort(int a[], int size){
  for(int i = 0; i < size; i ++){
    for(int j = size-1; j > i; j --){
      if(a[j] < a[j - 1]){
        swap(a,j,j-1);
      }
    }
  }
}
