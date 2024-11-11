#include <iostream>
using namespace std;

int main() {
  int greatestIndex;
  const int N = 10;
  int v[N] = {5, 9, 4, 3, 6, 1, 11, 7, 8, 2};
  cout << endl << "Array:";
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
  for (int i = 0; i < N; i++) {
    greatestIndex = i;
    //cout << endl << "i: " << i << "|greatestIndex: " << i;
    for (int j = i + 1; j < N; j++) {
      //cout << "\n\tj: " << j;
      if (v[j] < v[greatestIndex]) {
        greatestIndex = j;
        //cout << "||greatestIndex is now: " << j;
      }
    }
    int temp = v[i];
    v[i] = v[greatestIndex];
    v[greatestIndex] = temp;
    //cout << "||Switched " << v[i] << " and " << v[greatestIndex];

    /*cout << endl << "Current array:";
    for (int i = 0; i < N; i++) {
      cout << v[i] << " ";
    }*/
  }

  cout << endl << "Array:";
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
}
