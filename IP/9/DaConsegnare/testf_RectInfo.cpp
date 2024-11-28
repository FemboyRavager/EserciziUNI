#include <iostream>
using namespace std;

struct err {
  string functionName;
  string variableName;
  double variable1Value;
  double variable2Value;
  bool bothInvalid = false;
};

void computeRectInfo(double l1, double l2, double &area, double &perimetro) {
  if (l1 < 1 && l2 < 1) {
    err child;
    child.functionName = "computeRectInfo";
    child.bothInvalid = true;
    child.variableName = "l1 and l2";
    child.variable1Value = l1;
    child.variable2Value = l2;
    throw child;
  }
  if (l1 < 1) {
    err child;
    child.functionName = "computeRectInfo";
    child.variableName = "l1";
    child.variable1Value = l1;
    throw child;
  }
  if (l2 < 1) {
    err child;
    child.functionName = "computeRectInfo";
    child.variableName = "l2";
    child.variable1Value = l2;
    throw child;
  }
  perimetro = l1 + l1 + l2 + l2;
  area = l1 * l2;
}

struct rect {
  double l1;
  double l2;
};

int main() {
  const int N = 4;
  rect dati[N];
  double area = 0, perimeter = 0;
  dati[0].l1 = -20; // caso non valido
  dati[0].l2 = 10;

  dati[1].l1 = 20;
  dati[1].l2 = 0; // caso non valido

  dati[2].l1 = -20; // caso non valido
  dati[2].l2 = -10; // caso non valido

  dati[3].l1 = 20;
  dati[3].l2 = 110;

  for (int i = 0; i < N; i++) {
    try {
      computeRectInfo(dati[i].l1, dati[i].l2, area, perimeter);
      cout << "Rettangolo " << dati[i].l1 << "x" << dati[i].l2 << endl;
      cout << "Area: " << area << "\nPerimeter: " << perimeter << endl;
    } catch (err &error) {
      if (error.bothInvalid) {
        cout << "Errore in funzione " << error.functionName << ": variabili "
             << error.variableName
             << " con valori non validi: " << error.variable1Value << " and "
             << error.variable2Value << endl;
      } else {
        cout << "Errore in funzione " << error.functionName << ": variabile "
             << error.variableName
             << " con valore non valido: " << error.variable1Value << endl;
      }
    }
    cout << "---------------------" << endl;
  }
}
