#include <string>

using namespace std;

int maxArray(int *t, int size) {
  // DA MODIFICARE
  if (size == 0) {
    string child = "Array di dimensioni 0\n";
    throw child;
  }
  int *p = t;
  int maxN = *p; // maxN = array[0]
  for (int i = 0; i < size;
       i++) { // comincio da i=1 siccome maxN inizializzato a [0]
    if (*p > maxN) {
      maxN = *p;
    }
    p++;
  }
  return maxN;
  return 0;
}
