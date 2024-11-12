#include <cmath>
#include <iostream>

using namespace std;

struct StraightLine {
  double m; // coeff ang
  double q; // quota
};

struct Point {
  double x;
  double y;
};

int main() {
  double tolleranza=0.00001;
  StraightLine R;
  Point P;
  cout << "Inserire coeff. ang. e quota della retta, in ordine:\n";
  cin >> R.m >> R.q;
  cout << "Inserire coord di P:\n";
  cin >> P.x >> P.y;
  cout << "La retta R di equazione y=" << R.m << "x+" << R.q;
  if (fabs(P.y - R.m * P.x - R.q) < tolleranza) { // retta passa per il punto
    cout << " passa ";
  } else
    cout << " non passa ";
  cout << "per il punto di coordinate (" << P.x << "," << P.y << ")\n";
}
