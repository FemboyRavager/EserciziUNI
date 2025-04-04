#include <iostream>

using namespace std;

void print_choice(int n, string ch1, string ch2, string ch3, string ch4) {
  cout << endl << "Scelta effettuata: ";
  switch (n) {
  case 1:
    cout << ch1;
    break;
  case 2:
    cout << ch2;
    break;
  case 3:
    cout << ch3;
    break;
  case 4:
    cout << ch4;
    break;
  }
  cout << endl<<"------------------"<<endl<<endl;
}

void print_menu(string choice1, string choice2, string choice3,
                string choice4) {
  cout << "1\t" << choice1 << endl;
  cout << "2\t" << choice2 << endl;
  cout << "3\t" << choice3 << endl;
  cout << "4\t" << choice4 << endl;
}

int get_choice(int max) {
  int choice = 0;
  do {
    cout << "Inserisci una scelta fra 1 e " << max << ": ";
    cin >> choice;
  } while (choice < 1 || choice > max); // siccome il programma, come descritto nell'eserciziario, ripete finchè la scelta non è nell'intervallo corretto, non uso try-catch
  return choice;
}

int use_menu(string choice1, string choice2, string choice3, string choice4) {
  print_menu(choice1, choice2, choice3, choice4);
  int n = get_choice(4);
  print_choice(n, choice1, choice2, choice3, choice4);
  return n;
}

int main() {
  const string s1 = "Prima scelta";
  const string s2 = "Seconda scelta";
  const string s3 = "Terza scelta";
  const string s4 = "Basta!";
  int answer;
  do {
    answer = use_menu(s1, s2, s3, s4);
  } while (answer != 4);
}
