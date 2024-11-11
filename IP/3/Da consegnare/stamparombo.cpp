#include <iostream>

using namespace std;

int main() {
	int n=0;
	cout<<"Inserire numero intero positivo: ";
	cin>>n;

	if ( n<=0 ) {
	  cout<<"\nInput non valido\n";
	  return 0;		
	}
	
	int diagonal=(2*n)+1;

	cout<<endl<<"Diagonale: "<<diagonal<<endl<<"Diagonale/2 int: "<<(diagonal/2)<<endl<<endl;

	for ( int i=1 ; i<=(diagonal/2) ; i++ ) {
	    for ( int spazi=-1 ; spazi<(diagonal/2)-i ; spazi++ )
	      cout<<" ";
	    for ( int star=1 ; star<(i*2) ; star++ )
	      cout<<"*";
	  cout<<endl;
	}

	for ( int i=0 ; i<diagonal ; i++ ) {
	  cout<<"*";
	}

	cout<<endl;

	for ( int i=1 ; i<=(diagonal/2) ; i++ ) {
	  for ( int spazi=-1 ; spazi<i-1 ; spazi++ )
	    cout<<" ";
	  for ( int star=0 ; star<(diagonal-(2*i)) ; star++ )
            cout<<"*";
	  cout<<endl;
	}
	
}
