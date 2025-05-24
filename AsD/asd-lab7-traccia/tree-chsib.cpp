#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi,
scegliendo di volta in volta la formulazione più adatta a dare la specifica di
una funzione. Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando
operiamo su un albero, sia quando operiamo, a livello concettuale, su un
puntatore a un nodo dell'albero. Questo approccio e' corretto in quanto un
albero (o sottoalbero) è un puntatore a una struct di tipo treeNode: un albero è
identificato univocamente dal puntatore alla sua radice */

/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo
// figlio e il puntatore al prossimo fratello NON manteniamo il puntatore al
// padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per
// altre)
struct tree::treeNode {
  Label label;
  treeNode *firstChild;
  treeNode *nextSibling;
};

/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree &t) { return (t == emptyTree); }

/*******************************************************************************************************/

Tree findNode(Tree t, Label labelOfNodeInTree) {
  // cerr << "Looking for " << labelOfNodeInTree << endl;
  if (isEmpty(t)) {
    // cerr << "\tNo more children sadge\n";
    return emptyTree;
  }
  // cerr << "\tVisiting " << t->label << ", looking for " <<
  // labelOfNodeInTree<< endl;
  if (t->label == labelOfNodeInTree) {
    // cerr << "\tFound match :)\n";
    return t;
  }
  Tree foundTree = emptyTree;
  Tree auxTree = t->firstChild;
  foundTree = findNode(auxTree, labelOfNodeInTree); // visita figlio
  if (!isEmpty(foundTree)) {
    return foundTree;
  }
  auxTree = t->nextSibling;   // ritorna da visite figli, assegna primo fratello
  while (!isEmpty(auxTree)) { // while fratello esiste
    foundTree = findNode(auxTree, labelOfNodeInTree); // visita fratello
    if (!isEmpty(foundTree)) {
      return foundTree;
    }
    auxTree = auxTree->nextSibling; // scorri fratelli
  }
  return emptyTree; // se arrivo quì non l'ho trovato
}

// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd,
                    Tree &t) {
  if (labelOfNodeInTree == emptyLabel && isEmpty(t)) { // aggiunta radice
    t = new treeNode;
    t->label = labelOfNodeToAdd;
    t->firstChild = emptyTree;
    t->nextSibling = emptyTree;
    // cerr << labelOfNodeToAdd << " added as root\n";
    return OK;
  }
  if (labelOfNodeInTree == emptyLabel &&
      !isEmpty(t)) { // tentativo aggiunta radice ad albero esistente
    return FAIL;
  }
  if (labelOfNodeInTree != emptyLabel &&
      isEmpty(t)) { // tentativo aggiunta figlio ad albero vuoto
    return FAIL;
  }
  // controlliamo che non sia già nell'albero
  // cerr << "=Checking if " << labelOfNodeToAdd << " is already in tree" <<
  // endl;
  if (!isEmpty(findNode(t, labelOfNodeToAdd))) {
    return FAIL;
  }
  // cerr << "=Checking if parent " << labelOfNodeInTree << " is present in
  // tree\n";
  Tree fatherNode = findNode(t, labelOfNodeInTree);
  if (isEmpty(fatherNode)) {
    return FAIL;
  }
  Tree insertPoint = fatherNode->firstChild;
  Tree aux = new treeNode;
  aux->label = labelOfNodeToAdd;
  aux->firstChild = emptyTree;
  aux->nextSibling = emptyTree;
  if (isEmpty(insertPoint)) { // aggiungo come figlio diretto
    fatherNode->firstChild = aux;
    // cerr << labelOfNodeToAdd << " added as child of " << fatherNode->label <<
    // endl;
    return OK;
  }
  while (!isEmpty(insertPoint->nextSibling)) { // scorro i fratelli
    insertPoint = insertPoint->nextSibling;
  }
  // dovrei essere all'ultimo fratello
  insertPoint->nextSibling = aux;
  // cerr << labelOfNodeToAdd << " added as sibling of " << insertPoint->label<<
  // endl;
  return OK;
}

