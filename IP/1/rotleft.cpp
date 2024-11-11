#include <iostream>
using namespace std;

int main() {
	float a=0, b=0, c=0;
	cout<<"Seguire le istruzioni correttamente. Inserire caratteri non float risulterà in una prematura terminazione del codice\n\n";
	cout<<"Inserire tre valori float di fila, uno alla volta\n";
	cin>>a>>b>>c;
	cout<<"a: "<<a<<" |b: "<<b<<" |c: "<<c<<endl;
	
	float temp=a;
	
	a=b;
	b=c;
	c=temp;
	
	
	cout<<endl<<"a: "<<a<<" |b: "<<b<<" |c: "<<c<<endl;
	
	return 0;
}