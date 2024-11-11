#include <iostream>
using namespace std;

int main() {
	float radius=0, mathPi=3.14;
	cout<<"Inserire radius del cerchio"<<endl;
	cin>>radius;
	
	float circumference=2*radius*mathPi;
	float area=mathPi*radius*radius;
	
	cout<<"Perimetro: "<<circumference<<endl;
	cout<<"Area: "<<area<<endl;
	
	return 0;
}