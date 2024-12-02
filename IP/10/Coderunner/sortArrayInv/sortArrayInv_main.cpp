#include "sortArrayInv_funct.h"
#include <iostream>
using namespace std;

int main() {
  int array[] = {0, 6, 4, 9, 5, 7, 6, 3};
  for (int i = 0; i < 8; i++) {
    cout << array[i] << ((i < 7) ? "," : "\n");
  }
  cout << endl << endl;
  sortArrayInv(array, 8);
  for (int i = 0; i < 8; i++) {
    cout << array[i] << ((i < 7) ? "," : "\n");
  }
}
