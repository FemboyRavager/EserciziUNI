#include "isPresentInArray_funct.h"

bool isPresentInArray(int *t, int size, int x) {
  int *pArr = t;
  for (int i = 0; i < size; i++) {
    // cout << *pArr << endl;
    if (*pArr == x) {
      return true;
    }
    pArr++;
  }
  return false;
}


