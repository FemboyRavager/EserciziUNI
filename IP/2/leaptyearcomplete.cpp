#include <iostream>
using namespace std;

int main() {

	int anno=0;
	cout<<"Inserire anno da verificare: ";
	cin>>anno;

	if (anno%100==0){													//Secolare
		if (anno%400==0) {												//&& divisibile per 400
			cout<<"\nBisestile\n";
			return 0;
		}
	} else if (anno%4==0) {												//Non secolare && divisibile per 4 
		cout<<"\nBisestile\n";
		return 0;
	}
	
	cout<<"\nNon bisestile\n";
	
	return 0;
}