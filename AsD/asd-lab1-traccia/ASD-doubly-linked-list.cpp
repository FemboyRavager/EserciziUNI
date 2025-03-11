// FILE DA MODIFICARE
#include <fstream>
#include <iostream>
#include <string>
#include "ASD-doubly-linked-list.h"
using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/

/* crea la lista vuota */
void list::createEmpty(List &li) {
  li = new node;
  li->next = li;
  li->prev = li;
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List &li) {
  if (li->next == li && li->prev == li) {
    return;
  }
  List cur = li->next; // aux è primo elemento
  while (cur) {
    if (cur == li) {
      return;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    cur = li->next;
  }
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List &li) {
  return (li->next == li && li->prev == li);
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List &li) {
  unsigned int count = 0;
  List aux = li->next;
  while (aux != li) {
    count++;
    aux = aux->next;
  }
  return count;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List &li) {
  if (pos >= size(li)) {
    string child;
    throw child;
  }
  unsigned int count = 0;
  List cur = li->next;
  while (cur != li) {
    if (count == pos) {
      return cur->info;
    }
    count++;
    cur = cur->next;
  }
  string child;
  throw child; // non dovrebbe mai essere raggiunto
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List &li) {
  if (pos >= size(li)) {
    string child;
    throw child;
  }
  unsigned int count = 0;
  List cur = li->next;
  while (cur != li) {
    if (count == pos) {
      cur->info = el;
    }
    count++;
    cur = cur->next;
  }
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List &li) {
  if (pos > size(li)) {
    string child;
    throw child;
  }
  if (li->next == li) {
    List aux = new node;
    aux->info = el;
    li->next = aux;
    li->prev = aux;
    aux->next = li;
    aux->prev = li;
    return;
  }
  List cur = li->next;
  unsigned int currentPos = 0;
  while (cur != li) {
    if (currentPos == pos) {
      List aux = new node;
      aux->info = el;
      cur->prev->next = aux;
      aux->prev = cur->prev;
      aux->next = cur;
      cur->prev = aux;
      return;
    } else if (currentPos == pos - 1 && cur->next == li) {
      List aux = new node;
      aux->info = el;
      cur->next = aux;
      aux->prev = cur;
      aux->next = li;
      li->prev = aux;
      return;
    }
    currentPos++;
    cur = cur->next;
  }
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List &li) {
  List aux = new node;
  aux->info = el;
  /*
    if (li->next == li) {
      li->next = aux;
      aux->prev = li;
      aux->next = li;
      li->prev = aux;
      return;
    }
    */
  List cur = li->next;
  while (cur->next != li) {
    cur = cur->next;
  }
  aux->next = li;
  aux->prev = cur;
  li->prev = aux;
  cur->next = aux;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List &li) {
  List aux = new node;
  aux->info = el;
  List currentFirst = li->next;
  aux->next = currentFirst;
  aux->prev = li;
  currentFirst->prev = aux;
  li->next = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos, const List &li) {
  if (pos >= size(li)) {
    string child;
    throw child;
  }
  List cur = li->next;
  unsigned int currentPos = 0;
  while (cur != li) {
    if (pos == currentPos) {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      delete cur;
      return;
    }
    currentPos++;
    cur = cur->next;
  }
}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el, const List &li) {
  List cur = li->next;
  while (cur != li) {
    if (cur->info == el) {
      List tmp = cur->prev;
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      delete cur;
      cur = tmp;
    }
    cur = cur->next;
  }
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/

/* riempie una lista da file */
void list::readFromFile(string name_file, const List &li) {
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline(infile, read_data)) {
    if (read_data.length() > 0) {
      addRear(stoi(read_data), li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List &li) {
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END "
          "per terminare\n";
  string read_data;
  cin >> read_data;
  while (read_data != "END") {
    addRear(stoi(read_data), li);
    cin >> read_data;
  }
}

/* stampa la lista */
void list::print(const List &li) {
  if (li == li->next) {
    cout << "vuota";
  }
  List cur = li->next; // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {
    cout << cur->info;
    cur = cur->next;
    if (cur != li)
      cout << " <-> ";
  }
  cout << endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List &li) {
  string out = "";
  if (li == li->next) {
    out += "vuota";
  }
  List cur = li->next; // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {
    out += to_string(cur->info);
    cur = cur->next;
    if (cur != li)
      out += " <-> ";
  }
  return out;
}
