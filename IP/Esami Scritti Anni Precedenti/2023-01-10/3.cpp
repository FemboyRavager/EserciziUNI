#include <iostream>

using namespace std;

typedef struct cell {
  int head;
  cell *next;
} *lista;

void insertInOrdList(lista &list, int elem) {
  // cerr << "WEEE" << endl;
  if (!list || elem < list->head) {
    // cerr << "YAY" << endl;
    lista aux = new cell;
    aux->head = elem;
    aux->next = list;
    list = aux;
  } else {
    // cerr << "WOW" << endl;
    insertInOrdList(list->next, elem);
  }
  return;
}

void removeFromOrdList(lista &list, int elem) {
  if (!list) {
    return;
  }
  if (list->head == elem) {
    lista aux = list;
    list = aux->next;
    delete aux;
    return;
  } else {
    return removeFromOrdList(list->next, elem);
  }
}

bool areConsecutive(lista l1, lista l2) {
  lista cur = l1;
  int l1max = l1->head;
  while (cur) {
    if (cur->head > l1max) {
      l1max = cur->head;
    }
    cur = cur->next;
  }
  if (l1max < l2->head) {
    return true;
  }
  return false;
}

bool areEqual(lista l1, lista l2) {
  if (!l1 && !l2)
    return true;
  lista cur1 = l1;
  lista cur2 = l2;
  bool equal = true;
  while (cur1 && cur2) {
    if (cur1->head != cur2->head) {
      return false;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  if (cur1 || cur2) {
    return false;
  }
  return true;
}

int main() {

  lista a = nullptr;
  insertInOrdList(a, 3);
  insertInOrdList(a, 1);
  insertInOrdList(a, 6);
  insertInOrdList(a, 8);
  insertInOrdList(a, 0);
  // insertInOrdList(a, 13);
  lista cur = a;
  while (cur) {
    cerr << cur->head << "->";
    cur = cur->next;
  }

  cout << endl;

  removeFromOrdList(a, 3);
  cur = a;
  while (cur) {
    cerr << cur->head << "->";
    cur = cur->next;
  }

  lista b = nullptr;
  insertInOrdList(b, 12);
  insertInOrdList(b, 15);
  insertInOrdList(b, 32);

  cerr << endl;
  cur = b;
  while (cur) {
    cerr << cur->head << "->";
    cur = cur->next;
  }
  cout << endl;
  cout << (areConsecutive(a, b) ? "Consecutive" : "Not consecutive") << endl;
  cout << (areEqual(a, b) ? "Equal" : "Not equal") << endl << endl;
  lista l1 = nullptr;
  lista l2 = nullptr;
  lista cur1 = l1;
  lista cur2 = l2;
  while (cur1) {
    cerr << cur1->head << "->";
    cur1 = cur1->next;
  }
  cout << endl;
  while (cur2) {
    cerr << cur2->head << "->";
    cur2 = cur2->next;
  }
  cout << endl;
  cout << (areEqual(l1, l2) ? "Equal" : "Not equal") << endl << endl;

  insertInOrdList(l1, 2);
  cur1 = l1;
  cur2 = l2;
  while (cur1) {
    cerr << cur1->head << "->";
    cur1 = cur1->next;
  }
  cout << endl;
  while (cur2) {
    cerr << cur2->head << "->";
    cur2 = cur2->next;
  }
  cout << endl;
  cout << (areEqual(l1, l2) ? "Equal" : "Not equal") << endl << endl;

  insertInOrdList(l2, 2);
  insertInOrdList(l2, 3);
  cur1 = l1;
  cur2 = l2;
  while (cur1) {
    cerr << cur1->head << "->";
    cur1 = cur1->next;
  }
  cout << endl;
  while (cur2) {
    cerr << cur2->head << "->";
    cur2 = cur2->next;
  }
  cout << endl;
  cout << (areEqual(l1, l2) ? "Equal" : "Not equal") << endl << endl;
  insertInOrdList(l1, 3);
  cur1 = l1;
  cur2 = l2;
  while (cur1) {
    cerr << cur1->head << "->";
    cur1 = cur1->next;
  }
  cout << endl;
  while (cur2) {
    cerr << cur2->head << "->";
    cur2 = cur2->next;
  }
  cout << endl;
  cout << (areEqual(l1, l2) ? "Equal" : "Not equal") << endl << endl;
}
