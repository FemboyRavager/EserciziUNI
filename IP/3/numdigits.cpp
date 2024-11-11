#include <iostream>
using namespace std;

int main() {
  cout << "Inserisci un numero intero positivo: ";
  int K = 0, digitN = 1;
  cin >> K;
  if (K <= 0) {
    cout << "Il numero inserito NON e' valido";
    return 0;
  } else if (K >= 1 && K <= 9) {
    cout << "Il numero inserito e' composto da 1 cifra";
    return 0;
  } else {
    for (;;) {
      if ((K /= 10) > 0)
        digitN++;
      else
        break;
    }
  }

  cout << "Il numero inserito e' composto da " << digitN << " cifre";

  return 0;
}
