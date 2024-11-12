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
  int N = 5;
  Point polilinea[N];

  for (int i = 0; i < N; i++) {
    cout << "Inserire coordinate del punto " << i + 1 << ": ";
    cin >> polilinea[i].x >> polilinea[i].y;
  }
  for (int i = 0; i < N; i++) {
    cout << "\nPunto " << i + 1 << ": (" << polilinea[i].x << ","
         << polilinea[i].y << ")";
  }

  double totLength = 0;

  // Calcolo lunghezza totale
  for (int i = 0; i < N - 1; i++) { // lunghezza totale
    // cout<<endl<<"Current totLength: "<<totLength<<endl;
    totLength += sqrt(pow(polilinea[i].x - polilinea[i + 1].x, 2) +
                      pow(polilinea[i].y - polilinea[i + 1].y, 2));
  }

  cout << "\nLunghezza totale della polilinea: " << totLength << endl;

  // Calcolo lunghezza media
  double avgLength = totLength / (N - 1); // media lunghezza segmenti
  bool allSameLength = true;
  for (int i = 0; i < N - 1;
       i++) { // compara lunghezza di ogni segmento a avg length.
    if (sqrt(pow(polilinea[i].x - polilinea[i + 1].x, 2) +
             pow(polilinea[i].y - polilinea[i + 1].y, 2)) != avgLength) {
      allSameLength = false; // se almeno una è diversa da avgLength
    }
  }
  if (allSameLength)
    cout << "\nTutti i segmenti hanno la stessa lunghezza";
  else
    cout << "\nNon tutti i segmenti hanno la stessa lunghezza";

  // Verifica se chiusa e regolare
  if (polilinea[0].x == polilinea[N - 1].x &&
      polilinea[0].y == polilinea[N - 1].y) {
    cout << "\nLa linea e' chiusa e quindi definisce un poligono";
    if (allSameLength)
      cout << " regolare";
  }
  cout << endl;
}
