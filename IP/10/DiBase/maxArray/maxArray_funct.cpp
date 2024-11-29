#include <iostream>
#include "maxArray_funct.h"
using namespace std;

int maxArray(int *array, int size) {
  if (size==0) {
    string child="Array di dimensioni 0\n";
    throw child;
  }
  int* p=array; 
  int maxN=*p;  //maxN = array[0]
  for (int i=0; i<size; i++) {  //comincio da i=1 siccome maxN inizializzato a [0]
    if (*p > maxN) {
      maxN=*p;
    }
    p++;
  }
  return maxN;
}
