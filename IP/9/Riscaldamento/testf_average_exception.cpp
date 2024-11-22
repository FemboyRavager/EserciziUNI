#include <iostream>

using namespace std;

float average (int hm) {
  if (hm<0) {
    int err=42;
    throw err;
  }
  float sum=0;
  for ( int i=0 ; i<hm ; i++ ) {
    cout<<endl<<"Inserisci un numero: ";
    float x;
    cin>>x;
    sum += x;
  }
  return sum/hm;
}

int main() {
  try {
    cout<<"Di quanti numeri vuoi fare la media? ";
    int how_many;
    cin>>how_many;
    float result=average(how_many);
    cout<<endl<<"La media è "<<result<<endl;
  }
  catch (int& err) {
    if (err==42)
      cout<<"buranyaa"<<endl;
  }
}
