#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define RESOURCES 10;
int available_resources = RESOURCES;
pthread_mutex_t m1;

int request_resources(int rNum);
int release_resources(int rNum);
void process_manager();

int main(){

   pthread_t threads[5];
   pthread_mutex_init(&m1, NULL);

   for(int i = 0; i < 5; i ++){
      pthread_create(&threads[i], NULL, process_manager, NULL);
   }

   for(int j = 0; j < 5; j ++){
      pthread_join(threads[j], NULL);
   }
   pthread_mutex_destroy(&m1);
   return 0;
}

int request_resources(int rNum){
   if(available_resources >= rNum){
      pthread_mutex_lock(&m1);
      available_resources = available_resources - rNum;
      pthread_mutex_unlock(&m1);
      return rNum;
   }
   else{
      return -1;
   }
}

int release_resources(int rNum){
   pthread_mutex_lock(&m1);
   available_resources = available_resources + rNum;
   pthread_mutex_unlock(&m1);
   return rNum;
}

void process_manager(){
   srand(time(NULL));
   int resources = request_resources((rand() % 5) + 1);
   if(resources > 0){
      printf("Process was allocated %d resources\n", resources);
      sleep(rand() % 3);
      int rResources = release_resources(resources);
      printf("%d resources were released\n", rResources);
   }
   else{
      printf("Resources request was denied\n");
   }
   pthread_exit(NULL);
}
