#include "d_array.h"
#include <iostream>
using namespace std;

void read_d_array(dynamic_array &d) {
  int s = -5;
  while (s < 1) {
    cout << "Inserisci la dimensione dell'array" << endl;
    cin >> s;
  }
  d.size = s;
  d.store = new double[s];
  for (unsigned int i = 0; i < (unsigned int)s; i++) {
    cout << "Inserisci un valore: ";
    cin >> d.store[i];
  }
}

void print_d_array(const dynamic_array &d) {
  double *p = d.store;
  cout << "I valori contenuti nell'array sono: { ";
  for (unsigned int i = 0; i < d.size; i++) {
    cout << *(p + i) << (i < (d.size - 1) ? ", " : " }\n");
  }
}

void delete_d_array(dynamic_array &d) {
  // cout<< "Attempting deletion of array of size: "<<d.size<<endl;
  if (d.size > 0) {
    delete[] d.store;
    d.size = 0;
    cout << "Deletion succesful" << endl;
  } else {
    string child = "ERRORE: Array non esistente in memoria\n";
    throw child;
  }
}

void create_d_array(dynamic_array &d, int size, double value) {
  if (d.size<0) {
    string child = "Size negativa.\n";
    throw child;
  }
  if (d.size!=0) {
    cout<<"Array già esistente; deletion e creazione nuovo array"<<endl;
    delete_d_array(d);
  }
  d.size = size;
  d.store = new double[size];
  for (int i=0; i<size; i++) {
    d.store[i]=value;
  }
}
