#include "my_vector.h"
#include <iostream>
using namespace std;

my_vector create_my_vector(unsigned int capacity) {
  if (capacity <= 0) {
    string child = "create_my_vector: capacity fornita non positiva";
    throw child;
  }
  my_vector newVector;
  newVector.capacity = capacity;
  newVector.size = 0;
  newVector.store = new double[capacity];
  return newVector;
}

void print_my_vector_status(const my_vector &v) {
  if (v.size == 0) {
    string child = "my_vector is empty";
    throw child;
  }
  cout << "**********************" << endl;
  cout << "my_vector size = " << v.size << endl;
  cout << "my_vector capacity = " << v.capacity << endl;
  cout << "my_vector store = { ";
  for (unsigned int i = 0; i < v.size; i++) {
    cout << v.store[i] << (i < v.size - 1 ? ", " : " }\n");
  }
}

void push_back_my_vector_element(my_vector &v, double x) {
  if (v.size == v.capacity) {
    string child = "push_back_my_vector_element: Impossibile inserire elemento "
                   "in Array pieno";
    throw child;
  } else {
    v.store[v.size] = x;
    v.size++;
  }
}

double pop_back_my_vector_element(my_vector &v) {
  if (v.size == 0) {
    string child = "pop_back_my_vector_element: Impossibile estrarre elemento "
                   "da Array vuoto";
    throw child;
  } else {
    v.size--;
    return v.store[v.size-1];
  }
}
