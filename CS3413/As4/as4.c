#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>

#define NUMTHREADS 1000

void *mCarlo(void * arg);

int pointsCreated = 0;
int numHits = 0;
sem_t makingPoints;
sem_t hit;
pthread_t threads[NUMTHREADS];

typedef struct coord{
   float x;
   float y;
} Coord, *PCoord;

int main(){
   srand(time(NULL));
   printf("Hi\n");
   sem_init(&makingPoints,0,1);
   sem_init(&hit,0,1);


   for(int i = 0; i < NUMTHREADS; i ++){
      float xC = (rand() % 10000) ;
      float yC = (rand() % 10000) ;
      xC = xC / 10000;
      yC = yC / 10000;
      PCoord c = malloc(sizeof(Coord));
      c -> x = xC;
      c -> y = yC;
      pthread_create(&threads[i],NULL,mCarlo,(void*)c);
   }

   for(int j = 0;  j < NUMTHREADS; j ++){
      pthread_join(threads[j],NULL);
   }

   printf("Numhits: %d\tNumCreated: %d\n", numHits, pointsCreated);
   float pi = 4 *((float) numHits) / ((float)pointsCreated);

   printf("Pi was approximated to be: %f\n", pi);

   sem_destroy(&hit);
   sem_destroy(&makingPoints);

   return 0;
}

void *mCarlo(void * arg){
   Coord coordinate = *(PCoord)arg;
   float xC = coordinate.x;
   float yC = coordinate.y;
   if((xC*xC + yC*yC) <= 1){
      sem_wait(&hit);
      numHits ++;
      sem_post(&hit);
   }
   sem_wait(&makingPoints);
   pointsCreated ++;
   sem_post(&makingPoints);
}
