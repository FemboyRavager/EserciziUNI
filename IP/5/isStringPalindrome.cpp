#include <iostream>
#include <string>
using namespace std;

int main() {
  bool isPalindrome = true;
  string stringa;
  cout << "Inserire stringa: ";
  getline(cin, stringa);
  int length = stringa.length();
  

  for (int i = 0; i < length; i++) {                          // rendo minuscole
    if (stringa[i] >= 65 && stringa[i] <= 90)
      stringa[i] += 32;
  }
  // cout << endl << stringa << " | " << length << endl;
  for (int i = 0; i < length && isPalindrome; i++) {

    if (stringa[i] != stringa[length - 1 - i]) {
      isPalindrome = false;
      // cout << ">" << i << "!=" << (length-1-i) << endl;
    }
  }

  if (isPalindrome)
    cout << endl << "Palindrome\n";
  else
    cout << endl << "Not palindrome\n";


  return 0;
}
