#include <iostream>
using namespace std;

int main() {
  const int N = 15;
  // int v[N] = {5, 7, 16, 24, 25, 30, 45, 50, 62, 65};
  int v[N] = {};
  cout << "Inserire " << N << " valori da inserire nell'array" << endl;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < N - 1; i++) {
    if (v[i] >= v[i + 1]) {
      cout << "\nArray non ordinato\n";
      return 0;
    }
  }
  int item = 0, mid, first = 0, last = N - 1;
  bool found = false;
  /*
  cout << "Array: ";
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
  */
  cout << "\nInserire numero da trovare: ";
  cin >> item;
  cout << endl;
  while (first <= last && !found) {
    mid = (first + last) / 2;
    //cout << endl<< "First: " << first << "|Last: " << last << "|Mid: " << mid << endl;
    if (v[mid] == item)
      found = true;
    else if (v[mid] > item)
      last = mid - 1;
    else
      first = mid + 1;
  }
  if (found)
    cout << endl << item << " trovato in pos i:" << mid << " con primo elemento i=0\n";
  else
    cout << endl << item << " non trovato\n";
}
