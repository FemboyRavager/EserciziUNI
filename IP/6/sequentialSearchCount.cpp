#include <iostream>
using namespace std;

int main() {

  const int N = 30;
  int loc = -1;
  bool found = false;
  int item, count = 0;
  cout << "Inserire numero: ";
  cin >> item;
  int v[N] = {};
  for (int i = 0; i < N; i++) {
    v[i] = i;
  }
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
  for (int i = 0; i < N && !found; i++) {
    if (v[i] == item) {

      found = true;
      loc = i;
    }
    count++;
  }
  if (found) {
    cout << endl
         << item << " è stato trovato in pos " << loc << " con " << count
         << " accessi all'array";
  } else
    cout << endl
         << item << " non è stato trovato, con " << count
         << " accessi all'array";
}
