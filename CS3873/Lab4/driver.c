#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


//I'll just get this started working on some input. Then modify the driver to
//read from a file
int main(int argc, char ** argv){

  //Stores and initalizes words singularly
  char * encodedText[argc - 1];
  for(int i = 1; i < argc; i ++){
    encodedText[i-1] = malloc(sizeof(char)*(strlen(argv[i]) + 1));
    strcpy(encodedText[i-1],argv[i]);
  }

  //stores the IC value of the string
  double IC = vIC(encodedText, argc - 1);

  //Puts the words into a single continuous string and uppercase
  char * textString = toTextString(encodedText, argc - 1);
  char * textUpper = toUpper(textString);

  //Divides cyphertext into d sub-blocks
  int d = 6;
  int numSBlock = strlen(textUpper) / d;
  char * subBlocks[numSBlock];
  for(int i = 0; i < d; i ++){
    subBlocks[i] = &textUpper[i * d];
    printf("%s\n", subBlocks[i]);
  }

  //Values of plain english letter frequencies
  float plainFreqs[26] = {0.078,0.013,0.029,0.041,0.131,0.029,0.014,0.059,
    0.068,0.002,0.004,0.036,0.026,0.073,0.082,0.022,0.001,0.066,0.065,0.09,
    0.028,0.01,0.015,0.003,0.015,0.001};

  //waiting for the cyphertext to finish this
  float cypherFreqs[26];
  for(int i = 0; i < 26; i ++){
    cypherFreqs[i] = 0;
  }

  return 0;
}
