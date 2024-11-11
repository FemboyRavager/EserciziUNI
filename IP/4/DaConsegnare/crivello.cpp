#include <iostream>
using namespace std;

int main() {
  const int n = 1000;
  bool isprime[n] = {false, false};
  int p = 2;
  bool stop = 0;
  for (int i = 3; i < n; i++) {
    // cout << endl << isprime[i] << ",";
    isprime[i] = 1;
  }
  while (!stop) {

    for (int i = 3; i < n; i++) {
      if (i % p == 0 && i != p) {
        isprime[i] = false;
        // cout << "\t" << i << ": false";
      }
    }

    p++;
    if (p == n)
      stop = 1;
    // cout << "\nIncreasing p to " << p << endl;
    for (int j = p; j < n - 1; j++) {
      if (isprime[j]) {
        p = j;
        // cout << "\np is now: " << p << endl;
        break;
      }
    }
  }
  cout << endl << "Numeri primi fino a " << n << ":\n";
  for (int i = 0; i < n; i++) {
    if (isprime[i]) {
      cout << i << endl;
    }
  }
  return 0;
}
