#include "string_list.h"
#include <iostream>

using namespace std;

void headInsert(list &l, std::string s) {
  /*
  if (!l) {
    string child = "\n==ERROR nonexistent list\n";
    throw child;
  }*/
  // cout << "--START headInsert\n\t";
  // print(l);
  if (s == "") {
    string child = "\n==ERROR empty element\n";
    throw child;
  }
  list aux = new cell;
  aux->data = s;
  aux->next = l;
  l = aux;
  // print(l);
  // cout << "--END headInsert\n\t";
}

void tailInsert(list &l, std::string s) {
  if (!l) {
    string child = "\n==ERROR nonexistent list\n";
    throw child;
  }
  if (s == "") {
    string child = "\n==ERROR empty element\n";
    throw child;
  }
  list cur = l;
  while (cur->next != nullptr) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    cur = cur->next;
    // cerr << "--->" << cur->data << " | " << cur->next << endl;
  }
  // cerr << "Yay" << endl;
  list aux = new cell;
  aux->data = s;
  aux->next = nullptr;
  cur->next = aux;
}

void read(list &l) {
  bool flag = true;
  do {
    string newString = "";
    cout << "Inserire stringa da inserire nella lista\n\t";
    cin >> newString;
    if (newString != "STOP!") {
      tailInsert(l, newString);
    } else {
      flag = false;
    }
  } while (flag);
}

void print(const list &l) {
  cout << endl;
  list cur = l;
  while (cur) {
    cout << cur->data << ((cur->next) ? "->" : "");
    cur = cur->next;
  }
  cout << endl;
}

unsigned int size(const list &l) {
  list cur = l;
  unsigned int i = 0;
  while (cur) {
    i++;
    cur = cur->next;
  }
  return i;
}

bool isEmpty(const list &l) {
  if (l) {
    return false;
  } else
    return true;
}

std::string getElem(const list &l, unsigned int i) {
  if (!l) {
    string child = "\n==ERROR lista vuota\n";
    throw child;
  }
  if (i < 0) {
    string child = "\n==ERROR valore i invalido\n";
    throw child;
  }
  list cur = l;
  for (unsigned int j = 0; j < (i - 1) && cur; j++) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    cur = cur->next;
  }
  if (cur)
    return cur->data;
  else {
    string child = "\n==ERROR index greater than list length\n";
    throw child;
  }
}

void insertAt(list &l, std::string s, unsigned int i) {
  list cur = l;
  list prev = l;
  for (unsigned int j = 0; j < (i - 1) && cur; j++) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    prev = cur;
    cur = cur->next;
  }
  headInsert(cur, s);
  prev->next = cur;
}

void deleteAt(list &l, unsigned int i) {
  list cur = l;
  list prev = l;
  for (unsigned int j = 0; j < (i - 1) && cur; j++) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    prev = cur;
    cur = cur->next;
  }
  prev->next = cur->next;
  delete cur;
}

void deleteOnce(list &l, std::string s) {
  list cur = l;
  list prev = l;
  while (cur && cur->data != s) {
    prev = cur;
    cur = cur->next;
  }
  if (!cur)
    return;
  // cout<<"Found element "<<s<<endl;
  prev->next = cur->next;
  delete cur;
}

void deleteAll(list &l, std::string s) {
  list cur = l;
  list prev = l;
  while (cur->next) {
    if (cur->data == s) {
      if (cur==l) {
        delete l;
        l=l->next;
      }
      prev->next = cur->next;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
    //TODO aggiungere gestione ultima cella
  }
}
