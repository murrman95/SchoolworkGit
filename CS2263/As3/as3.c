#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "module.h"

int main(int argc, char * argv[]){
  FILE *f;
  if(argc > 1){
    if((f = fopen(argv[1], "r")) == NULL){
      printf("File failed to open\n");
    }
    else{
      printf("%s\n", argv[1]);
      if(readQueries(f) == true){
        printQueries();
        sortQueries();
        if(argc > 2){
          int nR;
          for(int i = 2; i < argc; i ++){
            printf("Query: %s\n", argv[i]);
            char ** results = allMatches(argv[i], &nR);
            for(int j = 0; j < (nR > 5 ? 5 : nR); j ++){
              printf("%s", results[j]);
            }
            printf("\n");
          }
        }
        fclose(f);
      }
      else{
        printf("Read didn't work\n");
      }
    }
  }
  else{
    printf("please enter a file to open\n");
  }
  return 0;
}
