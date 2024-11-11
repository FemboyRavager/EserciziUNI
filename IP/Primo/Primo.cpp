
#include <iostream>
#include <string>

int main() {
  int lettere[26] = {}; // Alfabeto per contare occorrenze
  std::string Stringa = "Esercizio";
  std::cout << "Inserire singola parola\n";
  std::cin >> Stringa;
  int lunghezza = Stringa.length();
  std::cout << lunghezza << " lettere" << std::endl;

  for (int i = 0; i < lunghezza; i++) { // rendo minuscole
    if (Stringa[i] >= 65 && Stringa[i] <= 90)
      Stringa[i] += 32;
  }

  std::cout << "Stringa corretta: " << Stringa << std::endl;

  for (int i = 0; i < lunghezza; i++) { // conto occorrenze

    char currentLetter = Stringa[i];
    // std::cout << "ASCII sbagliato: " <<(int)currentLetter << std::endl;
    // std::cout << "ASCII corretto: " << (int)currentLetter-64 << std::endl;
    std::cout << "ASCII " << currentLetter << " " << (int)currentLetter
              << "\t--> Alfabeto: " << (int)currentLetter - 96 << std::endl;
    lettere[(int)currentLetter - 97]++;
  }

  for (int i = 0; i <= 25; i++) { // stampo linea di lettere
    char letter = i + 97;
    // std::cout << "La lettera " << letter << " appare " << lettere[i] << "
    // volte\n";
    std::cout << letter << "   ";
  }

  std::cout << std::endl;

  for (int i = 0; i <= 25; i++) { // stampo occorrenze
    std::cout << lettere[i] << "   ";
  }

  std::cout << std::endl;

  return 0;
}