/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con
// la Label l e collega al padre di tale nodo tutti i suoi figli Restituisce
// FAIL se si tenta di cancellare la radice e questa ha dei figli (non si
// saprebbe a che padre attaccarli) oppure se non esiste un nodo nell'albero
// etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree &t) { //odio
  if (t == emptyTree)
    return FAIL;

  //nodo da cancellare è la radice
  if (t->label == l) {
    if (t->firstChild != emptyTree)
      return FAIL;
    delete t;
    t = nullptr;
    return OK;
  }

  Tree parent = emptyTree;
  Tree current = t;
  Tree prev = emptyTree;

  while (current != emptyTree) {
    //cerco tra i figli di current
    Tree child = current->firstChild;
    prev = emptyTree;

    while (child != emptyTree) {
      if (child->label == l) {
        //trovato il nodo da cancellare

        //collegamento dei figli di child al padre (current)
        if (prev == emptyTree) {
          //child primo figlio
          current->firstChild = child->firstChild;
        } else {
          //child è fratello più avanti
          prev->nextSibling = child->firstChild;
        }

        //se child ha figli, trova l’ultimo e collega il resto dei fratelli
        if (child->firstChild != emptyTree) {
          Tree last = child->firstChild;
          while (last->nextSibling != emptyTree) {
            last = last->nextSibling;
          }
          last->nextSibling = child->nextSibling;
        } else {
          //altrimenti collega direttamente il fratello successivo
          if (prev == emptyTree)
            current->firstChild = child->nextSibling;
          else
            prev->nextSibling = child->nextSibling;
        }

        delete child;
        return OK;
      }

      prev = child;
      child = child->nextSibling;
    }

    //non trovato in current, passo al prossimo sottoalbero
    if (current->firstChild != emptyTree) {
      parent = current;
      current = current->firstChild;
    } else if (current->nextSibling != emptyTree) {
      current = current->nextSibling;
    } else {
      //risalgo fino a trovare un fratello non ancora visitato
      while (parent != emptyTree && parent->nextSibling == emptyTree) {
        //risalita
        current = parent;
        //troviamo il nonno per risalire ancora (serve ciclo interno)
        Tree finder = t;
        Tree auxParent = emptyTree;
        while (finder != emptyTree && finder->firstChild != current) {
          Tree sibling = finder->firstChild;
          while (sibling != emptyTree && sibling != current) {
            auxParent = finder;
            finder = sibling;
            sibling = sibling->nextSibling;
          }
          if (sibling == current) {
            auxParent = finder;
            break;
          }
          finder = finder->firstChild;
        }
        parent = auxParent;
      }

      if (parent == emptyTree) {
        break;
      }

      current = parent->nextSibling;
      //aggiorno nuovo parent
      Tree finder = t;
      Tree tmpParent = emptyTree;
      while (finder != emptyTree && finder->firstChild != current) {
        Tree sibling = finder->firstChild;
        while (sibling != emptyTree && sibling != current) {
          tmpParent = finder;
          finder = sibling;
          sibling = sibling->nextSibling;
        }
        if (sibling == current) {
          tmpParent = finder;
          break;
        }
        finder = finder->firstChild;
      }
      parent = tmpParent;
    }
  }

  return FAIL; // nodo non trovato
}

/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione
// iterativa, ma implementata ricorsivamente (può anche non essere ricorsiva la
// deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error tree::deleteElemR(const Label l, Tree &t) { return FAIL; }

/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo
// esiste nell'albero (o sottoalbero) t e se il padre esiste. Restituisce la
// costante emptyLabel altrimenti
Label tree::father(const Label l, const Tree &t) {
  if (isEmpty(t)) {
    return emptyLabel;
  }

  Tree currentChild = t->firstChild;
  while (!isEmpty(currentChild)) { // while per scorrere i fratelli
    if (currentChild->label == l) {
      return t->label; // trovato genitore
    }

    Label result = father(l, currentChild); // controllo il figlio attuale di t
    if (result != emptyLabel) {
      return result;
    }
    // scorro orizzontalmente i sibling
    currentChild = currentChild->nextSibling;
  }
  return emptyLabel; // se arrivo quì non l'ho trovato
}

/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati
// viste a lezione (non un Vector!!!): si riusi una implementazione del TDD
// list, adattandola a elementi di tipo string (nelle precedenti esercitazioni
// gli elementi erano int)
list::List tree::children(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  if (isEmpty(t)) {
    return lst;
  }

  Tree parent = findNode(t, l);
  if (isEmpty(parent)) {
    return lst;
  }
  // cerr << "Found parent: "<< parent->label<<endl;
  Tree currentChild = parent->firstChild;
  while (!isEmpty(currentChild)) {
    addBack(currentChild->label, lst);
    currentChild = currentChild->nextSibling;
  }
  return lst;
}

