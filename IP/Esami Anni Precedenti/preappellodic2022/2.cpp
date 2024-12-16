#include <iostream>
#include <vector>
using namespace std;

vector<int> nMultiples(int n) {
  if (!(n>0)) {
    //error handling blah blah
  }
  vector<int> result;
  /*
  for (int i=n;i<=(n*n);i++) {
    if (i%n==0)
      result.push_back(i);
  }*/
  for (int i=n; i<=(n*n); i+=n) {
    result.push_back(i);
  }
  return result;
}

vector<int> nDividers(int n) {
  if (!(n>0)) {
    //error handling
  }
  vector<int> result;
  for (int i=1; i<=n ; i++) {
    if (n%i==0)
      result.push_back(i);
  }
  return result;
}

int main() {
  int n;
  cout << "Inserire n\n";
  cin >> n;
  vector<int> result = nMultiples(n);
  cout << "Multipli: \n";
  for (unsigned int i=0 ; i<result.size() ; i++) {
    cout << result[i]<<",";
  }
  cout << endl;
  cout << "Divisori: \n";
  result = nDividers(n);
  for (unsigned int i=0 ; i<result.size() ; i++) {
    cout << result[i]<<",";
  }
  cout << endl;
}
