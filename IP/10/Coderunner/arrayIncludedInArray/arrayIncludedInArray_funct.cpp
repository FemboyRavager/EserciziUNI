#include "arrayIncludedInArray_funct.h"
bool arrayIncludedInArray(int *t1, int size1, int *t2, int size2) {
  bool currentT1ElementFound=false;
  for (int i=0; i<size1; i++) {
    currentT1ElementFound=false;
    for (int j=0; j<size2; j++) {
      if (*(t1+i) == *(t2+j)) {
        currentT1ElementFound=true;
        break;
      }
    }
    if (!currentT1ElementFound) {
      return false;
    }
  }
  return true;
  //cout << endl;
  /* t1 contenuto in ordine
  for (int i = 0; i < size2; i++) {
    if (*(t2 + i) == *t1) {
      for (int j = i; j < size1; j++) {
        if (*(t2 + j) != *(t1 + j - i)) {
          return false;
        }
      }
    }
  }
  return true;
  */
}
