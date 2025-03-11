#include "string_list.h"
#include <iostream>

using namespace std;

struct pollicinoStep {
  char dir;
  pollicinoStep *next;
};

typedef pollicinoStep *step;

void pollicinoTailInsert(step &l, char s) {
  if (!l) {
    string child = "\n==ERROR nonexistent list\n";
    throw child;
  }
  step cur = l;
  while (cur->next != nullptr) {
    // cerr << "--" << cur->data << " | " << cur->next << endl;
    cur = cur->next;
    // cerr << "--->" << cur->data << " | " << cur->next << endl;
  }
  // cerr << "Yay" << endl;
  step aux = new pollicinoStep;
  aux->dir = s;
  aux->next = nullptr;
  cur->next = aux;
}

void FaiUnPasso(step &step, char dir);
void FaiUnPassoIndietro(step &step);
void Stampa(step &step);
char Direzione(step &mov);

int main() { 
  step Pollicino = new pollicinoStep;
  Pollicino->dir='D';
  pollicinoTailInsert(Pollicino, 'U');
  pollicinoTailInsert(Pollicino, 'R');
  pollicinoTailInsert(Pollicino, 'L');
  step cur = Pollicino;
  step prev = Pollicino;
  int i=0;
  while (cur) {
    cout <<"i:"<<i << "-> "<< cur->dir << "\n";
    prev = cur;
    cur=cur->next;
    i++;
  }
  cout << endl;
  cout << "Last movement: "<< Direzione(Pollicino)<<endl;
}


char Direzione(step& mov) {
  step prev = mov;
  step cur = mov;
  while (cur) {
    prev = cur;
    cur=cur->next;
  }
  return prev->dir;
}
