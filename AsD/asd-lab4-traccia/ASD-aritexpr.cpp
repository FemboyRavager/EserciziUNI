// FILE DA MODIFICARE
#include "ASD-aritexpr.h"
#include "ASD-stack.h"
#include "ASD-token.h"
#include <string>

using namespace my_stack;
using namespace std;

void eval(Stack &exprStack, bool &isSecondOperand) {
  token firstTok = pop(exprStack);
  if (firstTok.k == NUMERO && isEmpty(exprStack)) {
    // cerr << "\nUnico token: " << firstTok.val << endl;
    push(firstTok, exprStack);
    return;
  }
  token newTok;
  int secondN = pop(exprStack).val;
  kind op = pop(exprStack).k;
  int firstN = pop(exprStack).val;
  pop(exprStack);
  token prevToken;
  if (!isEmpty(exprStack)) {
    prevToken = pop(exprStack); //guarda il prossimo token
    prevToken.k == PARENTESI_APERTA ? isSecondOperand = false : isSecondOperand = true; //se è una parentesi, il risultato sarà il primo operando della prossima expr, altrimenti il secondo.
    push(prevToken, exprStack); //rimette il token. Non potendo modificare il .h non ho potuto fare una funzione top() nel file stack :(
  }
  int res = 0;
  switch ((int)op) {
  case 3:
    res = firstN + secondN;
    break;
  case 4:
    res = firstN - secondN;
    break;
  case 5:
    res = firstN * secondN;
  }
  newTok.val = res;
  newTok.k = NUMERO;
  push(newTok, exprStack);
}

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica*/
/*solleva un eccezione di tipo string*/
/*con valore: "Lexical Error" se st non è composta da tokens*/
/*e valore: "Syntactical Error" se st è ben formata*/
int compute_arithmetic_expr(const string &st) {
  // TODO
  Stack exprStack = createEmpty();
  int ret = 0;
  // try {
  string stCopy = st;
  int syntaxStage = 0; // variabile che progredisce man mano che si incontrano token nell'ordine giusto -> '('=1, n=2, *=3, m=4, ')'=5 -> eval
  while (stCopy != "" || stCopy != "\0") {
    // cerr << "\nSyntax stage: " << syntaxStage;
    token tok;
    nextToken(stCopy, tok);
    switch ((int)tok.k) { // stringa desiderata della forma: (n*m)
    case 0:
      // cerr << "(";
      syntaxStage = 1;
      break;
    case 1:
      // cerr << ")";
      syntaxStage == 4 ? syntaxStage = 5 : throw string("Syntactical error");
      break;
    case 2:                                       // NUMERO
      if (syntaxStage == 1 || syntaxStage == 3) { // primo o secondo operando
        syntaxStage++;
      } else if (syntaxStage == 0 && stCopy == "") { // singolo numero
        syntaxStage = 5;
      } else {
        throw string("Syntactical error");
      }
      break;
    case 3:
      // cerr << "+";
    case 4:
      // cerr << "-";
    case 5:
      // cerr << "*";
      syntaxStage == 2 ? syntaxStage = 3 : throw string("Syntactical error");
    }
    push(tok, exprStack);
    if (syntaxStage == 5) {
      bool isResultSecondOperand = false;
      eval(exprStack, isResultSecondOperand);
      isResultSecondOperand ? syntaxStage = 4 : syntaxStage = 2;  // setta il syntax stage a 4 o 2 in base a se il
                                                                  // risultato dell'operazione evaluata sarà il primo
                                                                  // o secondo operando nella prossima espressione
    }
    // cerr << "\nStringa rimanente: " << stCopy << endl;
  }
  ret = pop(exprStack).val;
  if (!isEmpty(exprStack)) {
    // cerr << "AAA";
    throw string("Bruh"); //non dovrebbe mai essere raggiunto
  }
  // cerr << endl;
  // } catch (string err) {
  //   //cerr << err;
  // }
  return ret;
}
