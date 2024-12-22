#include "string_ord_list.h"
#include <iostream>

using namespace std;

// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista
// ordinata
void insertElement(ordList &l, string s) {
  ordList cur = l;
  ordList prev = cur;
  if (!l) {
    l = new cell;
    l->next = nullptr;
    l->data = s;
  } else {
    while (cur) {
      if (s < cur->data) {
        ordList aux = new cell;
        aux->next = cur;
        aux->data = s;
        if (cur == l) { // inserimento in testa
          aux->next = cur;
          l = aux;
        } else {
          prev->next = aux;
        }

        return;
      }
      prev = cur;
      cur = cur->next;
    }
    ordList aux = new cell;
    aux->data = s;
    aux->next = nullptr;
    prev->next = aux;
  }
}

// legge valori da input e li memorizza (aggiunge) nella lista ordinata l
// al termine dell'esecuzione di readList la lista l deve essere una lista
// ordinata. l'inserimento termina se l'utente inserisce "STOP!"
void readList(ordList &l) {
  bool flag = true;
  do {
    string newString = "";
    cout << "Inserire stringa da inserire nella lista\n\t";
    cin >> newString;
    if (newString != "STOP!") {
      insertElement(l, newString);
    } else {
      flag = false;
    }
  } while (flag);
}

// stampa tutti i valori (data) degli elementi della lista ordinata l in linea
// separati da "->"

void printList(const ordList &l) {
  ordList cur = l;
  while (cur) {
    cerr << cur->data << ((cur->next) ? "->" : "");
    cur = cur->next;
  }
}

// ritorna il numero di elementi della lista ordinata l
// NB: nessuna variazione rispetto alla versione per liste non ordinate
unsigned int listSize(const ordList &l) {
  ordList cur = l;
  int i = 0;
  while (cur && i < 20) {
    i++;
    cur = cur->next;
  }
  return i;
}

// ritorna true se la lista ordinata l e vuota, false altrimenti
bool isEmptyList(const ordList &l) {
  if (!l)
    return true;
  return false;
}

// ritorna il contenuto dell'i-esimo elemento della lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo
// string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
string getElement(const ordList &l, unsigned int i) {
  if (!l) {
    string child =
        "====ERROR List empty. Cannot fetch element in getElement call.";
    throw child;
  }
  if (i > listSize(l)) {
    string child = "====ERROR Invalid index in getElement call";
    throw child;
  }
  ordList cur = l;
  unsigned int j = 1;
  while (cur && j < i) {
    j++;
    cur = cur->next;
  }
  return cur->data;
}

// cancella l'elemento in posizione i dalla lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo
// string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteElementAt(ordList &l, unsigned int i) {
  if (!l) {
    string child = "====ERROR List empty. Cannot delete elements.";
    throw child;
  }
  if (i > listSize(l)) {
    string child = "====ERROR Invalid index in deleteElementAt call";
    throw child;
  }
  ordList cur = l;
  ordList prev = l;

  for (unsigned int j = 0; j < (i - 1) && cur; j++) {
    prev = cur;
    cur = cur->next;
  }
  if (cur == l) { // first cell
    l = l->next;
    delete cur;
  } else if (cur->next == nullptr) { // last cell
    prev->next = nullptr;
    delete cur;
  } else {
    prev->next = cur->next;
    delete cur;
  }
}

// cancella dalla lista ordinata l il primo elemento contenente s
void deleteElementOnce(ordList &l, std::string s) {
  if (!l) {
    string child = "====ERROR List empty. Cannot delete elements.";
    throw child;
  }
  ordList cur = l;
  ordList prev = l;
  while (cur && cur->data != s) {
    prev = cur;
    cur = cur->next;
  }
  if (!cur) {
    string child = "Element not present in list.";
    throw child;
  }
  if (cur == l) { // first cell
    l = l->next;
    delete cur;
  } else if (cur->next == nullptr) { // last cell
    prev->next = nullptr;
    delete cur;
    return;
  } else {
    prev->next = cur->next;
    delete cur;
  }
}

