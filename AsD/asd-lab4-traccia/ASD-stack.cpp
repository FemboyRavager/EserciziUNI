// FILE DA MODIFICARE
#include "ASD-stack.h"
#include <string>

using namespace my_stack;
using namespace std;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack my_stack::createEmpty() {
  Stack newStack;
  newStack.tokens = new Elem[BLOCKDIM];
  newStack.size = 0;
  newStack.maxsize = BLOCKDIM;
  return newStack;
}

/* restituisce true se lo stack e' vuoto */
bool my_stack::isEmpty(const Stack &st) { return !((bool)st.size); }

void resize(Stack &st, bool increase) {
  if (increase) {
    //cerr << "Resizing\n";
    Elem *newTokens = new Elem[st.maxsize + BLOCKDIM];
    for (unsigned int i = 0; i < st.size; i++) {
      newTokens[i] = st.tokens[i];
    }
    delete[] st.tokens;
    st.tokens = newTokens;
    st.maxsize += BLOCKDIM;
  } else {
    Elem *newTokens = new Elem[st.maxsize - BLOCKDIM];
    for (unsigned int i = 0; i < st.size; i++) {
      newTokens[i] = st.tokens[i];
    }
    delete[] st.tokens;
    st.tokens = newTokens;
    st.maxsize -= BLOCKDIM;
  }
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
/* NB: se stack implementato con array dinamico,
   quando necessario implementare ridimensionamento in espansione*/
void my_stack::push(const Elem el, Stack &st) {
  if (st.size == st.maxsize) {
    resize(st, 1);
  }
  for (unsigned int i = 0; i < st.size; i++) {
  }
  st.tokens[st.size] = el;
  st.size++;
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
/* NB: se stack implementato con array dinamico,
   quando necessario implementare ridimensionamento in contrazione*/
Elem my_stack::pop(Stack &st) {
  if (st.size == 0) {
    //cerr << "SIZE";
    string child = "Empty stack, cannot pop\n";
    throw child;
  }
  Elem retElem;
  retElem = st.tokens[st.size - 1];
  st.size--;
  if (st.maxsize - st.size >= BLOCKDIM) {
    resize(st, 0);
  }
  return retElem;
}


Elem top(Stack &st) {
  if (st.size == 0) {
    string child = "Empty stack, cannot pop\n";
    throw child;
  }
  Elem retElem;
  retElem = st.tokens[st.size - 1];
  return retElem;
}

/*
int main() {
  try {
    Stack st = createEmpty();
    token tok;
    tok.k = NUMERO;
    tok.val = 42;
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    push(tok, st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    print(st);
    tok.k = PARENTESI_APERTA;
    push(tok, st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    print(st);
    tok.k = OP_MOLTIPLICAZIONE;
    push(tok, st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    print(st);
    tok.k = NUMERO;
    tok.val = 6549;
    push(tok, st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    pop(st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    pop(st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    pop(st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    pop(st);
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    if (isEmpty(st))
      cerr << "Vuota \n";
    else
      cerr << "Non vuota\n";
    for (int i=0;i<200; i++) {
      push(tok, st);
    }
    print(st);
  } catch (string err) {
    cerr << err;
  }
}*/
