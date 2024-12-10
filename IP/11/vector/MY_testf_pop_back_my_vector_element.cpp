#include "my_vector.h"
#include <iostream>
using namespace std;

int main() {
  const unsigned int N = 5;
  my_vector myVec;
  try {
    myVec = create_my_vector(N);
    cout << "\nNow starting appending of vector of size: " << myVec.size
         << endl;
    for (unsigned int i = 0; i < N; i++) {
      push_back_my_vector_element(myVec, i * 3);
      print_my_vector_status(myVec);
    }
    cout << "\nNow starting popping vector of size: " << myVec.size << endl;
    for (unsigned int i = 0; i < myVec.size + 1; i++) {
      // cout<<endl<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH"<<endl;
      pop_back_my_vector_element(myVec);
      print_my_vector_status(myVec);
      destroy_my_vector(myVec);
    }
  } catch (string &err) {
    cout << err;
    destroy_my_vector(myVec);
  }
}
