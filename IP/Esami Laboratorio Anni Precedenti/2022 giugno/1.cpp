#include <iostream>
#include "hist.h"
#include "ll.h"
using namespace std;


void swap ( Hist& h, int i, int elementIndex) {
	Bin aux = h[i];
	h[i] = h[elementIndex];
	h[elementIndex] = aux;
}

//--------------

void add ( Hist & h , int v ) {
    for (long unsigned int i=0;i<h.size();i++) {
    	if(h[i].value == v) {
    		h[i].num++;
    		return;
    	}
    }
    Bin aux;
    aux.value = v;
    aux.num = 1;
    h.push_back(aux);
}

void sort ( Hist & h ) {
	for (unsigned long int i=0;i<h.size();i++) {
		int currentElementPos = i;
		for (unsigned long int j = i+1; j<h.size() ;j++) {
			if (h[currentElementPos].value > h[j].value) {
				currentElementPos = j;
			}
		}
		swap(h, i, currentElementPos);
	}
}

int count ( const Hist & h , int v ) {
	for (unsigned long int i=0;i<h.size();i++) {
		if (h[i].value == v) {
			return h[i].num;
		}
	}
	return 0;
}
