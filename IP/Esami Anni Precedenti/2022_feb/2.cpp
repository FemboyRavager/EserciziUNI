#include <iostream>
using namespace std;

int CountOccurrences(int A[], int size, int val) {
  if (size == 1) {
    if (A[size-1] == val) {
      return 1;
    }
    return 0;
  } else {
    if (A[size-1]==val) {
      return 1+CountOccurrences(A,  size-1, val);
    }
    return CountOccurrences(A, size - 1, val);
  }
}

int main() {
  int a[50];
  for (int i = 0; i < 50; i++) {
    a[i] = i;
    if (i % 5 == 0)
      a[i] = 100;
  }

  for (int i = 0; i < 50; i++) {
    cout << a[i] << (i < 49 ? "," : "\n");
  }

  cerr << "There are " << CountOccurrences(a, 50, 100)
       << " occurrences of '100'" << endl;
}
