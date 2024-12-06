#include "my_vector.h"
#include <iostream>
using namespace std;

int main() {
  const unsigned int N = 5;
  try {
    my_vector myVec = create_my_vector(N);
    cout << "\nNow starting appending of vector of size: " << myVec.size
         << endl;
    for (unsigned int i = 0; i < N; i++) {
      push_back_my_vector_element(myVec, i * 3);
      print_my_vector_status(myVec);
    }
    cout << "-------------------------------------" << endl;
    int newCapacity = 10;
    cout << "Now resizing to capacity: " << newCapacity << endl;
    resize_my_vector(myVec, newCapacity);
    print_my_vector_status(myVec);
    cout << endl << "Now appending more values" << endl;
    for (unsigned int i = 0; i < (newCapacity - N); i++) {
      push_back_my_vector_element(myVec, i * 3);
      print_my_vector_status(myVec);
    }
  } catch (string &err) {
    cout << err;
  }
}
