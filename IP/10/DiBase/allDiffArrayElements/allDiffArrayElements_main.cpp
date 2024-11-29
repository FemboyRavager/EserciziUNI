#include "allDiffArrayElements_funct.h"
#include <iostream>

using namespace std;

int main() {
  const int N = 5;
  int arr1[N] = {0, 1, 2, 3, 5};
  int arr2[N] = {0, 1, 2, 3, 1};

  int *arrPrime[N] = {arr1, arr2};
  for (int i = 0; i < 2; i++) {
    cout << "Array: {";
    for (int j = 0; j < N; j++) {
      cout << arrPrime[i][j] << (j < (N - 1) ? "," : "}");
    }
    cout << (allDiffArrayElements(arrPrime[i], N)
                 ? "Tutti gli elementi sono diversi\n\n"
                 : "Ci sono almeno due elementi uguali\n\n");
  }
}
