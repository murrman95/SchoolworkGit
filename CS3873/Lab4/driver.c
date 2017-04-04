#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define TEXTSIZE 3000
#define ICSIZE 20
//I'll just get this started working on some input. Then modify the driver to
//read from a file
int main(int argc, char ** argv){

  //FIle name is to be handed in throught the command line
  if(argc != 2){
    printf("Hey enter the text file of the vignere text in the command line\n");
    return 0;
  }
  FILE * f;
  f = fopen(argv[1], "r");
  char * string = malloc(sizeof(char) * TEXTSIZE);
  //char * s;
  fscanf(f,"%s", string);
  //strcpy(string, s);
  double IC = vIC(string);
  printf("%lf\n", IC);

  //Need to make table of IC vlaues to compare with
  double * ICs = malloc(sizeof(double) * ICSIZE);
  getICs(ICs,ICSIZE);
  
  int d = findD(ICs, ICSIZE, IC);
  printf("D is: %d\n", d);
  //Divides cyphertext into d sub-blocks
  int numSBlock = strlen(string) / d;
  printf("Strlen is: %d, numBlocks is: %d\n", strlen(string), numSBlock);
  
  char * subBlocks[numSBlock];
  for(int i = 0; i < numSBlock; i ++){
    subBlocks[i] = &string[i * d];
    //printf("%s\n", subBlocks[i]);
  }

  //Values of plain english letter frequencies
  double plainFreqs[26] = {0.078,0.013,0.029,0.041,0.131,0.029,0.014,0.059,
    0.068,0.002,0.004,0.036,0.026,0.073,0.082,0.022,0.001,0.066,0.065,0.09,
    0.028,0.01,0.015,0.003,0.015,0.001};

  //waiting for the cyphertext to finish this
  double cypherFreqs[26];
  for(int i = 0; i < 26; i ++){
    cypherFreqs[i] = 0;
  }
  
  char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
                     'O','P','Q','E','S','T','U','V','X','Y','Z'};
      
  //records the offsets of each letter;    
  int offset[3] = { 0 };
  for(int i = 0; i < d; i ++){
    for(int j = 0; j < 26; j ++){
      double dummyCounter[26] = { 0 };
      for(int k = 0; k < numSBlock; k ++){
        if(subBlocks[k][i] != NULL){
          char letter = (((subBlocks[k][i] - 'A') + j) % 26) + 'A';
          dummyCounter[(int)(letter - 'A')] ++;
        }
      }
      getFreqs(dummyCounter,strlen(string)/3);
      double d1 = faDiff(dummyCounter, plainFreqs);
      double d2 = faDiff(cypherFreqs, plainFreqs);
      if(d1 < d2){
        cpyDArray(cypherFreqs,dummyCounter);
        offset[i] = j;
      }
    }
  }
  
  for(int i = 0; i < d; i ++){
    printf("Offset %d is %d\n", i, offset[i]);
  }

  return 0;
}
