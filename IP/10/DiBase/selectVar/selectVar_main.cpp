#include "selectVar_funct.h"
#include <iostream>
using namespace std;

int main() {
  char ch1 = 'a', ch2 = 'b', ch3 = 'c';
  char *selected = selectVar(ch1, ch2, ch3);
  if (selected == &ch1) {
    cout << "Hai scelto ch1 che ha valore: " << ch1 << endl;
  } else if (selected == &ch2) {
    cout << "Hai scelto ch2 che ha valore: " << ch2 << endl;
  } else if (selected == &ch3) {
    cout << "Hai scelto ch3 che ha valore: " << ch3 << endl;
  } else {
    cout << "Non hai scelto niente"<<endl;
  }
}
