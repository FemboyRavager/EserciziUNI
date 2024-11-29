#include "printArray_funct.h"
#include <iostream>

using namespace std;

void printArray(int *s, int size) {
  if (size == 0) {
    cout << "Array vuoto\n";
    return;
  } else {
    cout << "I valori contenuti nell'array s tramite puntatore sono: {";
    for (int i = 0; i < size; i++) {
      cout << *s << (i < (size - 1) ? "," : "}\n");
      s++;
    }
  }
}

void printArrayWithIndex(int s[], int size) {
  if (size == 0) {
    cout << "Array vuoto\n";
    return;
  } else {
    cout << "I valori contenuti nell'array s tramite indice sono: {";
    for (int i = 0; i < size; i++) {
      cout << s[i] << (i < (size - 1) ? "," : "}\n");
    }
  }
}
