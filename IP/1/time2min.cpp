#include <iostream>
using namespace std;

int main() {
	cout<<"Seguire le istruzioni. Inserire numeri al di fuori degli intervalli indicati causerà la prematura fine del programma\n\n";
	cout<<"Inserire numero di ore (tra 0 e 23): ";
	int h;
	cin>>h;
	if (h<0 || h>23) {
		cout<<"Per cortesia seguire direzioni\n";
		return 0;
	}
	
	cout<<"Inserire numero di minuti (tra 0 e 59): ";
	int m;
	cin>>m;
	if (m<0 || m>59) {
		cout<<"Per cortesia seguire direzioni\n";
		return 0;
	}
	
	cout<<"Minuti totali: "<<(h*60)+m<<endl;
	
	return 0;
}