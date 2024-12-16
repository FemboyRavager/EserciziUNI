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

bool areOverlapped(CIRCLE cerchio1, CIRCLE cerchio2) {
  if (sameArea(cerchio1, cerchio2)) {
    if (cerchio1.centro.x == cerchio2.centro.x &&
        cerchio1.centro.y == cerchio2.centro.y)
      return true;
  }
  return false;
}

bool oneContainsTheOther(CIRCLE cerchio1, CIRCLE cerchio2) {
  double centerDistance = sqrt(pow(cerchio1.centro.x-cerchio2.centro.x,2)+pow(cerchio1.centro.y-cerchio2.centro.y,2));
  if (centerDistance <= (cerchio1.raggio-cerchio2.raggio)) {
    return true;
  }
  return false;
}

int main() {
  CIRCLE cerchio1;
  cerchio1.centro.x = 5;
  cerchio1.centro.y = 5;
  cerchio1.raggio = 10;

  CIRCLE cerchio2;
  cerchio2.centro.x = 13;
  cerchio2.centro.y = 6;
  cerchio2.raggio = 2;

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

  if (areOverlapped(cerchio1, cerchio2))
    cout << "Circles are overlapped";
  else
    cout << "Circles are NOT overlapped";
  cout << endl;

  if (oneContainsTheOther(cerchio1, cerchio2))
    cout <<"One contains the other";
  else
    cout <<"Neither contains the other";
  cout << endl;
}
