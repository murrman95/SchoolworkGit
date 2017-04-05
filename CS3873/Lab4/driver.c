#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define TEXTSIZE 3000
#define ICSIZE 6
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
  ICs[0] = 0;
  ICs[1] = 0.066;
  ICs[2] = 0.052;
  ICs[3] = 0.047;
  ICs[4] = 0.045;
  ICs[5] = 0.044;
  
  int d = findD(ICs, ICSIZE, IC);
  printf("D is: %d\n", d);
  
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
                     

  //For this cipher, the period of the keyword is 3

  int offset[3] = { 0 };
  //records the offsets of each letter;     
  for(int i = 0; i < 26; i ++){
    for(int j = 0; j < 26; j ++){
      for(int k = 0; k < 26; k ++){
        double dummyCounter[26] = { 0 };
        for(int l = 0; l < strlen(string); l ++){
          if(l % 3 == 0){ // gives us an offset of i
            int letter = (int)(((string[l] - 'A') + i) % 26);
            dummyCounter[letter] ++;
          }
          else if(l % 3 == 1){//gives us an offset of j
            int letter = (int)(((string[l] - 'A') + j) % 26);
            dummyCounter[letter] ++;
          }
          else{//gives us an offset of k
            int letter = (int)(((string[l] - 'A') + k) % 26);
            dummyCounter[letter] ++;
          }
        }
        getFreqs(dummyCounter,strlen(string));
        double d1 = faDiff(dummyCounter, plainFreqs);
        double d2 = faDiff(cypherFreqs, plainFreqs);
        if(d1 < d2){
          cpyDArray(cypherFreqs,dummyCounter);
          offset[0] = i;
          offset[1] = j;
          offset[2] = k;
        }
      }
    }
  }
  
  for(int i = 0; i < strlen(string); i ++){
    char c = string[i];
    c -= 'A';
    if(i % 3 == 0){
      c += offset[0];
    }
    else if(i % 3 == 1){
      c += offset[1];
    }
    else{
      c += offset[2];
    }
    c = (c % 26) + 'A';
    string[i] = c;
  }
  
  FILE * fptr;
  fptr = fopen("decipheredText.txt", "w");
  fprintf(fptr,"The deciphered text reads as follows:\n%s", string);
  printf("Check file decipheredText.txt for output\n");
  fclose(fptr);

  return 0;
}
