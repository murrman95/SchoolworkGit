#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

//double countLetters(char * words){
//  double num = 0;
//  for(int i = 0; i < numWords; i ++){
//    int wLen = strlen(words[i]);
//    for(int j = 0; j < wLen; j ++){
//      if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
//        num += 1;
//      }
//
//      if(words[i][j] >= 'a'  && words[i][j] <= 'z'){
//        num += 1;
//      }
//    }
//  }
//  return num;
//}

//Calculates the Index of Coincidence in this code. Used for calculating the
//length of the keyword used in "seeding" the cypher.
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

/*char * toTextString(char ** words, int numWords){
  int numLetters = (int)countLetters(words,numWords);
  char * string = malloc(sizeof(char) * (numLetters + 1));
  int sCounter = 0;
  for(int i = 0; i < numWords; i ++){
    int wLen = strlen(words[i]);
    for(int j = 0; j < wLen; j ++){
      if(words[i][j] >= 'a' && words[i][j] <= 'z'){
        string[sCounter] = words[i][j];
        sCounter ++;
      }
      if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
        string[sCounter] = words[i][j];
        sCounter ++;
      }
    }
  }
  string[numLetters] = '\0';
  return string;
}*/

/*char * toupper(char * string){
  char * res = malloc(sizeof(char) * (strlen(string) + 1));

  for(int i = 0; i < strlen(string); i ++){
    if(string[i] >= 'a' && string[i] <= 'z'){
      res[i] = string[i] + ('A' - 'a');
    }
    else{
      res[i] = string[i];
    }
  }
  res[strlen(string)] = '\0';
  return res;
}*/

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
//This is if I want to trim input to not inlude punctuation.
/*
void wordsOnly(char ** words, int numWords){
  for(int i = 0; i < numWords; i ++){
    int wLen = strlen(words[i]);
    for(int j = 0; j < wLen; j ++){
      if(word[i][j] >= 'A' && word[i][j] <= 'Z'){
        word[i][j] = tolower(word[i][j]);
      }

 if(word[i][j] < 'a'  && word[i][j] > 'z'){
        strcpy(&word[i][j], &word[i][j+1]){
          wLen --;
        }
      }
    }
  }
}*/
