#include <iostream>
using namespace std;

int digitN(int n) {
  int count = 0;
  while (n > 0) {
    cout << "--Current n: " << n << "| Current count: " << count << endl;
    count++;
    n = n / 10;
  }
  cout << "--Current n: " << n << "| Current count: " << count << endl;
  return count;
}

int main() {
  int a = 335413;
  cout << digitN(a) << " cifre" << endl;
}
