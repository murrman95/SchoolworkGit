#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie{
  char c;
  int key;
  struct trie *next;
  struct trie *child;
} Trie_T, *Trie_Pt;

Trie_PT t;

int main(int argc, char ** argv){
  if(argc < 2){
    printf("needs a filename\n");
    return 0;
  }
  File *f;
  f = fopen(argv[1], "r");
  int rating;
  char * string = malloc(sizeof(char) * 200);
  while(fscanf(fptr, "%d", &rating) == 1){
    fgetc(fptr);
    fgets(string, 200, f);
    processReview(t,rating, string);
  }
  fclose(f);
  
  return 0;
}