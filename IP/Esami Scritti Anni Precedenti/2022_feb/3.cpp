#include <iostream>
using namespace std;

struct turista {
  string codFisc;
  string cognome;
  string nome;
  string nazionalità;
};

struct cell {
  turista data;
  cell *next;
};
typedef cell *insiemeTuristi;

bool StessoTurista(turista a, turista b) {
  if (a.codFisc == b.codFisc)
    return true;
  return false;
}

void InserisciTurista(insiemeTuristi &l, turista t);
void CancellaTurista(insiemeTuristi &l, turista t);
bool InsiemeVuoto(insiemeTuristi l);
void StampaInsiemeTuristi(insiemeTuristi l);
insiemeTuristi UnioneTraInsiemi(insiemeTuristi l1, insiemeTuristi l2);

insiemeTuristi UnioneTraInsiemi(insiemeTuristi l1, insiemeTuristi l2) {
  insiemeTuristi setUnion = l1;
  insiemeTuristi cur1 = setUnion;
  insiemeTuristi cur2 = l2;
  while (cur2) {
    bool alreadyPresent = false;
    cur1 = setUnion;
    while (cur1) {
      //cerr << "==Comparing " << cur1->data.codFisc << " and "
      //     << cur2->data.codFisc << endl;
      if (cur1->data.codFisc == cur2->data.codFisc) {
        //cerr << "====Already present" << endl;
        alreadyPresent = true;
        break;
      }
      cur1 = cur1->next;
    }
    //cerr << "==cur2: " << cur2->data.codFisc
    //     << (alreadyPresent ? "Presente" : "Assente") << endl;
    if (!alreadyPresent && cur2) {
      //cerr << "====Inserting " << cur2->data.codFisc << endl;
      insiemeTuristi aux = new cell;
      aux->next = setUnion;
      aux->data = cur2->data;
      setUnion = aux;
    }
    cur2 = cur2->next;
  }
  return setUnion;
}

int main() {
  turista a;
  a.codFisc = "aaa";
  turista b;
  b.codFisc = "bbb";
  insiemeTuristi l1 = new cell;
  insiemeTuristi l2 = new cell;
  l1->data.codFisc = "0";
  l2->data.codFisc = "0";

  insiemeTuristi cur = l1;
  for (int i = 0; i < 10; i++) {
    a.codFisc = i + 97;
    insiemeTuristi aux = new cell;
    aux->data = a;
    aux->next = nullptr;
    cur->next = aux;
    cur = cur->next;
  }
  cur = l2;
  for (int i = 0; i < 10; i++) {
    b.codFisc = i + 102;
    insiemeTuristi aux = new cell;
    aux->data = b;
    aux->next = nullptr;
    cur->next = aux;
    cur = cur->next;
  }

  cur = l1;
  while (cur) {
    cout << cur->data.codFisc << (cur->next ? "->" : "\n");
    cur = cur->next;
  }

  cur = l2;
  while (cur) {
    cout << cur->data.codFisc << (cur->next ? "->" : "\n");
    cur = cur->next;
  }

  cerr << "Stesso turista?--->" << (StessoTurista(a, b) ? "Si" : "No") << endl;

  cerr << endl << "Unione: " << endl;
  insiemeTuristi unione = UnioneTraInsiemi(l1, l2);

  cur = unione;
  while (cur) {
    cout << cur->data.codFisc << (cur->next ? "->" : "\n");
    cur = cur->next;
  }
}
