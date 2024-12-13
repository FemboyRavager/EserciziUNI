#include "string_ord_list.h"
#include <iostream>

using namespace std;

// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista
// ordinata
void insertElement(ordList &l, string s) {
  ordList cur = l;
  ordList prev = cur;
  if (!l) {
    // cerr << "List empty. Initializing.\n";
    l = new cell;
    l->next = nullptr;
    l->data = s;
    // cerr << "List initialized to: " << l->data << " , next: " << l->next <<
    // endl;
  } else {
    int i = 0;
    while (cur && i < 10) {
      // cerr << "Attempting to insert: " << s << endl;
      // cerr << "Current cell: " << cur->data << " , next: " << cur->next <<
      // endl;
      if (s < cur->data) {
        ordList aux = new cell;
        aux->next = cur;
        aux->data = s;
        if (cur == l) { // inserimento in testa
          // cerr << "--Attempting to insert " << s << " at head" << endl;
          aux->next = cur;
          l = aux;
        } else {
          // cerr << "--Attempting to insert " << s << " between " << prev->data
          // << " and " << cur->data << endl;
          prev->next = aux;
          // cerr << "--Inserted " << s << " before " << cur->data << endl;
        }
        while (cur && i < 20) {
          // cerr << cur->data << ((cur->next) ? "->" : "\n");
          i++;
          cur = cur->next;
        }
        return;
      }
      prev = cur;
      cur = cur->next;
      // //cerr << "--Current cell: " << cur->data << " , next: " << cur->next
      //      << endl;
      i++;
      // cerr << "==i: " << i << endl;
    }
    // cerr << "--Reached end of list. Appending " << s << " after " <<
    // prev->data  << endl;
    ordList aux = new cell;
    aux->data = s;
    aux->next = nullptr;
    prev->next = aux;
    // cerr << "====END WHILE" << endl;
  }
  // cerr << "======END INSERT" << endl;
  cur = l;
  int i = 0;

  while (cur && i < 20) {
    // cerr << cur->data << ((cur->next) ? "->" : "\n");
    i++;
    cur = cur->next;
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
    // cerr << cur->data << ((cur->next) ? "->" : "\n");
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
  ordList cur = l;
  unsigned int j = 1;
  while (cur && j != i) {
    // cerr << cur->data << ((cur->next) ? "->" : "\n");
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
  ordList cur = l;
  ordList prev = l;
  for (unsigned int j = 0; j < (i - 1) && cur; j++) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    prev = cur;
    cur = cur->next;
  }
  prev->next = cur->next;
  delete cur;
}

// cancella dalla lista ordinata l il primo elemento contenente s
void deleteElementOnce(ordList &l, std::string s) {
  ordList cur = l;
  ordList prev = l;
  while (cur && cur->data != s) {
    prev = cur;
    cur = cur->next;
  }
  if (!cur)
    return;
  // cout<<"Found element "<<s<<endl;
  if (cur == l) { // first cell
    l = l->next;
    delete cur;
  }
  if (cur->next == nullptr) { // last cell
    prev->next = nullptr;
    delete cur;
  }
  prev->next = cur->next;
}

// cancella dalla lista ordinata l tutti gli elementi contenenti s
void deleteAllElements(ordList &l, std::string s) {
  ordList cur = l;
  ordList prev = l;
  while (cur) {
    // cerr << "Current cell data: " << cur->data<<endl;
    if (cur->data == s) {
      if (cur == l) { // s in prima cella
        // cerr << s << " found in first cell";
        delete l;
        l = l->next;
        // print(l);
      }
      /*
      if (!cur->next) {
        cerr << s << " found in last cell";
      }
      */
      prev->next = cur->next;
      cur = prev->next;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
}

// restituisce true se le due liste contengono le stesse stringhe (con la stessa
// molteplicità) false altrimenti
bool listAreEqual(const ordList &l1, const ordList &l2) {
  ordList cur1 = l1;
  ordList cur2 = l2;
  bool areEqual = true;
  while (cur1 && cur2 && areEqual) {
    if (cur1->data != cur2->data) {
      areEqual = false;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  if (areEqual) {
    return true;
  }
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
    // cerr << "\nnewList: ";
    // printList(newList);
    // cerr << "\nCurrent cur1: " << cur1->data << endl;
    alreadyPresent = false;
    if (cur1 == l1) {
      // cerr << "\nInserting first element\n";
      insertElement(newList, cur1->data);
    } else {
      // cerr << "\nEntered else. Current newListCur: ";
      // printList(newListCur);
      // cerr << endl;
      newListCur = newList;
      while (newListCur) {
        // cerr << "==Current newListCur: ";
        // printList(newListCur);
        // cerr << "\n====Comparing " << cur1->data << " and " <<
        // newListCur->data << endl;
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
    // cerr << "\nnewList: ";
    // printList(newList);
    // cerr << "\nCurrent cur2: " << cur2->data << endl;
    alreadyPresent = false;
    // cerr << "\nEntered else. Current newListCur: ";
    // printList(newListCur);
    // cerr << endl;
    newListCur = newList;
    while (newListCur) {
      // cerr << "==Current newListCur: ";
      // printList(newListCur);
      // cerr << "\n====Comparing " << cur2->data << " and " <<
      // newListCur->data << endl;
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
  ordList newListCur = newList;
  ordList cur1 = l1;
  ordList cur2 = l2;
  while (cur1) {
    if ( cur1->next && cur1->data == cur1->next->data) { //if more than one string in a row
      cur1=cur1->next;
      continue;
    }
    cur2 = l2;
    while (cur2) {
      //cerr << "\n==Comparing " << cur1->data << " with " << cur2->data << endl;
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
