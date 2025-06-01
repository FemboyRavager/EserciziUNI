#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) { return (tr == tragittoVuoto); }

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  cerr << "\n\n";
  cerr << "\nInserting: "<< t.distanza << " " << t.citta << " in tragitto: ";
  //printTragitto(tr);
  if (isEmpty(tr)) {
    cerr << "tr empty\n";
    Tragitto aux = new TragittoElem;
    aux->tappa = t;
    tr = aux;
    return;
  }
  cerr << "tr not empty\n";
  Tragitto aux = new TragittoElem;
  aux->tappa = t;
  aux->next = tragittoVuoto;
  Tragitto cur = tr;
  while (cur->next) {
    cerr << "At least two elem";
    cur=cur->next;
    cerr << "FUCK";
  }
  cerr << "????";
  cur->next = aux;
  // TO DO
}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  // TO DO
  if (isEmpty(tr)) {
    return false;
  }
  t = tr->tappa;
  tr = tr->next;
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  if (isEmpty(tr)) {
    return;
  }
  cout << tr->tappa.distanza << " " << tr->tappa.citta<< " ";
  printTragitto(tr->next);
  // TO DO
  // tragitto::Tragitto cur = tr;
  // while (cur) {
  //   cout << "[ " << tr->tappa.distanza << " " << tr->tappa.citta << " ]";
  //   cur=cur->next;
  // }
}
