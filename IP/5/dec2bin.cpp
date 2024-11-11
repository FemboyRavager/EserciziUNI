#include <iostream>

using namespace std;

int main() {

  const int N = 10;
  int array[N] = {};
/*
  for (int i = 0; i < N; i++) {
    cout << array[i] << "|";
  }
*/
  //cout << "\tSize:" << sizeof(array) / sizeof(int);
  int n;
  //cout << "\nInserire numero intero positivo minore di 1024: ";
  cin >> n;
  if (n < 0 || n > 1023) {
    cout << "Numero NON valido";
    return 0;
  }

  int ncopy = n;

  for (int i = 0; ncopy != 0; i++) {
    array[N - 1 - i] = ncopy % 2;
    ncopy = ncopy / 2;
  }
  //cout << endl;
  cout << n << " ";
  for (int i = 0; i < N; i++) {
    cout << array[i];
  }
  //cout << endl;

  return 0;
}
