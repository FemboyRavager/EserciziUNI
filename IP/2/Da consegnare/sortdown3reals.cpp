#include <iostream>
using namespace std;

int main() {
	cout<<"Inserire tre numeri reali:";
	float a=1, b=2, c=3;
	cin>>a>>b>>c;
	
	float temp=0;
	
	cout<<endl<<"\nInput:"<<endl<<"A:"<<a<<endl<<"B:"<<b<<endl<<"C:"<<c<<endl;
	
	if (a<b) {
		temp=a;
		a=b;
		b=temp;
	}
	
	if (a<c) {
		temp=a;
		a=c;
		c=temp;
	}
	
	if (b<c) {
		temp=b;
		b=c;
		c=temp;
	}
	
	cout<<endl<<"In ordine decrescente:"<<endl<<"A:"<<a<<endl<<"B:"<<b<<endl<<"C:"<<c<<endl;
	
	return 0;
}