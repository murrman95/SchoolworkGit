#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

double vIC(char * words){
  double IC = 0;
  double numLetters = strlen(words);

  char letter[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
                     'O','P','Q','E','S','T','U','V','X','Y','Z'};
  double res = 0;
  for(int i = 0; i < 25; i ++){
    int letterCount = 0;
    for(int j = 0; j < numLetters; j ++){
      if(words[j] == letter[i]){
        letterCount += 1;
      }
    }
    if(letterCount > 0){
      res += letterCount * (letterCount - 1);
    }
  }

  double denominator = (numLetters * (numLetters - 1));
  IC = res / denominator;
  return IC;
}

void getFreqs(double * array, int numLetters){
  for(int i = 0; i < 26; i ++){
    array[i] = array[i] / numLetters;

  }
}

double faDiff(double * a1, double * a2){
  double res = 0;
  for(int i = 0; i < 26; i ++){
    double r = fabs(a1[i] - a2[i]);
    res += r;
  }
  return res;
}

void cpyDArray(double * a1, double * a2){
  for(int i = 0; i < 26; i ++){
    a1[i] = a2[i];
  }
}


void getICs(double * array, int size){
  double num = 1;
  for(int i = 1; i < size; i ++){
    array[i] = ((1/num)*((26-num)/25)*0.066) + (((num-1)/num)*(26/25)*0.038);
    num ++;
    printf("%lf ", array[i]);
  }
  printf("\n");
}

int findD(double * array, int ICSize, double IC){
  double diff = 9999;
  int index = 0;
  for(int i = 1; i < ICSize; i ++){
    double tempDiff = fabs(array[i] - IC);
    if(tempDiff < diff){
      diff = tempDiff;
      index = i;
    }
  }
  return index;
}