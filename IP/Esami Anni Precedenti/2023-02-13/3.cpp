#include <iostream>
using namespace std;

struct set {
  int dato;
  set *next;
};
typedef set *insieme;

void insertElement(insieme &ins, int elem) {
  insieme cur = ins;
  while (cur) {
    if (cur->dato == elem) {
      return;
    }
    cur = cur->next;
  }
  insieme aux = new set;
  aux->dato = elem;
  aux->next = ins;
  ins=aux;
}

void printRecursive(insieme ins) {
  if (!ins)
    return;
  insieme cur = ins;
  if (cur) {
    cout << cur->dato<< "->";
    printRecursive(cur->next);
  }
}


int main() {
  insieme a = nullptr;
  insertElement(a, 4);
  insertElement(a, 6);
  insertElement(a, 1);
  insertElement(a, 4);
  insertElement(a, 8);
  insertElement(a, 9);

  insieme cur = a;
  while (cur) {
    cout << cur->dato<< "->";
    cur=cur->next;
  }
  cout << endl;
  printRecursive(a);
}
