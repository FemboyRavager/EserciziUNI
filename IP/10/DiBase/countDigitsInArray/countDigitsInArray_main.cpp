#include "countDigitsInArray_funct.h"
#include <iostream>
using namespace std;

int main() {
  const int N = 5;

  char array1[N] = {'2', '1', '5', '9', '9'};
  char array2[N] = {'a', 'l', 'j', 'g', 'h'};
  char array3[N] = {'a', '1', '5', 'g', 'h'};
  char array4[N] = {'a', '1', '5', '4', 'h'};
  char array5[N] = {'a', '1', '5', '0', '1'};
  //uso array di puntatori invece di matrice per fare pratica
  char *arrayPrime[N] = {array1, array2, array3, array4, array5};
  for (int i = 0; i < N; i++) {
    int number = countDigitsInArray(arrayPrime[i], N);
    cout << endl << "Numero di cifre nell'array: " << number << endl;
  }
}
