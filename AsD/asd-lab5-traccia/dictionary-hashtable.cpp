#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell {
  Elem elem;
  cell *next;
};

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del
              // primo carattere della chiave (se esiste) e restituisce il resto
              // della divisione di tale valore per tableDim
{
  // implementare la funzione richiesta e modificare il return

  return ((int)s[0]) % tableDim;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere
              // nella chiave e restituisce il resto della divisione di tale
              // somma per tableDim
{
  // implementare la funzione richiesta e modificare il return
  int ret = 0;
  while (!s.empty()) {
    ret += s[0];
    s.erase(0, 1);
  }
  // cerr << ret << endl;
  return ret % tableDim;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/

unsigned int getFactorFromLetter(char c) { //uso fattorizzazione sperando che il modulo non rovini troppo l'unicità
  int lookUpTable[] = {3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  41, 43,
                       47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103}; //array usato come lookUpTable per non avere switch con 26 casi per le lettere [a-z]
  if (c<97 || c>123) { //qualsiasi char che non sia [a-z] è neutro
    return 1;
  }
  //cerr << "==: " << c - 97 << endl;
  return lookUpTable[c - 97]; //a=[0], b=[1], etc
}

int h3(Key s) // funzione di hash diversa da h1 ed h2, che progettate e
              // implementate voi seguendo qualche criterio che vi sembra
              // ragionevole
{
  // implementare la funzione richiesta e modificare il return
  //cerr << endl << s << endl;
  char letter = 0;
  int key = 1;
  int numLetters=0;
  while (!s.empty()) {
    numLetters++;
    letter = s[0];
    s.erase(0, 1);
    key *= getFactorFromLetter(letter);
    //cerr << "\nintString: " << letter << ", wiht key: " << key << endl;
    key = key%tableDim;
  }
  if (numLetters%2==0) {
    key*=2;
    key = key % tableDim;
  }
  return key;
}

/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s) {
  return h3(s); // modificare questa chiamata per sperimentare l'utilizzo delle
                // funzioni di hash h1, h2, h3, definite prima
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary &s) {

  int index = h(k);
  Bucket cur = s[index];
  Bucket prev = cur;
  while (cur) {
    if (cur->elem.key == k) {
      if (cur == s[index]) { // unico Elem nel bucket
        s[index] = emptyBucket;
        return OK;
      }
      prev->next = cur->next;
      delete cur;
      cur = prev->next;
      return OK;
    }
    prev = cur;
    cur = cur->next;
  }
  return FAIL;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary &s) {
  int index = h(k);
  Bucket cur = s[index];
  while (cur) {
    if (cur->elem.key == k) {
      return cur->elem.value;
    }
    cur = cur->next;
  }
  return emptyValue;
}

/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::insertElem(const Key k, const Value v, Dictionary &s) {
  Key kCopy = k;
  removeBlanksAndLower(kCopy);
  int index = h(kCopy);
  Bucket cur = s[index];
  while (cur) {
    if (cur->elem.key == k) {
      return FAIL;
    }
    cur = cur->next;
  }
  Bucket aux = new cell;
  aux->elem.key = k;
  aux->elem.value = v;
  aux->next = s[index];
  s[index] = aux;
  return OK;
}

/****************************************************************/
Dictionary dict::createEmptyDict() {
  Bucket *d = new Bucket[tableDim];
  for (int i = 0; i < tableDim; ++i)
    d[i] = emptyBucket;
  return d;
}

/****************************************************************/
Dictionary readFromFile(string nome_file) {
  ifstream ifs(
      nome_file
          .c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {
    cout << "\nErrore apertura file, verificare di avere inserito un nome "
            "corretto\n";
    return createEmptyDict();
  }
  return readFromStream(ifs);
}

/****************************************************************/
Dictionary readFromStdin() {
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: "
          "value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

/****************************************************************/
Dictionary readFromStream(istream &str) {
  Dictionary d = createEmptyDict();
  string key, kcopy;
  string value;
  getline(str, key, ':');
  getline(str, value);
  while (!str.eof()) {
    kcopy = key;
    removeBlanksAndLower(kcopy);
    insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON
                                 // PUO' FUNZIONARE CORRETTAMENTE: la insertElem
                                 // e' la prima funzione che dovete implementare
    getline(str, key, ':');
    getline(str, value);
  }
  str.clear();
  return d;
}

/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il
                          // numero di elementi contenuti nel bucket stesso
{
  int counter = 0;
  while (b != emptyBucket) {
    counter++;
    cout << (b->elem).key << ": " << (b->elem).value << "\n";
    b = b->next;
  }
  return counter;
}

/****************************************************************/
void print(const Dictionary &s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati
// organizzati gli elementi
{
  int bucketDim[tableDim];
  int totalElem = 0;
  for (unsigned int i = 0; i < tableDim; ++i) {
    cout << "\nBucket " << i << "\n\n";
    bucketDim[i] = printBucket(s[i]);
    totalElem += bucketDim[i];
  }
  float means = totalElem / (float)tableDim;
  float standardDevSum = 0;
  for (unsigned int i = 0; i < tableDim; ++i)
    standardDevSum += (bucketDim[i] - means) * (bucketDim[i] - means);

  /* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice
  di dispersione statistico, vale a dire una stima della variabilita' di una
  popolazione di dati o di una variabile casuale. Lo scarto tipo e' uno dei modi
  per esprimere la dispersione dei dati intorno ad un indice di posizione, quale
  puo' essere, ad esempio, la media aritmetica. */

  cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

  for (unsigned int i = 0; i < tableDim; ++i)
    cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

  cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
  cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
  if (tableDim != 0)
    cout << "\nIl numero atteso di elementi per bucket e' " << means
         << "\nLa deviazione standard e' " << sqrt(standardDevSum / tableDim);
}
