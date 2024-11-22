#include <iostream>
using namespace std;

struct err {
  string functionName;
  string paramName;
  int paramValue;
};

bool isOne(float f1, float f2, float f3) {
  if (f1 == 0) {
    err error;
    error.functionName = "isOne";
    error.paramName = "f1";
    error.paramValue = f1;
    throw error;
  }
  if (f2 == 0) {
    err error;
    error.functionName = "isOne";
    error.paramName = "f2";
    error.paramValue = f2;
    throw error;
  }
  if (f3 == 0) {
    err error;
    error.functionName = "isOne";
    error.paramName = "f3";
    error.paramValue = f3;
    throw error;
  }
  float multResult = f1 * f2 * f3;
  float divResult = multResult / f1;
  divResult = divResult / f2;
  divResult = divResult / f3;
  if (divResult) {
    return true;
  } else
    return false;
}

int main() {
  float f1=5, f2=343.45, f3=9;
  try {
    //cout << isOne(3.2, 5, 9.65);
    if (isOne(f1, f2, f3)) {
      cout<<"NICE";
    } else
      cout<<"NOT NICE";
  } catch (err& error) {
    cout<<"Error in function: '"<<error.functionName<<"', parameter: '"<<error.paramName<<"' with invalid value: "<<error.paramValue<<endl;
    cout<<"Value cannot be 0 since we need to divide by it"<<endl;
  }
}
