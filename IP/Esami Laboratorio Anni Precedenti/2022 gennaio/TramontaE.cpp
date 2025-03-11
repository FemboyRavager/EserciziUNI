#include <iostream>
#include "bow.h"
#include <vector>
using namespace std;

void scaleBack ( BagOfWords & b, long unsigned int emptyPos ) {
	for (long unsigned int i=emptyPos;i<b.size()-1;i++) {
		b[i]=b[i+1];
	}
	b.pop_back();
}

//-----------------------------------------------

void add ( BagOfWords & b , std :: string w ) {
    for (long unsigned int i=0;i<b.size();i++) {
    	if (b[i].word == w) {
    		b[i].num++;
    		return;
    	}
    }
    Entry aux;
    aux.word = w;
    aux.num = 1;
    b.push_back(aux);    
}

void del ( BagOfWords & b, string w ) {
    for (long unsigned int i=0;i<b.size();i++) {
    	if (b[i].word == w) {
    		if (b[i].num > 1) {
    			b[i].num--;
    		} else if (b[i].num == 1) {
    			scaleBack(b, i);
    		}
    	}
    }
}

int count ( const BagOfWords & b , std :: string w ) {
    int count=0;
	for (long unsigned int i=0;i<b.size();i++) {
		//cerr << "==>" << b[i].word << " ";
		if (b[i].word == w) {
			count= b[i].num;
		}
	}
	return count;
}
