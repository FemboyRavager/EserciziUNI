#include <iostream>

struct POINT {
  double x;
  double y;
};

struct CIRCLE {
  POINT centro;
  double raggio;
};

int main() {
  CIRCLE cerchio;
  cerchio.centro.x = 5;
  cerchio.centro.y = 5;
  cerchio.raggio = 3;
}
