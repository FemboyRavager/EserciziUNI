#include <iostream>

using namespace std;

void triangle(int len) {

  for (int i=1;i<=len;i++) {
    for (int j=1; j<=i; j++) {
      cout<<"*";
    }
    cout<<endl;
  }
}

int main() {
  cout << "Inserisci un numero maggiore di 0: ";
  int len = 0;
  cin >> len;
  if (len >= 0)
    triangle(len);
  else
    cout << "Errore: numero non maggiore di 0";

        return 0;
}
