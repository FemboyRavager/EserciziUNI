#include <iostream>
using namespace std;

int main() {
  string s1 = "Hello", s2 = "World";
  cout << "Variabile s1: " << s1 << " in " << &s1 << endl;
  cout << "Variabile s2: " << s2 << " in " << &s2 << endl;

  string *p = &s1;
  cout << "p contiene " << p << endl;
  cout << "*p contiene " << *p << endl;

  *p = "Ciao";
  cout << "p contiene " << p << endl;
  cout << "*p contiene " << *p << endl;

  p = &s2;
  cout << "p contiene " << p << endl;
  cout << "*p contiene " << *p << endl;

  *p = "Mondo";
  cout << "p contiene " << p << endl;
  cout << "*p contiene " << *p << endl;

  cout << "Variabile s1: " << s1 << " in " << &s1 << endl;
  cout << "Variabile s2: " << s2 << " in " << &s2 << endl;
}
