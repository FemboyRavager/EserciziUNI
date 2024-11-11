#include <iostream>
using namespace std;

int main() {
	
	cout<<"Inserire un numero intero: ";
	int number;
	cin>>number;
	
	if (number==0){				//0%13 dà divisibile per qualche motivo quindi lo metto ad eccezione
		cout<<"\nNon divisibile per 13\n";
		return 0;
	}
	
	(number%13)==0 ? cout<<"\nDivisibile per 13\n" : cout<<"\nNon divisibile per 13\n";
	
	return 0;
}