// cancella dalla lista ordinata l tutti gli elementi contenenti s
void deleteAllElements(ordList &l, std::string s) {
  if (!l) {
    string child = "====ERROR List empty. Cannot delete elements.";
    throw child;
  }
  ordList cur = l;
  ordList prev = l;
  while (cur) {
    if (cur->data == s) {
      if (cur == l) { // s in prima cella
        l = l->next;
        delete cur;
        cur = l;
      } else if (cur->next == nullptr) { // last cell
        prev->next = nullptr;
        delete cur;
        return;
      } else {
        prev->next = cur->next;
        delete cur;
        cur = prev->next;
      }
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
}

// restituisce true se le due liste contengono le stesse stringhe (con la stessa
// molteplicità) false altrimenti
bool listAreEqual(const ordList &l1, const ordList &l2) {
  if (!l1 && !l2)
    return true;
  ordList cur1 = l1;
  ordList cur2 = l2;
  bool equal = true;
  while (cur1 && cur2) {
    if (cur1->data != cur2->data) {
      equal = false;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  if (cur1 || cur2) {
    equal = false;
  }
  if (equal)
    return true;
  return false;
}

// restituisce una nuova lista ordinata contenente gli elementi delle 2 liste
// ordinate l1 e l2 Il numero di occorrenze di un elemento nel risultato è la
// somma del numero delle sue occorrenze nelle due liste l1 e l2 NB: ogni
// elemento della nuova lista deve essere un duplicato di quelli //     in
// questo modo sia l1 che l2 non subiscono alcuna modifica
ordList concatLists(const ordList &l1, const ordList &l2) {
  ordList newList = nullptr;
  ordList cur1 = l1;
  ordList cur2 = l2;
  while (cur1 || cur2) {
    if (cur1) {
      insertElement(newList, cur1->data);
      cur1 = cur1->next;
    }
    if (cur2) {
      insertElement(newList, cur2->data);
      cur2 = cur2->next;
    }
  }
  return newList;
}

// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in almeno una delle due liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli
// contenuti in l1 e l2
//      in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare
// il fatto che
//      le due liste sono ordinate per minimizzare il numero di operazioni
//      necessarie
ordList unionLists(const ordList &l1, const ordList &l2) {
  ordList newList = nullptr;
  ordList newListCur = newList;
  ordList cur1 = l1;
  ordList cur2 = l2;
  bool alreadyPresent = false;
  while (cur1) {
    alreadyPresent = false;
    if (cur1 == l1) {
      insertElement(newList, cur1->data);
    } else {
      newListCur = newList;
      while (newListCur) {
        if (cur1->data == newListCur->data) {
          alreadyPresent = true;
        }
        newListCur = newListCur->next;
      }
      if (!alreadyPresent) {
        insertElement(newList, cur1->data);
      }
    }
    cur1 = cur1->next;
  }
  while (cur2) {
    alreadyPresent = false;
    newListCur = newList;
    while (newListCur) {
      if (cur2->data == newListCur->data) {
        alreadyPresent = true;
      }
      newListCur = newListCur->next;
    }
    if (!alreadyPresent) {
      insertElement(newList, cur2->data);
    }
    cur2 = cur2->next;
  }
  return newList;
}

// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in entrambe le liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli
// contenuti in l1 e l2
//      in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare
// il fatto che
//      le due liste sono ordinate per minimizzare il numero di operazioni
//      necessarie
ordList intersectLists(const ordList &l1, const ordList &l2) {
  ordList newList = nullptr;
  // ordList newListCur = newList;
  ordList cur1 = l1;
  ordList cur2 = l2;
  while (cur1) {
    if (cur1->next &&
        cur1->data == cur1->next->data) { // if more than one string in a row
      cur1 = cur1->next;
      continue;
    }
    cur2 = l2;
    while (cur2) {
      if (cur1->data < cur2->data) {
        break;
      }
      if (cur2->data == cur1->data) {
        insertElement(newList, cur1->data);
      }
      cur2 = cur2->next;
    }
    cur1 = cur1->next;
  }
  return newList;
}
