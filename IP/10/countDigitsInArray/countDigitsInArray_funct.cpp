#include <iostream>
#include "countDigitsInArray_funct.h"
using namespace std;

int countDigitsInArray(char* v, int size) {
  char* pv;
  pv = v;
  unsigned int count=0;
  //cout<<"pv inizialmente punta a "<<pv<<endl;
  //cout<<"pv punta a "<<pv<<", con valore "<<*pv<<endl<<endl;
  cout<<endl<<"Array: {";
  for (int i = 0; i < size; i++) {
    //cout << *pv <<" with pv pointing at: "<<pv<< endl;
    cout<<*pv<<",";
    if (*pv >= 48 && *pv <=57) { count++; }
    pv++;
  }
  cout<<"}";
  return count;
}

