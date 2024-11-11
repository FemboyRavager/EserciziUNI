#include <iostream>

using namespace std;


int main() {
  const int N=5;
  int numeri[N]={};
  int maxVal=0, maxCount=0;

  for ( int i=0 ; i<5 ; i++ ) {
    cin >> numeri[i];
  }

  for ( int i=0 ; i<5 ; i++ ) {
    if ( numeri[i]==maxVal ) {
      maxCount++;
    }
    if (numeri[i]>maxVal) {
      maxVal=numeri[i];
      maxCount=1;
    }
  }
	
  cout << endl << "maxVal = " << maxVal << endl;
  cout << "maxCount = " << maxCount << endl;

  return 0;
}
