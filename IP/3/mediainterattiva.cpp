#include <iostream>
using namespace std;

int main() {
	bool doContinue=1;
	char doContinueUserInput=0;
	int number=0, count=0;
	do {
		int n=0;
		cout<<"\nInserire numero intero\n";
		cin>>n;
		number+=n;
		count++;

		cout<<"\nInserire altro numero? s o n\n";
		cin>>doContinueUserInput;

		if ( doContinueUserInput=='s' || doContinueUserInput=='S' )
			doContinue=1;
		else
			doContinue=0;


	} while(doContinue);
	
	float media=(float)number/count;

	cout<<"\nMedia: "<<media<<endl;

	return 0;
}
