#include <iostream>
#include "printArray_funct.h"

using namespace std;

int main() {
  const int N=6;
  int arr1[N]={1,3,4,9,4,6};
  printArray(arr1, N);
  printArrayWithIndex(arr1, N);
  cout<<endl;

  int arr2[]={5};
  int size2=1;
  printArray(arr2, size2);
  printArrayWithIndex(arr2, size2);
  cout<<endl;

  int arr3[]={};
  int size3=0;
  printArray(arr3, size3);
  printArrayWithIndex(arr3, size3);
  cout<<endl;
}
