#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione.
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo,
a livello concettuale, su un puntatore a un nodo dell'albero.
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */

/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
  Label label;
  treeNode *firstChild;
  treeNode *nextSibling;
};

/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree &t) {
  return (!t);
}

/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
Tree getNode(const tree::Label targetL, Tree t) {
  if (isEmpty(t)) {
    return emptyTree;
  }
  if (t->label == targetL) {
    return t;
  }
  Tree tmp = emptyTree;
  tmp = getNode(targetL, t->firstChild);
  if (tmp) {
    return tmp;
  }
  tmp = getNode(targetL, t->nextSibling);
  if (tmp) {
    return tmp;
  }
  return emptyTree;
}

Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree &t) {
  if (labelOfNodeInTree == emptyLabel) {
    if (isEmpty(t)) {
      Tree aux = new treeNode;
      aux->firstChild = emptyTree;
      aux->nextSibling = emptyTree;
      aux->label = labelOfNodeToAdd;
      t = aux;
      cerr << "Added " << aux->label << " as root\n";
      return OK;
    } else {
      return FAIL;
    }
  }

  Tree father = getNode(labelOfNodeInTree, t);
  if (!father) {
    return FAIL;
  }
  Tree aux = new treeNode;
  aux->firstChild = emptyTree;
  aux->nextSibling = emptyTree;
  aux->label = labelOfNodeToAdd;

  if (!(father->firstChild)) { // no first child
    father->firstChild = aux;
    cerr << "Added " << aux->label << " as firstChild\n";
    return OK;
  }

  Tree cur = father->firstChild; // exists first child
  if (cur->label == labelOfNodeToAdd) {
    return FAIL;
  }
  Tree prev = cur;
  while (cur) { // scroll through siblings
    if (cur->label == labelOfNodeToAdd) {
      return FAIL;
    }
    prev = cur;
    cur = cur->nextSibling;
  }
  prev->nextSibling = aux;
  if (labelOfNodeToAdd == "ponginae")
    cerr << "YAY";
  cerr << "Added " << aux->label << " as sibling\n";

  return OK;
}

/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree &t) {
  Tree deletionTarget = getNode(l, t);
  Label fatherLabel = tree::father(l, t);
  Tree father = getNode(fatherLabel, t);
  cerr << "Target: " << deletionTarget->label << " child of " << father->label << endl;
  Tree childFinder = father->firstChild;
  if (!(deletionTarget->firstChild)) {   // target has no children
    if (childFinder == deletionTarget) { // target is firstChild
      if (childFinder->nextSibling) {
        father->firstChild = childFinder->nextSibling;
        delete childFinder;
        return OK;
      }
    }
    while (childFinder->nextSibling && childFinder->nextSibling != deletionTarget) {
      childFinder = childFinder->nextSibling;
    }
    // childfinder is now previous sibling of target
    if (deletionTarget->nextSibling) {
      childFinder->nextSibling = deletionTarget->nextSibling;
      delete deletionTarget;
      return OK;
    }
    childFinder->nextSibling = emptyTree; // case target no next sibling
    delete deletionTarget;
    return OK;
  }
  // target has children
  Tree targetLastChild = deletionTarget->firstChild;
  while (targetLastChild->nextSibling) {
    targetLastChild = targetLastChild->nextSibling;
  }

  if (childFinder == deletionTarget) { // childFinder is currently father->firstChild
    father->firstChild = deletionTarget->firstChild;
    if (deletionTarget->nextSibling) {
      targetLastChild->nextSibling = deletionTarget->nextSibling;
    }
    delete deletionTarget;
    return OK;
  }
  while (childFinder->nextSibling && childFinder->nextSibling != deletionTarget) {
    childFinder = childFinder->nextSibling;
  }
  // childfinder is now previous sibling of target
  childFinder->nextSibling = deletionTarget->firstChild; // childfinder is still previous sibling
  if (deletionTarget->nextSibling) {
    targetLastChild->nextSibling = deletionTarget->nextSibling;
  }
  return OK;
}

