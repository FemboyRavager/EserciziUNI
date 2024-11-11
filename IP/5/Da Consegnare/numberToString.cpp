#include <iostream>
#include <string>
using namespace std;

int main() {

  int n = 0;

  cout << "Inserire numbero positivo\n";
  cin >> n;
  int ncopy = n;
  int remainder = 0;
  string stringFromInt = {};
  // int length = stringFromInt.length();
  int nlength = 0;
  while (ncopy) {               //Trova numero cifre di n
    if (ncopy % 10 != 0)
      nlength++;
    ncopy /= 10;
  }
  cout << "\nLength: " << nlength << endl;
  ncopy = n;

  for (int i = 0; i < nlength; i++) {
    remainder = ncopy % 10;             //Ottieni cifra più a destra con modulo,
    ncopy /= 10;                        //il risultato sarà invertito dopo

    // cout << ">" << c << endl;

    stringFromInt += (char)(remainder + 48);  //Shift per codifica ASCII e cast a char
  }
  int length = stringFromInt.length();
  for (int i = 0; i < length; i++) {      //Append copia invertita della stringa
    stringFromInt += stringFromInt[length - 1 - i];
  }
  stringFromInt.erase(0, length);   //Cancello stringa originale lasciando quella invertita

  cout << endl << "Stringa: " << stringFromInt << endl;

  return 0;
}
