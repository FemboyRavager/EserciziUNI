#include <iostream>
using namespace std;

int main() {
	float base=0, altezza=0;
	cout<<"Inserire base triangolo"<<endl;
	cin>>base;
	cout<<"Inserire altezza triangolo"<<endl;
	cin>>altezza;
	
	cout<<"L'area del triangolo specificato è: "<<(altezza*base)/2<<endl;
	
	return 0;
}