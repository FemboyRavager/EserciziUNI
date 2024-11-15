#include <iostream>

using namespace std;

void replicate(int N, char c) {
  if (N <= 0)
    return;
  for (int i = 0; i < N; i++) {
    cout << c;
  }
}

void triangle(int len) {
  for (int i = 1; i <= len; i++) {
    replicate(i, '*');
    cout << endl;
  }
}

int main() {
  cout << "Inserisci un numero maggiore di 0: ";
  int len = 0;
  cin >> len;
  if (len > 0)
    triangle(len);
  else
    cout << "Errore: numero non maggiore di 0\n";

  return 0;
}
