#include <iostream>
using namespace std;

int main() {
	
	int anno=0;
	cout<<"Inserire anno da verificare: ";
	cin>>anno;
	
	(anno%4)==0 ? cout<<"\nBisestile\n" : cout<<"\nNon bisestile\n";
	
	return 0;
}