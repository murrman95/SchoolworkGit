#ifndef _VGFUNC_H_
#define _VHFUNC_H_

//Calulates the index of coincidence.
double vIC(char * words);
//This method populates the ICs array with IC Values
void getICs(double * array, int size);
//Returns the period of the ciphertext
int findD(double * array, int ICSize, double IC);
//Populates the first aray with frequencies instead of occurances
void getFreqs(double * array, int numLetters);
//Returns the sum of the differences element-wise between the two arrays
double faDiff(double * a1, double * a2);
//Copies the second double array to the first one
void cpyDArray(double * a1, double * a2);
#endif
