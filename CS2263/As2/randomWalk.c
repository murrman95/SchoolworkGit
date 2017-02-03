/*
 *Author: Christopher Murray ID: 3108107
 *The purpose of this program is to produce a 26 length random walk on a nxn
 *array where n is provided by the user
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Prints a 2D array
void printArray(char *array[], int bound);

//Applies a random walk to a 2D array
void randomWalk(char *array[], int bound);

//Determines whether or not a position in an array is "locked" (no step can
//proceed from that point)
bool isLocked(char *array[], int x, int y, int bound);

int main(){
  int n;
  printf("Please enter the dimension of the nxn array: \n");
  scanf("%d", &n);
  int n2 = n*n;
  char store[n2];
  char *point[n];

  for(int i = 0; i < n2; i++){
    store[i] = '.';
  }

  int diff = 0;

  while(diff < n){
    point[diff] = &store[diff*n];
    diff++;
  }

  randomWalk(point, n);
  printArray(point, n);
  return 0;
}

void printArray(char *array[], int bound){
  for(int i = 0; i < bound; i ++){
    for(int j = 0; j < bound; j ++){
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }
}

void randomWalk(char *array[], int bound){

  time_t t;
  char letter = 'A';
  srand((unsigned) time(&t));
  int x = 0;
  int y = 0;
  array[x][y] = letter;
  letter ++;
  bool locked = isLocked(array, x, y, bound);
  while(!locked && letter < 'Z' + 1){
    switch (rand() % 4){
      case 0:
        if((x-1) > 0 && array[x-1][y] == '.'){
          x --;
          array[x][y] = letter;
          letter ++;
        }
        break;
      case 1:
        if((x+1) < bound && array[x+1][y] == '.'){
          x ++;
          array[x][y] = letter;
          letter ++;
        }
      break;
      case 2:
        if((y-1) > 0 && array[x][y-1] == '.'){
          y --;
          array[x][y] = letter;
          letter ++;
        }
      break;
      case 3:
        if((y+1) < bound && array[x][y+1] == '.'){
          y ++;
          array[x][y] = letter;
          letter ++;
        }
      break;
    }
    locked = isLocked(array, x, y, bound);
  }
}

bool isLocked(char *array[], int x, int y, int bound){
 bool up = false;
 bool right = false;
 bool down = false;
 bool left = false;

 if(y == 0 || array[x][y-1] != '.'){
   up = true;
 }
 if(y == bound - 1 || array[x][y+1] != '.'){
   down = true;
 }
 if(x == 0 || array[x-1][y] != '.'){
   left = true;
 }
 if(x == bound - 1 || array[x+1][y] != '.'){
   right = true;
 }
 if(up && down && left && right){
   return true;
 }
 else{
   return false;
 }
}
