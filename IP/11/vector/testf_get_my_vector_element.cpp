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
    cout << "Now getting elements by index" << endl;
    for (unsigned int i = 0; i < myVec.size; i++) {
      cout << "Vector[" << i << "]=" << get_my_vector_element(myVec, i) << endl;
    }

    destroy_my_vector(myVec);
  } catch (string &err) {
    cout << err;
  }
}
