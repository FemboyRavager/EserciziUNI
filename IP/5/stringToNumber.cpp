#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int length = 0;
  string stringa;
  bool wrongInput = false;
  do {
    wrongInput = false;
    cout << "Inserire stringa rappresentante un numero positivo: ";
    getline(cin, stringa);
    length = stringa.length();
    for (int i = 0; i < length; i++) {
      if (stringa[i] < '0' || stringa[i] > '9' || (stringa[i] == '0' && length == 1)) { // se non int, se <0, o se singolo 0
        wrongInput = true;
        cout << "Inserire solo caratteri rappresentanti numeri positivi" << endl;
      }
    }
  } while (wrongInput);

  int intFromString = 0;
  int positionalMultiplier = 0;
  for (int i = 0; i < length; i++) { // moltiplicatore posizionale base decimale, per non usare funzioni non ancora introdotte che convertono da string a int
    if (i == 0)
      positionalMultiplier = 1;
    else {
      positionalMultiplier *= 10;
    }
    // cout << "\nCurrent int: " << intFromString << "| posMul: " <<
    // positionalMultiplier << "| digit: " << stringa[length-1-i] << endl;
    intFromString += (stringa[length - 1 - i] - 48) * positionalMultiplier; //-48 per offset ASCII
  }

  cout << endl << intFromString << endl;

  return 0;
}
