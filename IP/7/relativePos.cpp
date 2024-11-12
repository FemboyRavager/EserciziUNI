#include <iostream>

using namespace std;

struct Point {
  double x;
  double y;
};

int main() {
  cout << "Inserire le coordinate del punto P1: ";
  Point P1, P2;
  cin >> P1.x >> P1.y;
  cout << "Inserire le coordinate del punto P2: ";
  cin >> P2.x >> P2.y;
  if (P1.x == P2.x && P1.y == P2.y) {
    cout << "I punti sono uguali\n";
  } else {
    cout << "Il secondo punto e' ";
    if (P2.y > P1.y)
      cout << "in alto ";
    else
      cout << "in basso";

    if (P2.x > P2.x)
      cout << "a destra";
    else
      cout << "a sinistra";
    cout << " rispetto al primo\n";
  }
}
