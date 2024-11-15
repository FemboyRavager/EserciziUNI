#include <cmath>
#include <iostream>
using namespace std;

struct Punto {
  double x, y;
};

double dist(Punto p1, Punto p2) {
  double dist = 0;
  dist = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
  //cout<<endl<<"\t dist:"<<dist<<endl;
  return dist;
}

int main() {
  const int N = 4;
  double tot = 0;
  Punto input[N] = {};
  for (int i = 0; i < N; i++) {
    cout << endl << i + 1 << ".x:";
    cin >> input[i].x;
    cout << i + 1 << ".y:";
    cin >> input[i].y;
  }
  for (int i = 0; i < N; i++) {
    cout << endl << i + 1 << ": " << input[i].x << "." << input[i].y << endl;
  }

  for (int i = 0; i < N - 1; i++) {
    //cout<<endl<<"Current tot"<<tot;
    tot += dist(input[i], input[i + 1]);
  }
  cout << endl << "La lunghezza della spezzata e'" << tot<<endl;
}
