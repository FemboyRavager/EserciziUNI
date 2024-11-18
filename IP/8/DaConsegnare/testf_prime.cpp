#include <iostream>
using namespace std;

bool isPrime(int x) {
  if (x < 0 || x == 0 || x == 1)
    return false;
  for (int i = 2; i < x; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  const int N = 50;
  int n[N] = {};

  for (int i = 0; i < N; i++) {
    n[i] = i - 15;
  }
  cout<<endl;
  for (int i = 0; i < N; i++) {
    cout<<n[i]<<"|";
  }
  cout<<endl<<endl;

  for (int i = 0; i < N; i++) {
    if (isPrime(n[i])) {
      cout << endl << n[i] << " e' primo";
    } else
	  cout << endl << n[i] << " non e' primo";
  }
}
