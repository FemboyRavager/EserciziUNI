#include "shiftRightArray_funct.h"
#include <iostream>
using namespace std;

int main() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ((i < 9) ? "," : "\n");
  }
  shiftRightArray(array, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << ((i < 9) ? "," : "\n");
  }
}
