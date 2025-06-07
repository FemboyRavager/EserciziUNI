#include "dictionary.h"

using namespace dict;

// STRUCT TO BE COMPLETED
//  *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! ***
struct dict::bstNode {
  // TO COMPLETE
  Elem el;
  bstNode *leftChild;
  bstNode *rightChild;
};

// Funzione da implementare
bool dict::isEmpty(const Dictionary &d) {
  // TODO
  return (!d);
}

// Funzione da implementare
Dictionary dict::createEmptyDict() {
  // TODO
  Dictionary aux = emptyDictionary;
  return aux;
}

// Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary &d) {
  // TODO
  if (isEmpty(d)) {
    Dictionary aux = new bstNode;
    aux->el.value = v;
    aux->el.key = k;
    aux->leftChild = emptyDictionary;
    aux->rightChild = emptyDictionary;
    d = aux;
    return OK;
  }

  if (k == d->el.key) {
    return FAIL;
  }

  if (k < d->el.key) {
    return insertElem(k, v, d->leftChild);
  } else {
    return insertElem(k, v, d->rightChild);
  }

  return OK;
}

// Funzione da implementare
Value dict::search(const Key k, const Dictionary &d) {
  // TODO
  if (isEmpty(d)) {
    return emptyValue;
  }

  if (k == d->el.key) {
    return d->el.value;
  }

  if (k < d->el.key) {
    return search(k, d->leftChild);
  } else {
    return search(k, d->rightChild);
  }

  return emptyValue;
}

Dictionary deleteMin(const Key k, Dictionary &d, bool &isFather) {
  if (isEmpty(d)) {
    return emptyDictionary;
  }
  Dictionary ret = deleteMin(k, d->leftChild, isFather);
  if (ret == emptyDictionary) {
    ret = d;
    if (d->rightChild) {
      d = d->rightChild;
      return ret;
    }
    d = emptyDictionary;
  }
  return ret;
}
// Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary &d) {
  // TODO
  if (isEmpty(d)) {
    return FAIL;
  }

  Dictionary target;
  Error res;
  if (k < d->el.key) {
    return deleteElem(k, d->leftChild);
  }
  if (k > d->el.key) {
    return deleteElem(k, d->rightChild);
  }
  if (k == d->el.key) {
    if (!d->leftChild && !d->rightChild) {
      delete d;
      d = emptyDictionary;
      return OK;
    }
    if (!d->leftChild && d->rightChild) {
      Dictionary tmp = d->rightChild;
      delete d;
      d = tmp;
      return OK;
    }
    if (d->leftChild && !d->rightChild) {
      Dictionary tmp = d->leftChild;
      delete d;
      d = tmp;
      return OK;
    }
    if (d->leftChild && d->rightChild) {
      bool aux = 0;
      Dictionary replacement = deleteMin(k, d->rightChild, aux);
      replacement->rightChild = d->rightChild;
      replacement->leftChild = d->leftChild;
      d = replacement;
      return OK;
    }
    return OK;
  }
  return FAIL;
}

// Funzione da implementare
void print(const Dictionary &d) {
  // TODO
  if (!d) {
    return;
  }
  print(d->leftChild);
  cout << d->el.key << endl;
  print(d->rightChild);
}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file) {
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {
    cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n";
    return emptyDictionary;
  }
  return readFromStream(ifs);
}

Dictionary readFromStdin() {
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
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
