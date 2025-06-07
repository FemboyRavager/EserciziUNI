/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"
#include <queue>
#include <utility>

// Funzioni ausiliarie che non appartengono al TDD

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2) {
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1;
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;

  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1;
  else
    return index2;
}

void printPQ(priorityQueue::PriorityQueue pq) {
  cout << "Current PQ:    ";
  for (int i = 0; i < pq.size; i++) {
    cout << "[" << pq.data[i].veicolo->plate << ":" << pq.data[i].timeStamp << "] ";
  }
  cout << endl;
}

void swapNodes(priorityQueue::PriorityQueue &pq, int v1index, int v2index) {
  priorityQueue::Elem aux = pq.data[v1index];
  pq.data[v1index] = pq.data[v2index];
  pq.data[v2index] = aux;
}

void moveDown(priorityQueue::PriorityQueue &pq) {
  // cerr << "moveDown:\n";
  int sinker = 0;
  if (pq.size < 2) {
    return;
  }
  int firstChild = sinker * 2 + 1;
  int secondChild = sinker * 2 + 2;
  // cerr << " sinker: " << sinker << endl;
  if (!pq.data[firstChild].veicolo && !pq.data[secondChild].veicolo && firstChild < pq.size && secondChild < pq.size) {
    // cerr << "\tNo children\n";
    return;
  }
  int minChild = 0;
  while ((pq.data[firstChild].timeStamp < pq.data[sinker].timeStamp && firstChild < pq.size) || ((pq.data[secondChild].timeStamp < pq.data[sinker].timeStamp && secondChild < pq.size))) { // esiste almeno un figlio
    // cerr << "\tAlmeno un figlio\n";
    if (firstChild < pq.size && secondChild < pq.size) { // ha 2 figli
      // cerr << "\t Ha 2 figli\n";
      (pq.data[firstChild].timeStamp < pq.data[secondChild].timeStamp) ? minChild = firstChild : minChild = secondChild;
      // cerr << "\t sinker index: "<< sinker<< " timestamp: "<<pq.data[sinker].timeStamp<<endl;
      // cerr << "\t minChild index: "<< minChild<< " timestamp: "<<pq.data[minChild].timeStamp<<endl;
    } else if (secondChild >= pq.size) { // solo figlio SX
      // cerr << "\t Solo figlio SX";
      minChild = firstChild;
    } else {
      // cerr << "\t Solo figlio DX";
      minChild = secondChild;
    }
    swapNodes(pq, sinker, minChild);
    sinker = minChild;
    firstChild = sinker * 2 + 1;
    secondChild = sinker * 2 + 2;
  }
}

void moveUp(priorityQueue::PriorityQueue &pq, int floater) {
  // TODO
  ////cerr << "Move Up:\n";
  while (floater != 0 && pq.data[floater].timeStamp < pq.data[(floater - 1) / 2].timeStamp) {
    // cerr << "\telem: " << pq.data[floater].timeStamp << " and father: " << pq.data[(floater - 1) / 2].timeStamp << endl;
    //  priorityQueue::Elem aux = pq.data[floater];
    //  pq.data[floater] = pq.data[(floater - 1) / 2];
    //  pq.data[(floater - 1) / 2] = aux;
    swapNodes(pq, floater, (floater - 1) / 2);
    floater = (floater - 1) / 2;
  }
}

// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim) {
  PriorityQueue pq;
  pq.maxsize = dim;
  pq.size = 0;
  pq.data = new Elem[dim];
  // TODO
  return pq;
}

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq) {
  // TODO
  return (pq.size == 0);
}

// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna
// TRUE nel caso in cui la PriorityQueue sia piena ritorna FALSE suggerimento:
// inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem) {
  // TODO
  // printPQ(pq);
  // cerr << "Inserting " << elem.veicolo->plate       << ", timestamp: " << elem.timeStamp << " on PQ: ";
  if (pq.size == pq.maxsize) {
    return false;
  }
  pq.data[pq.size] = elem;
  pq.size++;
  // printPQ(pq);
  moveUp(pq, pq.size - 1);
  // printPQ(pq);
  // cerr << endl;
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res) {
  // TODO
  if (pq.size == 0) {
    return false;
  }
  res = pq.data[0];
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq) {
  // TODO
  // cerr << "Calling deleteMin on pq of size: " << pq.size << endl;
  if (pq.size == 0) {
    return false;
  }
  // printPQ(pq);
  // cerr << "Popping elem "<< pq.data[0].veicolo->plate<<":"<<pq.data[0].timeStamp<<endl;
  pq.data[0] = pq.data[pq.size - 1];
  pq.size--;
  moveDown(pq);
  // printPQ(pq);
  // cerr << endl;
  return true;
}
