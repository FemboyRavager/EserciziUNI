#include <iostream>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

int main() {
  Point P1, P2;
  cout << "Inserire coordinate del punto P1: ";
  cin >> P1.x >> P1.y;

  cout << "Inserire coordinate del punto P2: ";
  cin >> P2.x >> P2.y;

  double distance;

  distance=sqrt(pow(P2.x-P1.x,2)+pow(P2.y-P1.y,2));
  cout<<"\nLa distanza tra P1 e P2 è: "<<distance<<endl;
}
