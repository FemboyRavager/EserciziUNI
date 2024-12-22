#include <iostream>
using namespace std;

float avgRec(float A[], int size, int i) {
  if (i == size - 1) {
    return A[i];
  }
  if (i == 0) {
    return (A[i] + avgRec(A, size, i + 1)) / size;
  }
  return A[i] + avgRec(A, size, i + 1);
}

float avg(float A[], int size) { return avgRec(A, size, 0); }

int main() {
  float A[10];
  for (int i = 0; i < 10; i++) {
    A[i] = i + 3;
  }
  for (int i = 0; i < 10; i++) {
    cout << A[i] << (i < 9 ? "," : "\n");
  }
  cerr << "La media è: " << avg(A, 10);
}
