#include <iostream>
using namespace std;

int main() {
	int birthYear=0, birthMonth=1, birthDay=1;
	cout<<"Inserire giorno di nascita"<<endl;
	cin>>birthYear;
	
	cout<<birthDay<<"."<<birthMonth<<"."<<birthYear<<endl;
	
	int ageYear=2024-birthYear;
	cout<<ageYear;
	
	return 0;
	
}