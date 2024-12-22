#include <iostream>
#include <vector>
using namespace std;

struct casella {
  int x;
  int y;
  // string state;
};

bool Adiacente(casella c1, casella c2) {
  if (c1.x == c2.x) { // stessa colonna
    if (c1.y - c2.y == 1 || c2.y - c1.y == 1) {
      return true;
    }
  }
  if (c1.y == c2.y) { // stessa riga
    if (c1.x - c2.x == 1 || c2.x - c1.x == 1) {
      return true;
    }
  }
  return false;
}

void newStep(int fieldWidth, int fieldHeight, vector<casella> &path,
             casella nextCell) {

  cout << endl
       << "Attempting to insert (" << nextCell.x << "," << nextCell.y << ")";
  if (nextCell.x > 0 && nextCell.x < fieldWidth && nextCell.y > 0 &&
      nextCell.y < fieldHeight) { // interna al tabellone
    cout << "\nInterno al tabellone\n";
    cout << "\nChecking if " << nextCell.x << "," << nextCell.y
         << " is adjacent to " << path.back().x << "," << path.back().y << endl;
    if (Adiacente(nextCell, path.back())) { // adiacente al passo precedente
      cout << "\nAdiacente :)\n";
      path.push_back(nextCell);
      return;
    }
    return;
  }
  cout << "\nProssimo passo non adiacente\n";
}

int ampiezzaMax(vector<casella> path) {
  if (path.size() <= 0)
    throw "fuck";
  int minX = path.at(0).x;
  int maxX = path.at(0).x;
  for (int i = 1; i < path.size(); i++) {
    if (path.at(i).x<minX)
      minX = path.at(i).x;
    if (path.at(i).x>maxX)
      maxX = path.at(i).x;
  }
  return maxX-minX+1;
}

int main() {
  casella a;
  a.x = 1;
  a.y = 1;
  casella b;
  b.x = 2;
  b.y = 2;

  cout << "Adiacenti? " << (Adiacente(a, b) ? "Si" : "No") << endl;
  casella field[10][10];
  vector<casella> path = {};
  path.push_back(a);
  path.push_back(b);
  cerr << endl << "Size: " << path.size() << endl;
  for (unsigned int i = 0; i < 10 && i < path.size(); i++) {
    cerr << "Step " << i + 1 << ": (" << path[i].x << "," << path[i].y << ")"
         << endl;
  }
  casella c;
  c.x = 3;
  c.y = 2;
  newStep(10, 10, path, c);
  cerr << endl << "Size: " << path.size() << endl;
  for (unsigned int i = 0; i < 10 && i < path.size(); i++) {
    cerr << "Step " << i + 1 << ": (" << path[i].x << "," << path[i].y << ")"
         << endl;
  }
  cout << "The path's maximum amplitude is: " << ampiezzaMax(path);
}
