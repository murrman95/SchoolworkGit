#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int * sortPermute(char ** a, int n);
int compareStrs(const void * s1, const void * s2, void * arg);

int main(){
  const char *words[26];
  int i;
  char c = 'z';
  for(i = 0; i < 26; i ++){
    int j = c - i;
    char * meh = malloc(2*sizeof(char));
    meh[0] = j;
    meh[1] = '\0';
    words[i] = meh;
  }
  for(i = 0; i < 26; i ++){
    printf("%s ,", words[i]);
  }
  printf("\n");
  int * p =  sortPermute(words, 26);
  for(i = 0; i < 26; i ++){
    printf("%d ,", *(p + i));
  }
  printf("\n");
  return 0;
}
int * sortPermute(char ** a, int n){
  int * permute = malloc(n*sizeof(int));
  int i;
  for(i = 0; i < n; i++){
    permute[i] = i;
  }
  qsort_r(permute, n, sizeof(int), &compareStrs, a);
  return permute;
}
int compareStrs(const void * s1, const void * s2, void * arg){
  const int  S1 = *(const int *) s1;
  const int  S2 = *(const int *) s2;

  const char ** words = (const char **) arg;
  return strcmp((words[S1]),(words[S2]));
}
