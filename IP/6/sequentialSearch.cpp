#include <iostream>
using namespace std;

int main() {

  const int N = 15;
  int loc = -1;
  bool found = false;
  int item;
  cout << "Inserire numero: ";
  cin >> item;
  int v[N] = {};
  cout << "Inserire 15 numeri per l'array";
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
  for (int i = 0; i < N && !found; i++) {
    if (v[i] == item) {
      found = true;
      loc = i;
    }
  }
  if(found) {
    cout << endl<<item<<" è stato trovato in pos " <<loc;
  } else
    cout << endl<<item<<" non è stato trovato";
}