/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione iterativa, ma implementata ricorsivamente
// (può anche non essere ricorsiva la deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error deleteElemRAux(const Label l, Tree &t) {
  if (!t) {
    return FAIL;
  }
  // cerr << "Examining: " << t->label << endl;
  if (t->label == l) {
    // cerr << "Found node with label: " << t->label << endl;
    if (!(t->firstChild)) {
      if (t->nextSibling) {
        Tree tmp = t->nextSibling;
        delete t;
        t = tmp;
        return OK;
      }
      delete t;
      t = emptyTree;
      return OK;
    }
    Tree tmp = t->firstChild;
    delete t;
    t = tmp;
    return OK;
  }
  Error deletionOccurred = deleteElemRAux(l, t->nextSibling);
  if (deletionOccurred == OK) {
    return OK;
  }
  deletionOccurred = deleteElemRAux(l, t->firstChild);
  if (deletionOccurred == OK) {
    return OK;
  }
  return FAIL;
}

Error tree::deleteElemR(const Label l, Tree &t) {
  if (!t) {
    return FAIL;
  }
  if (t->label == l) {
    if (t->firstChild) {
      return FAIL;
    }
    delete t;
    t = emptyTree;
    return OK;
  }
  return deleteElemRAux(l, t->firstChild);
}

/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero
// (o sottoalbero) t e se il padre esiste.
// Restituisce la costante emptyLabel altrimenti

Label fatherAux(const Label l, const Tree &t, bool &found) {
  if (!t) {
    return emptyLabel;
  }
  // cerr << "Examining: " << t->label << endl;
  if (t->label == l) {
    found = 1;
    return t->label; // temporary return of the child
  }
  Label result = emptyLabel;
  result = fatherAux(l, t->nextSibling, found);
  if (result != emptyLabel) {
    return result;
  }
  result = fatherAux(l, t->firstChild, found);
  if (found) {
    found = 0;
    return t->label;
  }
  if (result != emptyLabel) {
    return result;
  }
  return emptyLabel;
}

Label tree::father(const Label l, const Tree &t) {
  if (!t) {
    return emptyLabel;
  }
  if (t->label == l) {
    return emptyLabel;
  }
  bool found = 0;
  return fatherAux(l, t, found);
}

/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  return lst;
}

/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree &t) {
  return -1;
}

/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
// (può anche non essere ricorsiva la ancestorsR, ma deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  return lst;
}

/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  return lst;
}

/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree &t) {
  return emptyLabel;
}

/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree &t) {
  return false;
}

/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst
int tree::numNodes(const Tree &t) {
  return -1;
}

/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty() {
  Tree newTree = emptyTree;
  return newTree;
}

/*******************************************************************************************************/
// Visualizzazione possibilmente strutturata come visto a lezione

void printAux(const Tree &t, int layer) {
  if (!t) {
    layer--;
    return;
  }
  printAux(t->nextSibling, layer);
  for (int i = 0; i <= layer; i++) {
    cout << "--";
  }
  cout << t->label << endl;
  layer++;
  printAux(t->firstChild, layer);
}

void printTree(const Tree &t) {
  if (!t) {
    return;
  }
  int useless = 0;
  cout << endl;
  printAux(t, useless);
}

/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando qualche funzione ausiliaria che operi
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione...
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream &str) {
  Tree t = createEmpty();
  string line;
  Label rootLabel, fatherLabel, childLabel;
  getline(str, line);
  istringstream instream; // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
  instream.clear();
  instream.str(line);
  instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
  addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
  getline(str, line);                // poi si iniziano a scansionare le righe seguenti
  instream.clear();
  instream.str(line);
  while (!str.eof()) {
    instream >> fatherLabel;           // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
    removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
    while (!instream.eof())            // finche' la riga corrente non e' terminata
    {
      instream >> childLabel;              // leggo la prossima etichetta
      removeBlanksAndLower(childLabel);    // la normalizzo
      addElem(fatherLabel, childLabel, t); // e la attacco al padre
    }
    getline(str, line);
    instream.clear();
    instream.str(line);
  }
  str.clear();
  return t;
}

/****************************************************************/
Tree readFromFile(string nome_file) {
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {
    cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n";
    return createEmpty();
  }
  return readFromStream(ifs);
}
