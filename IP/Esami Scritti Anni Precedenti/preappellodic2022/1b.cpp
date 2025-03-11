#include <cmath>
#include <iostream>
using namespace std;

struct POINT {
  double x;
  double y;
};

struct CIRCLE {
  POINT centro;
  double raggio;
};

bool sameArea(CIRCLE cerchio1, CIRCLE cerchio2) {
  double c1Area = pow(cerchio1.raggio, 2) * M_PI;
  double c2Area = pow(cerchio2.raggio, 2) * M_PI;
  if (c1Area == c2Area)
    return true;
  return false;
}

bool samePerimeter(CIRCLE cerchio1, CIRCLE cerchio2) {
  double c1Perimeter = 2 * M_PI * cerchio1.raggio;
  double c2Perimeter = 2 * M_PI * cerchio2.raggio;
  if (c1Perimeter == c2Perimeter)
    return true;
  return false;
}

int main() {
  CIRCLE cerchio1;
  cerchio1.centro.x = 5;
  cerchio1.centro.y = 5;
  cerchio1.raggio = 3;

  CIRCLE cerchio2;
  cerchio2.centro.x = 5;
  cerchio2.centro.y = 5;
  cerchio2.raggio = 3;

  if (sameArea(cerchio1, cerchio2)) {
    cout << "Same area";
  } else
    cout << "Different area";
  cout << endl;
  if (samePerimeter(cerchio1, cerchio2))
    cout << "Same perimeter";
  else
    cout << "Different perimeter";
  cout << endl;
}
