#ifndef _VGFUNC_H_
#define _VHFUNC_H_

//Calulates the index of coincidence.
double vIC(char ** words, int numWords);
//Returns the ciphertext as one big string
char * toTextString(char ** words, int numWords);
//Returns an uppercase version of a string
char * toUpper(char * string);
#endif
