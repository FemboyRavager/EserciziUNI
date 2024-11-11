#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	srand(time(NULL));

	char player1=0, player2=0;
	bool continuePlaying=true;
	char continueUserInput=0;
	do {
		cout<<"Inserire mossa del giocatore come lettere 'f', 'c' o 's': ";
		cin>>player1;

		player2 = (rand()%3);

		switch (player2) {
		case 0:
			player2='f';
			break;
		case 1:
			player2='c';
			break;
		case 2:
			player2='s';
			break;
		default:
			cout<<"Randomization error\n";
		}


		switch (player1) {
		case 'f':
		case 'c':
		case 's':
			break;
		default:
			cout<<"\nGiocatore 1 seguire istruzioni\n";
			return 0;
		}
	
	
	
	switch (player1) {								//Orrida ripetizione di switch ma il primo necessita cascata e il secondo no; non ho trovato modo di integrarli
	case 'f':
		cout<<"Giocatore 1 gioca forbice\n";
		break;
	case 'c':
		cout<<"Giocatore 1 gioca carta\n";
		break;
	case 's':
		cout<<"Giocatore 1 gioca sasso\n";
		break;
	}
	
	switch (player2) {
	case 'f':
		cout<<"Computer gioca forbice\n";
		break;
	case 'c':
		cout<<"Computer gioca carta\n";
		break;
	case 's':
		cout<<"Computer gioca sasso\n";
		break;
	}
	
	
	if (player1==player2) {							//Fine prematura
		cout<<"Pari"<<endl;
		cout<<endl;
	
		cout<<"Continuare? Scrivere s per si o n per no\n";
		cin>>continueUserInput;

		if (continueUserInput=='s' || continueUserInput=='S')
			continuePlaying=1;
		else
			continuePlaying=0;
		continue;
	}

	if (player1=='f') {								//P1 forbice
		if (player2=='c')							//&&P2 carta
			cout<<"Player 1 vince";
		else 									//&&P2 sasso
			cout<<"Computer vince";
	} else if (player1=='c') {							//P1 carta
		if (player2=='f')							//&&P2 forbice
			cout<<"Computer vince";
		else									//&&P2 sasso
			cout<<"P1 vince";
	} else if (player1=='s') {							//P1 sasso
		if (player2=='f')							//&&P2 forbice
			cout<<"P1 vince";
		else									//&&P2 carta
			cout<<"Computer vince";
	}

	cout<<endl;
	
	cout<<"Continuare? Scrivere s per si o n per no\n";
	cin>>continueUserInput;

	if (continueUserInput=='s' || continueUserInput=='S')
		continuePlaying=1;
	else
		continuePlaying=0;
	
	} while (continuePlaying);

	cout<<"\nGrazie per aver giocato\n";

	return 0;
}
