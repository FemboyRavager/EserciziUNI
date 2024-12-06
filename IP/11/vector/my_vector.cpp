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
    string child = "my_vector is empty\n";
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
    return v.store[v.size - 1];
  }
}

void set_my_vector_element(my_vector &v, double value, unsigned int index) {
  if (v.size == 0) {
    string child = "set_my_vector_element: Impossibile impostare un elemento "
                   "di un My_Vector vuoto\n";
    throw child;
  }
  if (index < 0 || index > (v.size - 1)) {
    string child = "set_my_vector_element: Indice fornito non ammissibile\n";
    throw child;
  }
  v.store[index] = value;
}

double get_my_vector_element(const my_vector &v, unsigned int index) {
  if (v.size == 0) {
    string child = "get_my_vector_element: Impossibile leggere un elemento da "
                   "un My_Vector vuoto";
    throw child;
  }
  if (index < 0 || index > v.size - 1) {
    string child = "get_my_vector_element: Indice fornito non ammissibile";
    throw child;
  }
  return v.store[index];
}

void resize_my_vector(my_vector &v, unsigned int new_capacity) {
  if (new_capacity <= 0) {
    string child = "resize_my_vector: new_capacity fornita non positiva";
  }
  double *tempPointer = new double[new_capacity];
  if (v.size > 0 && v.size < new_capacity) {
    for (unsigned int i = 0; i < v.size; i++) {
      *(tempPointer + i) = v.store[i];
    }
  } else if (v.size > new_capacity) {
    for (unsigned int i = 0; i < new_capacity; i++) {
      *(tempPointer + i) = v.store[i];
    }
  }
  if (v.capacity > 0) {
    delete[] v.store;
  }
  v.store = tempPointer;
  v.capacity = new_capacity;
  if (v.size > v.capacity) {
    v.size = v.capacity;
  }
}

void safe_push_back_my_vector_element(my_vector &v, double x) {
  if (v.capacity == 0) {
    resize_my_vector(v, 1);
  }
  try {
    push_back_my_vector_element(v, x);
  } catch (string &err) {
    resize_my_vector(v, v.capacity * 2);
    push_back_my_vector_element(v, x);
  }
}

void destroy_my_vector(my_vector &v) {
  if (v.capacity == 0) {
    return;
  }
  delete[] v.store;
  v.capacity = v.size = 0;
}
