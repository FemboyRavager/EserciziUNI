#include "allDiffArrayElements_funct.h"
#include <iostream>

using namespace std;

bool allDiffArrayElements(int *t, int size) {
  int *tJ = t;
  int *tI = t;
  cout << endl;
  for (int i = 0; i < size; i++) {
    tJ = t;
    for (int j = 0; j < size; j++) {
      // cout<<"Comparing "<<*tI<<" and "<<*tJ<<"| i: "<<i<<" and j: "<<j<<endl;
      if (i != j && *tJ == *tI) {
        return false;
      }
      tJ++;
    }
    tI++;
  }
  return true;
}
