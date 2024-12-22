#include <iostream>
using namespace std;

typedef int Elem;

typedef struct cell {
  Elem head;
  cell *next;
} *lista;

void insertListHead(lista &l, Elem x) {
  lista aux = new cell;
  aux->head = x;
  aux->next = l;
  l = aux;
}

void printList(lista &l) {
  if (!l) {
    cout << "";
  } else {
    cout << l->head << (l->next ? "->" : "\n");
    printList(l->next);
  }
}

void deleteElementAll(lista &l, Elem x) {
  lista cur = l;
  lista prev = cur;
  if (l->head == x) {
    cerr << x << " found in head" << endl;
    l = l->next;
    // delete cur;
  }
  cerr << "== ";
  printList(l);
  cur = l;
  prev = cur;
  while (cur) {
    cerr << "DAJE: " << prev->head << "->" << cur->head << endl;
    // cerr << "Comparing " << cur->head << endl;
    cerr << "== ";
    printList(l);
    if (cur->head == x) {
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
    cerr << "== ";
    printList(l);
  }
}

int main() {
  lista l = nullptr;
  insertListHead(l, 5);
  insertListHead(l, 1);
  insertListHead(l, 2);
  insertListHead(l, 3);
  insertListHead(l, 4);
  insertListHead(l, 5);
  insertListHead(l, 5);
  insertListHead(l, 6);
  insertListHead(l, 5);
  insertListHead(l, 4);
  insertListHead(l, 5);

  cerr << "== ";
  printList(l);

  cerr << "Deleting all instances of 5:\n";
  deleteElementAll(l, 5);
  cerr << "== ";
  printList(l);
}
