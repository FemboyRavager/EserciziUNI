#include <iostream>
using namespace std;

int main() {
	
	float number=0;
	cout<<"Inserire numero reale: ";
	cin>>number;
	
	float numberCopy=number;
	float result=0;
	
	result= numberCopy/4.9;
	result=result/3.53;
	result=result/6.9998;
	
	result=result*4.9;
	result=result*3.53;
	result=result*6.9998;
	
	cout<<"Numero originale: "<<number<<endl;
	cout<<"Dopo moltiplicazioni e divisioni: "<<result<<endl;
	
	if (result==number)
		cout<<"moltiplicare e' l'inverso di dividere\n";
	else
		cout<<"moltiplicare NON e' l'inverso di dividere\n";
	
	return 0;
}