#include <iostream>
using namespace std;

int main() {

  char player1 = 0, player2 = 0;

  cout << "Inserire mossa del primo giocatore come lettere 'f', 'c' o 's': ";
  cin >> player1;

  cout << "Inserire mossa del secondo giocatore come lettere 'f', 'c' o 's': ";
  cin >> player2;

  switch (player1) {
  case 'f':
  case 'c':
  case 's':
    break;
  default:
    cout << "\nGiocatore 1 seguire istruzioni\n";
  }

  switch (player2) {
  case 'f':
  case 'c':
  case 's':
    break;
  default:
    cout << "\nGiocatore 2 seguire istruzioni\n";
  }

  switch (
      player1) { // Orrida ripetizione di switch ma il primo necessita cascata e
                 // il secondo no; non ho trovato modo di integrarli
  case 'f':
    cout << "Giocatore 1 gioca forbice\n";
    break;
  case 'c':
    cout << "Giocatore 1 gioca carta\n";
    break;
  case 's':
    cout << "Giocatore 1 gioca sasso\n";
    break;
  }

  switch (player2) {
  case 'f':
    cout << "Giocatore 2 gioca forbice\n";
    break;
  case 'c':
    cout << "Giocatore 2 gioca carta\n";
    break;
  case 's':
    cout << "Giocatore 2 gioca sasso\n";
    break;
  }

  if (player1 == player2) { // Fine prematura
    cout << "Pari" << endl;
    return 0;
  }

  if (player1 == 'f') { // P1 forbice
    if (player2 == 'c') //&&P2 carta
      cout << "Player 1 vince";
    else //&&P2 sasso
      cout << "Player 2 vince";
  } else if (player1 == 'c') { // P1 carta
    if (player2 == 'f')        //&&P2 forbice
      cout << "P2 vince";
    else //&&P2 sasso
      cout << "P1 vince";
  } else if (player2 == 'f') // P1 sasso (per esclusione) && P2 forbice
    cout << "P1 vince";
  else // P1 sasso (per esclusione) && P2 carta
    cout << "P2 vince";

  cout << endl;

  return 0;
}
