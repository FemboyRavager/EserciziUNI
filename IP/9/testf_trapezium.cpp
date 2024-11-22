#include <iostream>
using namespace std;

struct err {
  string functionName;
  string paramName;
  int paramValue;
};

void replicate(int n) {
  for (int i = 0; i < n; i++) {
    cout << "*";
  }
}

void drawTrapezium(int lesserBase, int greaterBase) {
  if (lesserBase < 1) {
    err error;
    error.functionName = "drawTrapezium";
    error.paramName = "lesserBase";
    error.paramValue = lesserBase;
    throw error;
  }
  if (greaterBase < 1) {
    err error;
    error.functionName = "drawTrapezium";
    error.paramName = "greaterBase";
    error.paramValue = greaterBase;
    throw error;
  }
  int height = greaterBase - lesserBase + 1;
  for (int i = 0; i < height; i++) {
    replicate(lesserBase + i);
    cout << endl;
  }
}

int main() {
  int base1 = 0, base2 = 0;
  cout<<"Inserire prima base: ";
  cin>>base1;
  cout<<"Inseire seconda base: ";
  cin>>base2;
  int lesserBase = (base1 < base2) ? base1 : base2;
  int greaterBase = (base2 > base1) ? base2 : base1;
  cout << "Lesser: " << lesserBase << "\nGreater: " << greaterBase << endl;
  try {
    drawTrapezium(lesserBase, greaterBase);
  } catch (err& error) {
    cout<<"Error in function: '"<<error.functionName<<"', parameter: '"<<error.paramName<<"' with invalid value: "<<error.paramValue<<endl;
    cout<<"Value needs to be positive"<<endl;
  }
}
