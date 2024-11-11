#include <iostream>
using namespace std;

int main() {
  const int N = 10;
  int source[N] = {};
  int dest[N] = {};

  cout << "Inserire 10 interi:\n";

  for (int i = 0; i < N; i++) {
    cin >> source[i];
  }

  for (int i = 0; i < N; i++) {
    dest[N - i - 1] = source[i];
  }
  cout << "\nElementi in array source:\t";
  for (int i = 0; i < N; i++) {
    cout << source[i] << " ";
  }
  cout << "\nElementi in array dest:\t\t";
  for (int i = 0; i < N; i++) {
    cout << dest[i] << " ";
  }
  cout << endl;
  return 0;
}
