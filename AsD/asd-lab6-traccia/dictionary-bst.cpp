#include "dictionary.h"

using namespace dict;

// STRUCT TO BE COMPLETED
//  *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! ***
struct dict::bstNode {
  // TO COMPLETE
  Elem payload;
  bstNode *leftChild;
  bstNode *rightChild;
};

// Funzione da implementare
bool dict::isEmpty(const Dictionary &d) { return (d == emptyDictionary); }

// Funzione da implementare
Dictionary dict::createEmptyDict() {
  // TODO
  Dictionary newDict = NULL;
  return newDict;
}

// Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary &d) {
  // TODO
  // cerr << "Nodo attuale e': " << (isEmpty(d) ? "Vuoto" : "Non vuoto\t");
  if (!isEmpty(d)) {
    // cerr << "Pair->" << d->payload.key << ":" << d->payload.value << endl;
  }
  // cerr << endl;
  // cerr << "==";
  // print(d);
  if (isEmpty(d)) {
    // cerr << "\nVUOTOOOO\n";
    d = new bstNode;
    d->leftChild = emptyDictionary;
    d->rightChild = emptyDictionary;
    d->payload.key = k;
    d->payload.value = v;
    return OK;
  }
  if (d->payload.key < k) { // non uso search() perchè non mi ritorna la cella, faccio manualmente
    // cerr << "Ricorsione: value attuale: " << d->payload.value<< "| vado a DX\n";
    return insertElem(k, v, d->rightChild);
  } else if (d->payload.key > k) {
    // cerr << "Ricorsione: valore attuale: " << d->payload.value     << "| vado a SX\n";
    return insertElem(k, v, d->leftChild);
  } else if (d->payload.key == k) {
    // cerr << "Già esistente\n";
    return FAIL;
  }
  return OK;
}

// Funzione da implementare
Value dict::search(const Key k, const Dictionary &d) {
  // TODO
  if (d == emptyDictionary) {
    return emptyValue;
  }
  // cerr << "==";
  //  print(d);
  if (k < d->payload.key) {
    return search(k, d->leftChild);
  } else if (k > d->payload.key) {
    return search(k, d->rightChild);
  } else if (k == d->payload.key) {
    // cerr << "FOUND\n";
    return d->payload.value;
  }
  return emptyValue;
}

Dictionary deleteMin(Dictionary &d) {
  // cerr << "deleteMin visiting " << d->payload.key << endl;
  Dictionary ret = new bstNode;
  if (d->leftChild == emptyDictionary) {
    // cerr << "FOUND MIN: " << d->payload.key << endl;
    if (d->rightChild) {
      // cerr << "Ha figlio DX: " << d->rightChild->payload.key << endl;
      //  Dictionary temp = d->rightChild;
      ret->payload = d->payload;
      // delete d;
      // d = temp;
      // cerr << "After deletion min is now: " << d->payload.key << endl;
    } else {
      // cerr << "Foglia\n";
      ret->payload.key = d->payload.key;
      ret->payload.value = d->payload.value;
      // cerr << "Salvo in ret->
      // "<<ret->payload.key<<":"<<ret->payload.value<<endl;
      d = emptyDictionary;
    }
    return ret;
  } else {
    ret = deleteMin(d->leftChild);
    // cerr << "Current ret: " << ret->payload.key<<":"<<ret->payload.value<<
    // endl;
    if (ret != emptyDictionary && d->leftChild &&
        d->leftChild->payload.key == ret->payload.key) {
      // cerr << "Returned after finding MIN, now at: " << d->payload.key <<
      // endl;
      Dictionary temp = d->leftChild;
      d->leftChild = temp->rightChild;
      // cerr << "Connected "<<d->payload.key<<" to "<<d->leftChild->payload.key<<endl;
      return ret;
    } else if (ret != emptyDictionary) {
      // cerr << "Returned after deleting leaf or smth idk, now at: " << d->payload.key << ", left child: "<<d->leftChild <<endl;
      if (d->leftChild == emptyDictionary) {
        // cerr << "TFW no left child :(\n";
        delete d->leftChild;
      }
      return ret;
    }
    return emptyDictionary;
  }
}

// Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary &d) {
  // TODO
  if (d == emptyDictionary) {
    return FAIL;
  }
  // cerr << "==";
  // print(d);
  // cerr << "Visito " << d->payload.key << endl;
  if (k < d->payload.key) {
    return deleteElem(k, d->leftChild);
  } else if (k > d->payload.key) {
    return deleteElem(k, d->rightChild);
  } else if (k == d->payload.key) { // trovato nodo
    // cerr << "Trovato nodo da eliminare: " << d->payload.key << endl;
    if (d->rightChild == emptyDictionary && d->leftChild == emptyDictionary) {
      // cerr << "Fogla\n";
      delete d;
      d = emptyDictionary;
      return OK;
    } else if (d->leftChild == emptyDictionary) {
      // cerr << "Solo DX\n";
      delete d;
      d = d->rightChild;
      return OK;
    } else if (d->rightChild == emptyDictionary) {
      // cerr << "Solo SX\n";
      delete d;
      d = d->leftChild;
      return OK;
    } else { // 2 figli
      // cerr << "Calling deleteMin on " << d->rightChild->payload.key << endl;
      Dictionary min = deleteMin(d->rightChild);
      // cerr << "deleteMin done, returned: " << min->payload.key << ":"<<
      // min->payload.value << endl;
      d->payload.key = min->payload.key;
      d->payload.value = min->payload.value;
      return OK;
    }
    // deleteMin(d->rightChild);
  }
  return FAIL;
}

// Funzione da implementare
void print(const Dictionary &d) {
  // TODO
  if (!d) {
    return;
  }
  if (d->leftChild) {
    print(d->leftChild);
  }
  cout << "\t" << d->payload.key << ": " << d->payload.value << endl;
  if (d->rightChild) {
    print(d->rightChild);
  }
}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file) {
  ifstream ifs(
      nome_file
          .c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {
    cout << "\nErrore apertura file, verificare di avere inserito un nome "
            "corretto\n";
    return emptyDictionary;
  }
  return readFromStream(ifs);
}

Dictionary readFromStdin() {
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: "
          "value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream &str) {
  Dictionary d = emptyDictionary;
  string key, kcopy;
  string value;
  getline(str, key, ':');
  getline(str, value);
  while (!str.eof()) {
    kcopy = key;
    removeBlanksAndLower(kcopy);
    insertElem(kcopy, value, d);
    getline(str, key, ':');
    getline(str, value);
  }
  str.clear();
  return d;
}
