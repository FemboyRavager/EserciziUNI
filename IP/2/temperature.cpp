#include <iostream>
using namespace std;

int main() {
	
	int Temp=0;
	
	cout<<"Inserire temperatura:";
	cin>>Temp;
	
	if (Temp>=-20 && Temp<=0)
		cout<<"Freddo incredibile";
	else if (Temp>=1 && Temp<=15)
		cout<<"Freddo";
	else if (Temp>=16 && Temp<=23)
		cout<<"Normale";
	else if (Temp>=24 && Temp<=30)
		cout<<"Caldo";
	else if (Temp>=31 && Temp<=40)
		cout<<"Caldo da morire";
	else 
		cout<<"Non ci credo, il termometro deve essere rotto";
	
	cout<<endl;
	
	return 0;
}