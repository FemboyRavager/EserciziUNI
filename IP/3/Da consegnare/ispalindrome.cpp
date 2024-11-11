#include <iostream>
using namespace std;

int main() {
  cout<<"Inserire intero positivo: ";
  int k=0, inv=0;
  cin>>k;

  int originalK=k;

  if(k<=0) {
    cout<<"Seguire istruzioni\n";
    return 66;
  }
  int mod=0;

  while (k>0){
    mod=k%10;
    k=k/10;
    inv=inv*10;
    inv=inv+mod;
  }

  cout<<"\nNumero originale: "<<originalK<<endl;
  cout<<"\nNumero inverso: "<<inv<<endl;

  if(originalK==inv)
    cout<<endl<<"E' palindromo"<<endl;
  else
    cout<<endl<<"Non e' palindromo"<<endl;

  return 0;
}
