#ifndef STACK_H
#define STACK_H 

#include "ASD-token.h"

// Implementa STACK 
namespace my_stack{
    // tipo base 
    typedef token Elem; 

    const unsigned int BLOCKDIM = 20;

    typedef struct {
	Elem* tokens;
	unsigned int size;
	unsigned int maxsize;
    } Stack;

    /**************************************************/
    /*       prototipi di funzioni da implementare    */
    /**************************************************/

    /* restituisce lo stack vuoto */
    Stack createEmpty();

    /* restituisce true se lo stack e' vuoto */
    bool isEmpty(const Stack&);

	/* aggiunge elem in cima (operazione safe, si può sempre fare) */
	/* NB: se stack implementato con array dinamico, 
	   quando necessario implementare ridimensionamento in espansione*/
    void push(const Elem, Stack&);

	/* toglie dallo stack l'ultimo elemento e lo restituisce */
	/* se lo stack è vuoto solleva una eccezione di tipo string */
	/* NB: se stack implementato con array dinamico, 
	   quando necessario implementare ridimensionamento in contrazione*/
    Elem pop(Stack&);
}

#endif
