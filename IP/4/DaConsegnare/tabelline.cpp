#include <iostream>
using namespace std;

int main() {
  const int N = 10;

  int tavolaPitagorica[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      tavolaPitagorica[i][j] = ((i + 1) * (j + 1));
    }
  }
  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << tavolaPitagorica[i][j] << " ";
    }
    cout << endl;
  }*/

  int n = 0, m = 0;
  while (true) {
    cout << "Inserire due valori tra 1 e 10\n";
    cin >> n >> m;
    if (n > 0 && n < 11 && m > 0 && m < 11) {
      break;
    } else
      cout << "Per cortesia seguire le istruzioni\n";
  }

  // cout << endl << n << endl << m;
  cout << "\nProdotto tra " << n << " e " << m << ": " << tavolaPitagorica[n-1][m-1] << endl;
  return 0;
}
