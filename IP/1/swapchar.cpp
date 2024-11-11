#include <iostream>
using namespace std;

int main() {
	char a=0,b=0;
	
	cout<<"Inserire primo carattere ";
	cin>>a;
	cout<<"Inserire secondo carattere ";
	cin>>b;
	
	cout<<endl<<"a: "<<a<<endl<<"b: "<<b;
	
	char c=a;
	a=b;
	b=c;
	
	cout<<endl<<"a: "<<a<<endl<<"b: "<<b<<endl;
	
	return 0;
}