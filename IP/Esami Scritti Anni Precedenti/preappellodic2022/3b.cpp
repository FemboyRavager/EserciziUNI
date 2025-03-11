#include <iostream>
#include <list>
using namespace std;

bool isEcco(list<string> l) {
  for (string elem : l) {
    if (elem == "ecco")
      return true;
  }
  return false;
}

bool allAreEcco(list<string> l) {
  for (string elem : l) {
    if (elem != "ecco")
      return false;
  }
  return true;
}

int main() {
  list<string> l1 = {"Hello", " ", "World", "!"};
  list<string> l2 = {"Hello", " ", "World", "!", "ecco"};
  list<string> l3 = {"ecco", "ecco", "ecco", "ecco", "ecco"};

  cerr << "l1" << (isEcco(l1) ? "contiene ecco" : "non contiene ecco") << endl;
  cerr << "l2" << (isEcco(l2) ? "contiene ecco" : "non contiene ecco") << endl;

  cerr << "------------------" << endl;

  cerr << "l1" << (allAreEcco(l1) ? "è solo ecco" : "non è solo ecco") << endl;
  cerr << "l2" << (allAreEcco(l2) ? "è solo ecco" : "non è solo ecco") << endl;
  cerr << "l3" << (allAreEcco(l3) ? "è solo ecco" : "non è solo ecco") << endl;
}
