#include "reverseArray_funct.h"
#include <iostream>
using namespace std;

void reverseArray(int *source, int *dest, int size) {
  if (source == dest) {
    string child = "Stesso array passato come source e dest\n";
    throw child;
  }
  for (int i = 0; i < size; i++) {
    *(dest + (size - i - 1)) = *(source + i);
    // dest[size - i - 1] = source[i];
  }
  cout << "\nFunzione:";
  cout << "\n\tElementi in array source:\t";
  for (int i = 0; i < size; i++) {
    cout << *(source + i) << " ";
  }
  cout << "\n\tElementi in array dest:\t\t";
  for (int i = 0; i < size; i++) {
    cout << *(dest + i) << " ";
  }
  cout << "\nFine funzione";
  cout << endl << endl;
}

void printArray(int *s, int size) {
  if (size == 0) {
    cout << "Array vuoto\n";
    return;
  } else {
    cout << "{";
    for (int i = 0; i < size; i++) {
      cout << *s << (i < (size - 1) ? "," : "}\n");
      s++;
    }
  }
}
