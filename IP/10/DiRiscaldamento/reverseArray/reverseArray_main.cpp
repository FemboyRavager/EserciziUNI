#include "reverseArray_funct.h"
#include <iostream>
using namespace std;

int main() {
  const int N = 5;
  int sourceArray[N] = {1, 2, 3, 4, 5};
  int destArray[N] = {0, 0, 0, 0, 0};
  cout<<"Source: ";
  printArray(sourceArray, N);
  cout<<"Dest: ";
  printArray(destArray, N);
  
  try {
    reverseArray(sourceArray, destArray, N);
  } catch (string &err) {
    cout << err;
  }
  cout<<"Source: ";
  printArray(sourceArray, N);
  cout<<"Dest: ";
  printArray(destArray, N);

}
