#include <iostream>
using namespace std;

int main() {
	
	float a=0, b=0, c=0;
	cout<<"Inserire 3 numeri reali:";
	cin>>a>>b>>c;
	
	if ( !( a>(b+c) ) && !( b>(a+c) ) && !( c>(a+b) ) ) {
		cout<<"\nI lati dati possono essere lati di un triangolo\n";
	} else
		cout<<"\nI lati dati non possono essere lati di un triangolo\n";
	
	return 0;
}