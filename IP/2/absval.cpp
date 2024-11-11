#include <iostream>
using namespace std;

int main() {
	int number=0;
	cout<<"\nInserire numero intero\n";
	cin>>number;
	
	cout<<"Valore assoluto: ";
	//number<0 ? cout<<-number : cout<<number;          non usare ternario con istruzioni, usare per assegnare
	
	number = (number<0) ? number*-1 : number;
	
	cout<<number<<endl;
	
	return 0;
}