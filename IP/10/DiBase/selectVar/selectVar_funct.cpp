#include <iostream>
using namespace std;

char *selectVar(char &a, char &b, char &c) {
  // cout<<"Scegliere una tra "<<a<<", "<<b<<", "<<c<<endl;
  cout << "Scegi fra queste variabili, potrai cambiare idea in seguito e "
          "sceglierne una diversa che preferisci"<<endl;
  char answer;
  char *p = nullptr;
  cout << "Vuoi la prima (y/n)? contiene: " << a<<"\t";
  cin >> answer;
  if (answer == 'y' || answer == 'Y') {
    p = &a;
  }
  cout << "Vuoi la seconda (y/n)? contiene: " << b<<"\t";
  cin >> answer;
  if (answer == 'y' || answer == 'Y') {
    p = &b;
  }
  cout << "Vuoi la terza (y/n)? contiene: " << c<<"\t";
  cin >> answer;
  if (answer == 'y' || answer == 'Y') {
    p = &c;
  }
  return p;
}
