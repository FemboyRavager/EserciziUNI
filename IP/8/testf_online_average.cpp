#include <iostream>
using namespace std;

double onlineAverage() {
  bool stop = false, stop_yn = false;
  char userChoice = 0;
  double currentNumber = 0, total = 0, i = 0;
  while (!stop) {
    cout << "Inserire numero reale: ";
    cin >> currentNumber;
    i++;
    total += currentNumber;
    stop_yn = false;
    while (!stop_yn) {
      cout << "Continuare ad inserire? y/n: ";
      cin >> userChoice;
      if (userChoice == 'n') {
        stop = true;
        stop_yn = true;
      } else if (userChoice == 'y') {
        stop_yn = true;
      } else {
        cout << "Input non valido\n";
      }
    }
  }
  return total / i;
}

int main() {
  double media = onlineAverage();
  cout << endl << "La media dei numeri inseriti e': " << media << endl;
}
