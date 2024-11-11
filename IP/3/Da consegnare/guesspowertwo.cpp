#include <iostream>
using namespace std;

int main() {
  while (true) {
    int n=0;
    cout<<"Inserire numero intero: ";
    cin>>n;
    
    if (n<=0) {
      cout<<"\nSeguire le istruzioni\n";
      continue;
    }
    
    int nSquared=n*n;
    int attempt=0;

    cout<<"Indovina il quadrato: ";
    cin>>attempt;

    if (nSquared==attempt) {
      cout<<"Bravo!\n";
      return 0;
    } else
      cout<<"\nRiprova\n";
  }

}
