#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

double countLetters(char ** words, int numWords){
  double num = 0;
  for(int i = 0; i < numWords; i ++){
    int wLen = strlen(words[i]);
    for(int j = 0; j < wLen; j ++){
      if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
        num += 1;
      }

      if(words[i][j] >= 'a'  && words[i][j] <= 'z'){
        num += 1;
      }
    }
  }
  return num;
}

//Calculates the Index of Coincidence in this code. Used for calculating the
//length of the keyword used in "seeding" the cypher.
double vIC(char ** words, int numWords){
  double IC = 0;
  double numLetters = countLetters(words,numWords);

  char letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                     'o','p','q','r','s','t','u','v','x','y','z'};
  double res = 0;
  for(int i = 0; i < 25; i ++){
    int letterCount = 0;
    for(int j = 0; j < numWords; j ++){
      int wLen = strlen(words[j]);
      for(int k = 0; k < wLen; k ++){
        if(words[j][k] == letter[i] || words[j][k] == toupper(letter[i])){
          letterCount += 1;
        }
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

char * toTextString(char ** words, int numWords){
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
}

char * toUpper(char * string){
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
