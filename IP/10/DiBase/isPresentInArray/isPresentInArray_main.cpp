#include <iostream>
#include "isPresentInArray_funct.h"
using namespace std;

struct inputData {
  int arr[3];
  int size;
  int x;
};

int main() {
  const int N = 3;
  inputData data[3];
  data[0].arr[0] = 0;
  data[0].arr[1] = 1;
  data[0].arr[2] = 2;
  data[0].size = 3;
  data[0].x = 1;

  data[1].arr[0] = 0;
  data[1].arr[1] = 1;
  data[1].arr[2] = 2;
  data[1].size = 3;
  data[1].x = 3;

  data[2].arr[0] = 0;
  data[2].arr[1] = 1;
  data[2].arr[2] = 2;
  data[2].size = 3;
  data[2].x = 2;
  //cout << isPresentInArray(arr, N, 3);
  cout<<endl;
  for(int i=0; i<N; i++) {
    cout<< "Looking for " << data[i].x<< " in array: {";
    for (int j=0; j<N; j++) {
      cout<<data[i].arr[j]<< (j==(N-1)? "" : ",");
    }
    cout<<"}\n";

    if (isPresentInArray(data[i].arr, data[i].size, data[i].x)) {
      cout<<data[i].x<< " is present in array"<<endl;
    } else {
      cout<<data[i].x<< " is NOT present in array"<<endl;
    }
    cout<<endl;

  }
}
