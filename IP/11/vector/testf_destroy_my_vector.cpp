#include "my_vector.h"
#include <iostream>
using namespace std;

int main() {
  const unsigned int N=5;
  try {
    my_vector myVec = create_my_vector(N);
    for (unsigned int i=0; i<(N*2); i++) {
      safe_push_back_my_vector_element(myVec, i*3);
      print_my_vector_status(myVec);
    }
    cout << "-----------------------------------------" << endl;
    cout << "Deallocating memory and setting size and capacity to 0" << endl;
    destroy_my_vector(myVec);
    cout << "Printing empty vector" << endl;
    print_my_vector_status(myVec);
  } catch (string &err) {
    cout << err;
  }
}
