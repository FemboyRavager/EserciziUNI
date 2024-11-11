#include <iostream>
using namespace std;

int main() {
	cout<<"Inserire primo valore numerico: ";
	int a=0;
	cin>>a;
	cout<<"Inserire primo valore numerico: ";
	int b=0;
	cin>>b;
	
	cout<<endl<<"a vale: "<<a<<endl;
	cout<<"b vale: "<<b<<endl;
	
	int c=a;
	
	a=b;
	b=c;
	
	cout<<endl<<"a vale: "<<a<<endl;
	cout<<"b vale: "<<b<<endl;
	
	
	
	return 0;
}