/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l;
// restituisce -1 se non esiste nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree &t) {
  Tree parent = findNode(t, l);
  if (isEmpty(parent)) {
    return -1;
  }
  // cerr << "Found parent: "<< parent->label<<endl;
  Tree currentChild = parent->firstChild;
  int count = 0;
  while (!isEmpty(currentChild)) {
    count++;
    currentChild = currentChild->nextSibling;
  }
  return count;
}

/*******************************************************************************************************/
// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le
// etichette di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo
// stesso La lista può essere implementata usando una delle strutture dati viste
// a lezione (non un Vector) (può anche non essere ricorsiva la ancestorsR, ma
// deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  return lst;
}

/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le
// etichette di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo
// stesso La lista può essere implementata usando una delle strutture dati viste
// a lezione (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree &t) {
  list::List lst = list::createEmpty();
  return lst;
}

/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2,
                                const Tree &t) {
  return emptyLabel;
}

/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene
// all'albero t e false altrimenti
bool tree::member(const Label l, const Tree &t) {
  return (!isEmpty(findNode(t, l)));
}

/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita
// ricorsiva in depthfirst
int tree::numNodes(const Tree &t) {
  if (isEmpty(t)) {
    return 0;
  }
  return 1 + numNodes(t->firstChild) + numNodes(t->nextSibling);

  return -1;
}

/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty() { return emptyTree; }

/*******************************************************************************************************/

void printAux(const Tree t, int depth) {
  if (isEmpty(t)) {
    // cerr << "------No child, sadge"<<endl;
    return;
  }

  Tree auxTree =
      t->nextSibling;      // ritorna da visite figli, assegna primo fratello
  if (!isEmpty(auxTree)) { // while fratello esiste
    // cerr << "------Now executing call on sibling"<<auxTree->label<<endl;
    printAux(auxTree, depth);
    auxTree = auxTree->nextSibling; // scorri fratelli
  }
  for (int i = 0; i < depth; i++) {
    cout << "--";
  }
  cout << t->label << endl;

  // cerr << "---------"<<t->label<<" exiting while\n";
  auxTree = t->firstChild;
  depth++;
  printAux(auxTree, depth);
  return;
}

// Visualizzazione possibilmente strutturata come visto a lezione
void printTree(const Tree &t) {
  if (isEmpty(t)) {
    // cerr << "------No child, sadge"<<endl;
    return;
  }
  printAux(t, 0);
}

/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che
// implementa l'albero: usa solo addElem e quindi e' ad un alto livello di
// astrazione Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque
// implementazione del TDD Tree Svantaggi: inefficiente: la addElem cerca ogni
// volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola
// per trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza
// ripetere la dispendiosa ricerca nell'albero; per renderla efficiente dovrei
// pero' accedere direttamente alla struttura dati chiamando qualche funzione
// ausiliaria che operi sui nodi dell'albero, rinunciando a scrivere codice
// modulare, chiaro e ad un ragionevole livello di astrazione... Non esiste
// un'opzione migliore tra le due: se il codice deve essere efficiente, è
// opportuno scrivere una funzione ad hoc per una determinata implementazione;
// se il codice deve essere riutilizzabile, bisogna limitarsi a usare le
// funzioni offerte dall' interfaccia del TDD in modo che la funzione continui
// ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream &str) {
  Tree t = createEmpty();
  string line;
  Label rootLabel, fatherLabel, childLabel;
  getline(str, line);
  istringstream instream; // uso una variabile di tipo istringstream per poter
                          // scandire i pezzi di ogni riga usando >>
  instream.clear();
  instream.str(line);
  instream >> rootLabel; // il primo elemento che si incontra nel file e'
                         // l'etichetta della radice, per convenzione su come
                         // deve essere fatto il file
  addElem(emptyLabel, rootLabel,
          t); // la si inserisce nell'albero vuoto, indicando che il padre non
              // c'e' (primo argomento emptyLabel)
  getline(str, line); // poi si iniziano a scansionare le righe seguenti
  instream.clear();
  instream.str(line);
  while (!str.eof()) {
    instream >>
        fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta
                     // del nodo padre e gli altri sono le etichette dei figli
    removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
    while (!instream.eof()) // finche' la riga corrente non e' terminata
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
  ifstream ifs(
      nome_file
          .c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {
    cout << "\nErrore apertura file, verificare di avere inserito un nome "
            "corretto\n";
    return createEmpty();
  }
  return readFromStream(ifs);
}
