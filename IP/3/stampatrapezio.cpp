#include <iostream>
using namespace std;

int main() {
	int b=0,B=0,x=0,y=0;
	cout<<"Inserire primo numero intero positivo: ";
	cin>>x;

	cout<<"Inserire secondo numero intero positivo: ";
	cin>>y;

	if(x>=y) {
	  B=x;
	  b=y;
	} else {
	    B=y;
	    b=x;
	}

	if ( b<=0 || B<=0 || b>B ) {
	  cout<<"\nInput non valido\n";
	  return 0;		
	}
	
	int startingXNumber=B-b+1;
	
	cout<<"B: "<<B<<endl<<"b: "<<b<<endl<<"First line x: "<<startingXNumber<<endl;

	for(int i=0; i<=b-1 ; i++, startingXNumber++) {
	  for ( int j=0 ; j<startingXNumber ; j++ )
	    cout<<"x";
	  cout<<endl;
	}
}
