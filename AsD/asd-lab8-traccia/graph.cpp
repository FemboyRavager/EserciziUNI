#include <iostream>

#include "graph.h"

using namespace graph;

struct halfEdgeVertex {
  Label label;
  Graph destinazione;
  Weight weight;
  halfEdgeVertex *next;
};

struct graph::vertexNode {
  // TODO
  bool isVisited;
  Label label;
  Graph nextVertex;
  halfEdgeVertex *firstHalfEdge;
};
typedef halfEdgeVertex *Edge;
const Edge emptyEdge = nullptr;
/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/
// Restituisce il grafo vuoto
Graph graph::createEmptyGraph() {
  // TODO
  return emptyGraph;
}

// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false
bool graph::addVertex(Label l, Graph &g) {
  // TODO
  if (isEmpty(g)) {
    g = new vertexNode;
    g->nextVertex = emptyGraph;
    g->firstHalfEdge = emptyEdge;
    g->isVisited = 0;
    g->label = l;
    //cerr << "Added to empty graph:" << g->label << endl;
    return 1;
  }
  Graph cur = g;
  while (cur) {
    if (cur->label == l) {
      return 0;
    }
    cur = cur->nextVertex;
  }
  cur = g;
  while (cur->nextVertex) {
    cur = cur->nextVertex;
  }
  Graph aux = new vertexNode;
  aux->nextVertex = emptyGraph;
  aux->firstHalfEdge = emptyEdge;
  aux->isVisited = 0;
  aux->label = l;
  cur->nextVertex = aux;
  return 1;
}

bool addStartDest(Graph start, Graph end, Graph &g, Edge &aux) {
  //cerr << "addStartDest\n";
  //cerr << " start: " << start->label << endl;
  //cerr << " end: " << end->label << endl;

  if (start->firstHalfEdge != emptyEdge) { // ha almeno un arco
    Edge edgeCur = start->firstHalfEdge;
    Edge prev = edgeCur;
    while (edgeCur) { // scorro fino ad arrivare ad ultimo nodo arco
      //cerr << "  start: " << start->label << endl;
      //cerr << "  end: " << end->label << endl;
      //cerr << "  edgeCur: " << edgeCur->label << endl;
      if (edgeCur->label == end->label) {
        //cerr << "   Already present\n";
        delete aux;
        return 0;
      }
      //cerr << "  Not present yet :)))\n";

      prev = edgeCur;
      edgeCur = edgeCur->next;
    }
    prev->next = aux;
    //cerr << " Added " << prev->next->label << " as edge to " << start->label<< endl;
    return 1;
  }
  // non ha archi
  //cerr << " No edges\n";
  start->firstHalfEdge = aux;
  //cerr << " Added " << start->firstHalfEdge->label << " as first edge to "<< start->label << endl;
  return 1;
}

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph &g) {
  // TODO
  if (isEmpty(g)) {
    return 0;
  }
  Graph cur = g;
  Graph startNode = emptyGraph;
  Graph destNode = emptyGraph;
  bool start = 0, dest = 0;

  while (cur && !(start && dest)) {
    //cerr << "cur: " << cur->label << endl;
    if (cur->label == from) {
      //cerr << "Assigned start\n";
      start = 1;
      startNode = cur;
    }
    if (cur->label == to) {
      dest = 1;
      //cerr << "Assigned dest\n";
      destNode = cur;
    }

    cur = cur->nextVertex;
  }
  if (isEmpty(startNode) || isEmpty(destNode)) {
    return 0;
  }
  //cerr << "Yay\n";

  Edge destAux = new halfEdgeVertex;
  destAux->next = emptyEdge;
  destAux->label = destNode->label;
  destAux->destinazione = destNode;
  destAux->weight = w;

  Edge startAux = new halfEdgeVertex;
  startAux->next = emptyEdge;
  startAux->label = startNode->label;
  startAux->destinazione = startNode;
  startAux->weight = w;

  if (addStartDest(startNode, destNode, g, destAux) &&
      addStartDest(destNode, startNode, g, startAux)) {
    return 1;
  }
  return 0;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph &g) { return g == emptyGraph; }

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph &g) {
  // TODO
  if (isEmpty(g)) {
    return 0;
  }
  return 1 + numVertices(g->nextVertex);
}

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph &g) {
  // TODO
  Graph cur = g;
  unsigned int count = 0;
  while (cur) {

    Edge edgeCur = cur->firstHalfEdge;
    while (edgeCur) {
      count++;
      edgeCur = edgeCur->next;
    }

    cur = cur->nextVertex;
  }
  return count / 2;
}

// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int &degree, const Graph &g) {
  // TODO
  Graph cur = g;
  degree = 0;
  //cerr << "nodeDegree:\n";
  while (cur && cur->label != l) {
    cur = cur->nextVertex;
  }
  if (isEmpty(cur)) {
    return 0;
  }
  //cerr << " while exited with cur: " << cur->label << endl;
  if (cur->firstHalfEdge == emptyEdge) {
    degree = 0;
    return 1;
  }
  Edge edgeCur = cur->firstHalfEdge;
  while (edgeCur) {
    degree++;
    //cerr << "  current degree: " << degree << endl;
    edgeCur = edgeCur->next;
  }
  return degree;
}

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph &g) {
  // TODO
  // userò il metodo di esplorare le liste di adiacenza di entrambi i vertici
  Graph v1node = emptyGraph;
  Graph v2node = emptyGraph;
  Graph cur = g;
  while (cur) {
    if (cur->label == v1) {
      v1node = cur;
    }
    if (cur->label == v2) {
      v2node = cur;
    }
    cur = cur->nextVertex;
  }
  if (isEmpty(v1node) || isEmpty(v2node)) {
    return 0;
  }
  // cominciamo a scorrere gli archi dei due
  Edge edgeCur1 = v1node->firstHalfEdge;
  Edge edgeCur2 = v2node->firstHalfEdge;
  while (edgeCur1 && edgeCur2) {
    if (edgeCur1->label == v2 || edgeCur2->label == v1) {
      return 1;
    }

    edgeCur1 = edgeCur1->next;
    edgeCur2 = edgeCur2->next;
  }
  return 0;
}

// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph &g) {
  // TODO
  list::List lst = list::createEmpty();
  if (isEmpty(g)) {
    return lst;
  }
  Graph cur = g;
  while (cur && cur->label != v1) {
    cur = cur->nextVertex;
  }
  Edge edgeCur = cur->firstHalfEdge;
  while (edgeCur) {
    addBack(edgeCur->label, lst);
    edgeCur = edgeCur->next;
  }
  return lst;
}

bool pathFinderAux(Graph start, Graph end, list::List &path, Weight &weight,
                   const Graph &g) {
  if (isEmpty(start)) {
    //cerr << "  End of the edges\n";
    return 0;
  }
  if (start->label == end->label) {
    //cerr << "  found match\n";
    return 1;
  }
  //cerr << "  visiting: " << start->label << endl;
  start->isVisited = 1;
  Edge edgeCur = start->firstHalfEdge;
  bool result = 0;
  //cerr << "  while:\n";
  while (edgeCur) {
    //cerr << "   edgeCur: " << edgeCur->label<< ", visited: " << edgeCur->destinazione->isVisited << endl;
    if (!(edgeCur->destinazione->isVisited)) {
      //cerr << "   next visiting: " << edgeCur->destinazione->label << endl;
      result = pathFinderAux(edgeCur->destinazione, end, path, weight, g);
      if (result) {
        if (edgeCur->label != start->label) {
          //cerr << "   adding " << edgeCur->label << " to list\n";
          list::addFront(edgeCur->label, path);
        }
        //printList(path);
        weight += edgeCur->weight;
        //cerr << "  weight: " << weight << endl;
        return 1;
      }
    }
    edgeCur = edgeCur->next;
  }
  //cerr << " end of the path\n";
  return 0;
}

// Calcola, se esiste, un cammino tra due vertici
// Il primo argomento e il vertice di partenza
// Il secondo argomento e il vertice di arrivo
// Il terzo argomento conterrà la lista delle etichette degli
// vertici visitati sul cammino (senza il vertice di partenza, ne il vertice
// di arrivo)
// Si assume che il chiamante fornisca inizialmente una lista vuota.
// Il quarto argomento è il peso del cammino
// La funziona ritorna false, se il vertice di partenza e uguale al vertice
// di arrivo, o se non c'e un cammino tra i due vertici,
// altrimenti ritorna true
bool graph::findPath(Label v1, Label v2, list::List &path, Weight &weight,
                     const Graph &g) { //nel .h specifica di includere la città di destinazione, e così farò così l'output dei test manuali sarà corretto
  // TODO
  //cerr << "findPath:\n";
  weight = 0;
  if (v1 == v2) {
    //cerr << " Same start and dest: " << v1 << "->" << v2 << endl;
    return 1;
  }
  Graph cur = g;
  Graph start = emptyGraph;
  Graph end = emptyGraph;

  while (cur) {
    cur->isVisited = 0;
    if (cur->label == v1) {
      start = cur;
      cur->isVisited = 1;
    }
    if (cur->label == v2) {
      end = cur;
    }
    cur = cur->nextVertex;
  }
  if (isEmpty(start) || isEmpty(end)) {
    return 0;
  }

  return pathFinderAux(start, end, path, weight, g);
}

// Svuota un grafo
void clearEdges(Edge &arco) {
  if (arco == emptyEdge) {
    return;
  }

  clearEdges(arco->next);
  //cerr << "\tnow deleting edge "<<arco->label<<endl;
  delete arco;
}

void graph::clear(graph::Graph &g) {
  // TODO
  if (isEmpty(g)) {
    return;
  }
  clear(g->nextVertex);
  clearEdges(g->firstHalfEdge);
  //cerr << "now deleting vertex "<<g->label<<endl;
  delete g;
  g = emptyGraph;
}

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph &g) {
  // TODO
  Graph cur = g;
  while (cur) {
    cout << cur->label << "->";
    Edge edgeCur = cur->firstHalfEdge;
    while (edgeCur) {
      if (edgeCur != cur->firstHalfEdge) {
        cout << ":";
      }
      cout << edgeCur->label;
      edgeCur = edgeCur->next;
    }
    cout << endl;
    cur = cur->nextVertex;
  }
}
