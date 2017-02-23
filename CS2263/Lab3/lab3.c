#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void printGrid(int ** grid, int rSize, int cSize);
int countFilled(int ** grid, int rSize, int cSize);
int countBlob(int ** grid, int rCoord, int cCoord, int rSize, int cSize);

int main(int argc, char ** argv){
  if(argc != 3){
    printf("Please enter dimensions of grid\n");
  }
  else{
    int rSize = atoi(argv[1]);
    int cSize = atoi(argv[2]);
    printf("rSize is: %d, cSize is: %d\n", rSize, cSize);
    int * array =  malloc(sizeof(int)*rSize*cSize);
    int ** pArray = malloc(sizeof(int*)*rSize);

    //Setting up rand() seeds
    srand(time(NULL));

    //Filling array
    for(int k = 0; k < (cSize * rSize); k ++){
      array[k] = (rand() % 3) % 2; //Grid was getting too populated
    }
    int j = 0;

    //Setting up pointer array
    for(int i = 0; i < rSize; i ++){
      pArray[i] = &array[cSize*j];
      j ++;
    }
    printGrid(pArray, rSize, cSize);
    printf("enter coordinate i,j (non-integer to quit): ");
    int r = 0;
    int c = 0;
    while(scanf("%d,%d", &r, &c) == 2){
      int bSize = countBlob(pArray, r, c, rSize, cSize);
      int fSize = countFilled(pArray, rSize, cSize) ;
      int percent = ((bSize * 100)/fSize);
      printf("Blob size: %d (%d %% of all 1's)\n", bSize, percent);
      printf("enter coordinate i,j (non-integer to quit): ");
    }
    free(array);
    free(pArray);
  }
  return 0;
}

void printGrid(int ** grid, int rSize, int cSize){
  for(int i = 0; i < rSize; i ++){
    for(int j = 0; j < cSize; j ++){
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int countFilled(int ** grid, int rSize, int cSize){
  int filled = 0;
  for(int i = 0; i < rSize; i ++){
    for(int j = 0; j < cSize; j ++){
      if(grid[i][j] > 0){
        filled ++;
        if(grid[i][j] == 2){
          grid[i][j] = 1;
        }
      }
    }
  }
  return filled;
}

int countBlob(int ** grid, int rCoord, int cCoord, int rSize, int cSize){
  int acc;

  //For the orininal call if it tries bad input
  if(rCoord < 0 || rCoord >= rSize ||
    cCoord < 0 || cCoord >= cSize ||
    grid[rCoord][cCoord] == 0){
    acc = 0;
  }
  else{
    acc = 1;

    //marking visited spot
    grid[rCoord][cCoord] = 2;

    //Incrementing indices with loops and I regret it because of readability
    for(int i = -1; i < 2; i ++){
      for(int j = -1; j < 2; j ++){

        //This is a gross block of tests and I'm sorry
        if(rCoord + i >= 0 && cCoord + j >= 0 &&
        rCoord + i < rSize && cCoord + j < cSize){
          if(grid[rCoord + i][cCoord + j] == 1 &&
          !(i == 0 && j == 0)){

            acc += countBlob(grid, rCoord+i, cCoord+j, rSize, cSize);
          }
        }
      }
    }
  }
  return acc;
}
