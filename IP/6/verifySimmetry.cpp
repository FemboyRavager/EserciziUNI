#include <iostream>
using namespace std;

int main() {
  const int N = 3;
  int mat[N][N];
  bool isSymmetric = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << "Inserire int per cella " << i << "," << j << ": ";
      cin >> mat[i][j];
    }
  }
  cout<<endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << "|" << mat[i][j] << "|";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < N; i++) { // Check
    for (int j = 0; j < N; j++) {
      if (mat[i][j] != mat[j][i])
        isSymmetric = false;
    }
    cout << endl;
  }
  if (isSymmetric)
    cout << "E' simmetrica\n";
  else
    cout << "Non e' simmetrica\n";
}
