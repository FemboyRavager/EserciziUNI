#include "arrayIncludedInArray_funct.h"
#include <iostream>
using namespace std;

int main() {
  int a[] = {0, 2, 13};
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << (arrayIncludedInArray(a, 3, b, 10) ? "Contenuto\n" : "Non contenuto\n");
}
