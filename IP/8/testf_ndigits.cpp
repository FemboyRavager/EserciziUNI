#include <iostream>
using namespace std;

int getLength(int num) {
  int digits = 0;
  for (int i = 0;; i++) {
    if (num % 10 != 0) {
      // cout<<endl<<num<<"divisibile per 10\n";
      num /= 10;
      digits++;
    } else
      return digits;
  }

  return digits;
}

int main() {
  const int N = 5;
  int a[5] = {546, 32198465, -321, 6, 23};
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << a[i] << " ha " << getLength(a[i]) << " cifre\n";
  }
}
