#include "d_array.h"
#include <iostream>
using namespace std;

int main() {
  dynamic_array arr;
  read_d_array(arr);
  print_d_array((const dynamic_array)arr);
  try {
    create_d_array(arr, -5, 9);
  } catch (string &err) {
    cout << err;
  }
  print_d_array((const dynamic_array)arr);
  try {
    cout << "Primo tentativo di deletion: ";
    delete_d_array(arr);
  } catch (string &err) {
    cout << err << endl;
  }
  try {
    cout << "Secondo tentativo di deletion: ";
    delete_d_array(arr);
  } catch (string &err) {
    cout << err << endl;
  }
}
