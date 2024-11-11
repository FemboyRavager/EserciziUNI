#include <iostream>
using namespace std;

int main() {
	
	cout<<boolalpha;			//Setta flag a true
	
	cout<<"Tre è maggiore di uno: "<< (3>1)<<endl;
	
	cout<<"Quattro diviso due e' minore di zero: "<<((4/2)<0)<<endl;
	
	char zero='0';
	cout<<"Il carattere 'zero' è uguale al valore zero: "<<( 0 == zero )<<endl;
	
	cout<<"Dieci mezzi è compreso fra zero escluso e dieci incluso: "<<(  0<(10/2) && (10/2)<=10 )<<endl;
	
	cout<<"Non e' vero che tre è maggiore di due e minore di uno: "<<( !(3>2 && 3<1) )<<endl;
	
	cout<<"Tre minore di meno cinque implica sette maggiore di zero: "<<( ( !(3<-5) ) || (7>0) )<<endl;
	
	return 0;
	
}