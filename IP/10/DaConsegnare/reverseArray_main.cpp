#include "reverseArray_funct.h"
#include <iostream>
using namespace std;

int main() {
  const int N1 = 5;
  const int N2 = 1;

  int sourceArray1[N1] = {1, 2, 3, 4, 5};
  int destArray1[N1] = {0, 0, 0, 0, 0};

  int sourceArray2[N2] = {5};
  int destArray2[N1] = {0, 0, 0, 0, 0};

  cout << "Source 1: ";
  printArray(sourceArray1, N1);
  cout << "Dest 1: ";
  printArray(destArray1, N1);

  try {
    reverseArray(sourceArray1, destArray1, N1);
  } catch (string &err) {
    cout << err;
  }
  cout << "Source 1: ";
  printArray(sourceArray1, N1);
  cout << "Dest 1: ";
  printArray(destArray1, N1);

  cout << "--------------------" << endl;
  cout << "Source 2: ";
  printArray(sourceArray2, N2);
  cout << "Dest 2: ";
  printArray(destArray2, N2);

  try {
    reverseArray(sourceArray2, destArray2, N2);
  } catch (string &err) {
    cout << err;
  }
  cout << "Source 2: ";
  printArray(sourceArray2, N2);
  cout << "Dest 2: ";
  printArray(destArray2, N2);

  cout << "--------------------" << endl;

  cout << "Mando stesso array:\n";
  try {
    reverseArray(sourceArray2, sourceArray2, N2);
  } catch (string &err) {
    cout << err;
  };
}
