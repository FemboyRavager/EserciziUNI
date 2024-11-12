#include <iostream>

using namespace std;

struct Time {
  unsigned int ora = 0;
  unsigned int minuti = 0;
  unsigned int secondi = 0;
};

int main() {
  Time T1, T2;
  bool timeValid = true, isT1beforeT2 = true;
  cout << "Inserire valori T1 di ore, min, e sec in questo ordine: ";
  cin >> T1.ora >> T1.minuti >> T1.secondi;

  cout << "Inserire valori T2 di ore, min, e sec in questo ordine: ";
  cin >> T2.ora >> T2.minuti >> T2.secondi;

  // Check validity (assumendo orologio 24h)
  if ((T1.ora >= 24 || T2.ora >= 24) ||
      (T1.ora < 0 || T2.ora < 0)) { // check ore non valide
    cout << "Ora non valida\n";
    timeValid = false;
  }
  if ((T1.minuti >= 60 || T2.minuti >= 60) ||
      (T1.minuti < 0 || T2.minuti < 0)) { // check min non validi
    cout << "Minuti non valida\n";
    timeValid = false;
  }
  if ((T1.secondi >= 60 || T2.secondi >= 60) ||
      (T1.secondi < 0 || T2.secondi < 0)) { // check secs non validi
    cout << "Ora non valida\n";
    timeValid = false;
  }
  if (!timeValid)
    return 0;
  

  // Check T1 prima di T2
  if (T1.ora > T2.ora)
    isT1beforeT2 = false;
  else if (T1.ora == T2.ora && T1.minuti > T2.minuti)
    isT1beforeT2 = false;
  else if (T1.ora == T2.ora && T1.minuti == T2.minuti &&
           T1.secondi > T2.secondi)
    isT1beforeT2 = false;
  if (isT1beforeT2) {
    cout << "\nT1 rappresenta un'ora precedente o uguale a T2\n";
  } else {
    cout << "\nT1 rappresenta un'ora successiva a T2\n";
    return 0;
  }

  // Calcolo diff
  Time diff;
  Time T1temp=T1, T2temp=T2;

  //cout << "T1 originali: " << T1temp.ora << "." << T1temp.minuti << "." << T1temp.secondi << endl;

  //cout << "T2 originali: " << T2temp.ora << "." << T2temp.minuti << "." << T2temp.secondi << endl;

  if (T2temp.secondi < T1.secondi) { //pur essendo successivo può avere secondi minori, gestisco caso
    if (T2temp.minuti==0) {//siccome sono unsigned, diminuire di 1 (riga 66) fa casino, quindi prendo in prestito dalle ore se minuti==0
      T2temp.minuti+=60;  //prendo in prestito dalle ore
      T2temp.ora-=1;  //riduco ore
    }
    T2temp.minuti -= 1;   //riduco minuti
    T2temp.secondi += 60; //prendo in prestito dai minuti (dopo essermi accertato che siano >0 (sopra))
  }
  if (T2temp.minuti < T1temp.minuti) { //pur essendo successivo può avere minuti minori, gestisco caso
    T2temp.ora -= 1;  //prendo in prestito dalle ore
    T2temp.minuti += 60; //converti in minuti
  }

  //cout << "T1 convertite: " << T1.ora << "." << T1.minuti << "." << T1.secondi << endl;

  //cout << "T2 convertita: " << T2.ora << "." << T2.minuti << "." << T2.secondi << endl;

  diff.ora = T2temp.ora - T1temp.ora;
  diff.minuti = T2temp.minuti - T1temp.minuti;
  diff.secondi = T2temp.secondi - T1temp.secondi;

  cout << "Tra T1 e T2 sono trascorse " << diff.ora << " ore, " << diff.minuti
       << " minuti e " << diff.secondi << " secondi\n";
}
