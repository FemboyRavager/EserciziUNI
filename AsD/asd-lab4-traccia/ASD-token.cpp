// FILE DA MODIFICARE
#include "ASD-token.h"
#include <iostream>

using namespace std;

bool isNum(string substr, int &numRet, string st) {
  int i=0;
  for (i = 0; st[i] >= 48 && st[i] <= 57; i++) {
      numRet *= 10;
      numRet += st[i] - 48;
  }
  if (st[i] != 32 && st[i]!='\0' ) {
    //cerr << "BBB";
    throw string("Lexical error");
    //throw string("Token non valido dopo numero: " + st.substr(i,1) + "\n");
  }

  return i;
}

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

// funzione che estrae il prossimo token della string st
// lo mette in tok e modifica st,
// ritorna true se c'era un token da estrarre,
// ritorna false se non c'era niente da estrarre e si e arrivato alla fine di
// st, solleva una eccezione di tipo string se legge un token di tipo
// sconosciuto
bool nextToken(string &st, token &tok) {
  // TODO
  if (st == "") {
    return false;
  }
  int num = 0;
  string substr = st.substr(0, 1);
  //cerr << "\n\nsubstr attuale: " << substr << endl;
  while (substr == " ") {
    //cerr << "Space found";
    st.erase(0, 1); // aggiustare per più spazi di fila (caso brutto)
    //cerr << "-> " << st << endl;
    substr = st.substr(0, 1);
  }
  if (substr.length() == 0) {
    //cerr << "Solo spazi\n";
    return false;
  }
  //cerr << "tolti spazi ->substr attuale: " << substr << endl; 
  if (substr == "(") {
    tok.k = PARENTESI_APERTA;
  } else if (substr == ")") {
    tok.k = PARENTESI_CHIUSA;
  } else if (substr == "+") {
    tok.k = OP_SOMMA;
  } else if (substr == "-") {
    tok.k = OP_SOTTRAZIONE;
  } else if (substr == "*") {
    tok.k = OP_MOLTIPLICAZIONE;
  } else if (isNum(substr, num, st)) {
    tok.k = NUMERO;
    tok.val = num;
  } else {
    //cerr << "CCC";
    throw string("Lexical error");
  }
  if (tok.k != NUMERO) {
    st.erase(0, 1); // aggiustare per num >9
  } else {
    unsigned int digitNumber = 1;
    num /= 10;
    while (num > 0) {
      digitNumber++;
      num /= 10;
    }
    //cerr << "number had " << digitNumber << " digits" << endl;
    st.erase(0, digitNumber);
  }
  //cerr << "Size left: "<<st.length()<<endl;
  if (st.substr(0, 1) != " " && st.length()!=0) {
    //cerr << "\nStringa attuale: "<< st<<endl;
    throw string("Lexical error");
    //throw string("Manca spazio tra " + substr + " e " + st.substr(0,1) + " dio paleontologo");
  }
  // cerr << "fine funz\n";
  return true;
}
/*
int main() {

  string str = "( 2 + 4 )";
  token token;
  try {
    while (nextToken(str, token)) {
      if (token.k == NUMERO) {

        cerr << "n: " << token.val << "|";
      } else {
        cerr << "Token: ";
        switch ((int)token.k) {
        case 0:
          cerr << "(";
          break;
        case 1:
          cerr << ")";
          break;
        case 3:
          cerr << "+";
          break;
        case 4:
          cerr << "-";
          break;
        case 5:
          cerr << "*";
        }
        // cerr << "kind: " << token.k << "|";
      }
    }
  } catch (string child) {
    cerr << child;
  }
  cerr << "\nFINE\n";
}
*/
