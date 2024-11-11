#include <cctype>
#include <iostream>
using namespace std;

int main() {

  const int D = 4;

  int array[D] = {};

  cout << "Inserire " << D << " elementi per l'array:\n";
  for (int i = 0; i < D; i++) {
    cin >> array[i];
  }
  for (int i = 0; i < D; i++) {
    cout << array[i] << " ";
  }
  cout << "<- Originale";
  int temp = array[D - 1];
  for (int i = D - 1; i >= 0; i--) {
    if (i == 0) {
      // cout << "\ni: " << i << "| replacing " << array[i] << " with " << temp;
      array[i] = temp;
    } else {
      // cout << "\ni: " << i << "| replacing " << array[i] << " with " <<
      // array[i - 1];
      array[i] = array[i - 1];
    }
  }
  cout << endl;
  for (int i = 0; i < D; i++) {
    cout << array[i] << " ";
  }
  cout << "<- Ruotato\n";
  return 0;
}
