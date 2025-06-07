#include <chrono> // necessario compilare con -std=c++11
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h> // srand, rand
#include <string>   // std::string
#include <vector>

#include "string-utility.h"

using namespace std::chrono;
using namespace std;

namespace dict {

// Codici di errore

enum Error { OK, FAIL };

// Tipi e costanti

const int tableDim = 1000; // da modificare per fare esperimenti diversi

typedef string Key;   // tipo base
typedef string Value; // tipo base

const Key emptyKey = "###RESERVED KEYWORD### EMPTY KEY";
const Value emptyValue = "###RESERVED KEYWORD### EMPTY VALUE";

typedef struct {
  Key key;
  Value value;
} Elem;

// Implementazione basata su tabella hash

struct cell;
typedef cell *Bucket;
const Bucket emptyBucket = NULL;
typedef Bucket *Dictionary; // un Dictionary è un array di dimensione tableDim (che viene fissata in fase di inizializzazione), di puntatori a cell (che abbiamo chiamato "Bucket"); come già fatto in altre occasioni, la struttura di cell è
                            // definita nel file ausiliario per incapsulare il più possibile l'informazione

Error insertElem(const Key, const Value, Dictionary &);
Error deleteElem(const Key, Dictionary &);
Value search(const Key, const Dictionary &);
Dictionary createEmptyDict();

} // namespace dict

dict::Dictionary readFromFile(string);
dict::Dictionary readFromStdin();
dict::Dictionary readFromStream(istream &);
void print(const dict::Dictionary &);
