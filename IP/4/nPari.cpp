#include <iostream>
using namespace std;

int main() {
  const int N = 10;
  int a[N] = {};
  int P=0, D=0;
  for (int i = 0; i < N; i++) {
    cout << "\nInserire int a[" << i << "]: ";
    cin >> a[i];
  }

  for (int i = 0; i < N; i++) {
    //cout << "\na[" << i << "]: " << a[i];
    if ( a[i]%2 == 0 ) {
      P++;
    } else
      D++;
  }

  cout << endl << "Numero valori pari: " << P << endl;

  cout << endl << "Numero valori dispari: " << D << endl;
  return 0;
}
