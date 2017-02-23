#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_LENGTH = 100;

char **queries;
unsigned long *weights;
int *permute;
int nQ;
char ** allMatches(char *prefix, int *nR);
void swapWeights(int i1, int i2);
void swapQueries(int i1, int i2);

void swapQueries(int i1, int i2){
  char * temp = queries[i2];
  queries[i2] = queries[i1];
  queries[i1] = temp;
}

void swapWeights(int i1, int i2){
  unsigned long temp = weights[i2];
  weights[i2] = weights[i1];
  weights[i1] = temp;
}

int compareWeights(const void * s1, const void * s2){
  const int S1 = *(const int *)s1;
  const int S2 = *(const int *)s2;

  if(weights[S1] > weights[S2]){

    return -1;
  }
  else if(weights[S1] < weights[S2]){
    swapWeights(S1, S2);
    return 1;
  }
  else{
    return 0;
  }
}

char ** allMatches(char *prefix, int * nR){
  int min = 0;
  int max = 0;
  int lower = 0;
  int upper = nQ;
  int mid = (lower + upper) / 2;
  while(upper >  lower){
    if(strncmp(queries[permute[mid]], prefix, strlen(prefix)) == 0){
      min = mid;

      //All of this is to find the lower bound
      int bLower = lower;
      int bUpper = mid;
      int bMid = (bLower + bUpper) / 2;
      while(bUpper > bLower){
        if(strncmp(queries[permute[bMid]], prefix, strlen(prefix)) < 0){
          bLower = bMid + 1;
          min = bLower;
          bMid = (bLower + bUpper) / 2;
        }
        else{
          bUpper = bMid;
          bMid = (bUpper + bLower) / 2;
        }
      }

      //Now trying to find the upper bound
      lower = mid + 1;
      mid = (lower + upper) / 2;
      while(upper > lower){
        if(strncmp(queries[permute[mid]], prefix, strlen(prefix)) > 0){
          upper = mid;
          mid = (lower + upper) / 2;
        }
        else{
          lower = mid + 1;
          mid = (upper + lower) / 2;
          max = lower;
        }
      }
    }
    else if(strncmp(queries[permute[mid]], prefix, strlen(prefix)) > 0){
      upper = mid;
      mid = (upper + lower) / 2;
    }
    else{
      lower = mid + 1;
      mid = (lower + upper) / 2;
    }
  }
  if(min == 0 && max == 0){
    printf("no matches\n");
    *nR = 0;
    return queries;
  }
  else{
    *nR = max - min;
    qsort(&permute[min],*nR, sizeof(int), &compareWeights);
    char ** results = malloc(*nR * sizeof(char*));
    int j = 0;
    for(int i = min; i < max; i ++){
      //printf("%d\t%s", weights[permute[i]], queries[permute[i]]);
      results[j] = malloc(sizeof(char) * strlen(queries[permute[i]]));
      strcpy(results[j], queries[permute[i]]);
      j ++;
    }
    return results;
  }
}

void printQueries(){
  for(int i = 0; i < nQ; i++){
    printf("%lu\t%s", weights[i], queries[i]);
  }
  printf("\n");
}



int compareStrs(const void * s1, const void * s2, void * arg){
  const int S1 = *(const int *)s1;
  const int S2 = *(const int *)s2;

  const char ** words = (const char **)arg;
  return strcmp(words[S1],words[S2]);
}

void sortQueries(){
  permute = malloc(nQ*sizeof(int));
  for(int i = 0; i < nQ; i ++){
    permute[i] = i;
  }
  qsort_r(permute, nQ, sizeof(int), &compareStrs, queries);

}

bool readQueries(FILE *f){
  fscanf(f,"%d", &nQ);
  queries = malloc(nQ*sizeof(char*));
  weights = malloc(nQ*sizeof(unsigned long));
  char* string = malloc(sizeof(char) * 100);
  int i = 0;
  while(i < nQ){

    fscanf(f,"%lu", (weights + i));
    fgetc(f);
    fgets(string, 100, f);
    string[strlen(string)+1] = '\0';
    queries[i] = malloc(sizeof(char) * strlen(string) + 1);
    strcpy(queries[i], string);
    i ++;
  }
  return true;
}
