#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string stringa;
  cout << "Inserire stringa: ";
  getline(cin, stringa);
  int length = stringa.length();
  for (int i = 0; i < length; i++) {
    stringa += stringa[length - 1 - i];
  }
  stringa.erase(0, length);

  cout << endl << stringa << endl;
  return 0;
}
