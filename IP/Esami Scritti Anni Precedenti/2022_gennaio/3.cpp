#include <iostream>

using namespace std;

typedef struct cell {
  int head;
  cell *next;
} *lista;

void insertElement(lista &l, int x) {
  if (!l) {
    l = new cell;
    l->head = x;
    l->next = nullptr;
  } else {
    lista aux = new cell;
    aux->next = nullptr;
    aux->head = x;
    lista cur = l;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = aux;
  }
}

int countElements(lista &l) {

  int n = 0;
  if (l) {
    n = 1;
    return n + countElements(l->next);
  } else {
    return n;
  }
}

bool allEven(lista &l) {
  if (!l) {
    string child = "AAAAAAAAAAAAAAAAAAAAAAAAAA";
    throw child;
  }
  lista cur = l;
  while (cur) {
    if (cur->head % 2 != 0)
      return false;
    cur = cur->next;
  }
  return true;
}

int main() {
  lista a = nullptr;

  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 32);
  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 6);
  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 66);
  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 86);
  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 2);
  cout << "list contains " << countElements(a) << " elements" << endl;
  insertElement(a, 8);
  cout << "list contains " << countElements(a) << " elements" << endl;
  lista cur = a;

  while (cur) {
    cout << cur->head << (cur->next ? "->" : "\n");
    cur = cur->next;
  }

  cout << "list contains " << countElements(a) << " elements" << endl;
  cout << "Does list contain all even elements?:-> "
       << (allEven(a) ? "Yes" : "No") << endl;

  lista b = nullptr;
  cout << "list contains " << countElements(b) << " elements" << endl;
  try {
    cout << "Does list contain all even elements?:-> "
         << (allEven(b) ? "Yes" : "No") << endl;
  } catch (string &err) {
    cerr << err;
  }
}
