#include <iostream>
using namespace std;

int main() {
  const int N = 2, M = 2;
  float mat[N][M];
  float det = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << "\nInserire float per i=" << i << " e j=" << j << ": ";
      cin >> mat[i][j];
    }
  }
  cout << endl;

  det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
  cout << "Il determinante della matrice:" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << "|" << mat[i][j] << "|";
    }
    cout << endl;
  }
  cout<<"è: "<<det<<endl;
}
