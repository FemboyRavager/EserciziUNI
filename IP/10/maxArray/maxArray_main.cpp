#include "maxArray_funct.h"
#include <iostream>
using namespace std;
int main() {

  int max;
  const int size1 = 4;
  int arr1[size1] = {0, 1, 2, 3};

  const int size2 = 10;
  int arr2[size2] = {0, 1, 2, 3, 2, 1, 0, 5, 9, 56};

  const int size3 = 0;
  int arr3[size3] = {};

  const int size4 = 4;
  int arr4[size4] = {-8, -1, -56, -3};
  try {
    max = maxArray(arr1, size1);
    cout << "Il valore massimo in {";
    for (int i = 0; i < size1; i++) {
      cout << arr1[i] << (i != size1 - 1 ? "," : "}");
    }
    cout << " e' " << max << endl;
  } catch (string &err) {
    cout << err;
  }
  try {
    max = maxArray(arr2, size2);
    cout << "Il valore massimo in {";
    for (int i = 0; i < size2; i++) {
      cout << arr2[i] << (i != size2 - 1 ? "," : "}");
    }
    cout << " e' " << max << endl;
  } catch (string &err) {
    cout << err;
  }
  try {
    max = maxArray(arr3, size3);
    cout << "Il valore massimo in {";
    for (int i = 0; i < size3; i++) {
      cout << arr3[i] << (i != size3 - 1 ? "," : "}");
    }
    cout << " e' " << max << endl;
  } catch (string &err) {
    cout << err;
  }
  try {
    max = maxArray(arr4, size4);
    cout << "Il valore massimo in {";
    for (int i = 0; i < size4; i++) {
      cout << arr4[i] << (i != size4 - 1 ? "," : "}");
    }
    cout << " e' " << max << endl;
  } catch (string &err) {
    cout << err;
  }
}
