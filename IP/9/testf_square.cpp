#include <iostream>
using namespace std;

struct err {
  string functionName;
  string paramName;
  int paramValue;
};

string asterisk = "* ";

void firstLastLine(int n) {
  for (int i = 0; i < n; i++) {
    cout << asterisk;
  }
}

void middleLines(int n) {
  string space = "  ";
  cout << asterisk;
  for (int i = 0; i < n - 2; i++) {
    cout << space;
  }
  cout << asterisk;
}

void square(int n) {
  err error;
  if (n <= 0) {
    error.functionName = "Square";      //Non serve a niente iddio santissimo
    error.paramName = "n";              //la consegna vuole solo "Errore valore < 1"
    error.paramValue = n;
    throw error;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) {
      firstLastLine(n);
    } else {
      middleLines(n);
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  int size = 3;
  try {
    cin>>size;
    square(size);
  } catch (err& errore) {
    cout << "Errore valore < 1" << endl;
  }
}
