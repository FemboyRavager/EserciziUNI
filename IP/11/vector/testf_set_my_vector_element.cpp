#include "my_vector.h"
#include <iostream>
using namespace std;

int main() {
  const unsigned int N = 5;
  cout << "Primo blocco try-catch per index<0: " << endl;
  try {
    my_vector myVec = create_my_vector(N);
    cout << "\nNow starting appending of vector of size: " << myVec.size
         << endl;
    for (unsigned int i = 0; i < N; i++) {
      push_back_my_vector_element(myVec, i * 3);
      print_my_vector_status(myVec);
    }
    int index = 2, value = 99;
    cout << "\nSetting element in slot: " << index << " to value: " << value
         << endl;
    set_my_vector_element(myVec, value, index);
    print_my_vector_status(myVec);

    index = -3;
    cout << "\nSetting element in slot: " << index << " to value: " << value
         << endl;
    set_my_vector_element(myVec, value, index);
    print_my_vector_status(myVec);
  } catch (string &err) {
    cout << err;
  }
  cout << "--------------------------------------------------" << endl;
  cout << "Secondo blocco try-catch per index>v.size-1: " << endl;
  try {
    my_vector myVec = create_my_vector(N);
    cout << "\nNow starting appending of vector of size: " << myVec.size
         << endl;
    for (unsigned int i = 0; i < N; i++) {
      push_back_my_vector_element(myVec, i * 3);
      print_my_vector_status(myVec);
    }
    int index = 2, value = 99;
    cout << "\nSetting element in slot: " << index << " to value: " << value
         << endl;
    set_my_vector_element(myVec, value, index);
    print_my_vector_status(myVec);

    index = 90;
    cout << "\nSetting element in slot: " << index << " to value: " << value
         << endl;
    set_my_vector_element(myVec, value, index);
    print_my_vector_status(myVec);
  } catch (string &err) {
    cout << err;
  }

  cout << "------------------------------------------" << endl;
  cout << "Terzo blocco try-catch per my_vector con v.size==0: " << endl;
  try {
    my_vector myVec = create_my_vector(N);
    int index = 2, value = 99;
    cout << "\nSetting element in slot: " << index << " to value: " << value
         << endl;
    set_my_vector_element(myVec, value, index);
    print_my_vector_status(myVec);

    destroy_my_vector(myVec);
  } catch (string &err) {
    cout << err;
  }
}
