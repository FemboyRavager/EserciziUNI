#include <string>
#include "movestack.h"

void push(MoveStack & ms, char cmd) {
	if (!ms) {
		MoveStack aux = new Move;
		aux->cmd = cmd;
		aux->next = nullptr;
		ms = aux;
		return;
	}
	if (cmd == 'B') {
		pop(ms);
		return;
	}
	MoveStack aux = new Move;
	aux->cmd = cmd;
	aux->next = nullptr;
	MoveStack cur = ms;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = aux;	
}

char pop(MoveStack & ms) {
	MoveStack cur = ms;
	MoveStack prev = cur;
	while (cur->next) {
		prev = cur;
		cur = cur->next;
	}
	prev->next=nullptr;
	char ret = cur->cmd;
	delete cur;
	return ret;
}

void doMove(int &x, int&y, char cmd) {
	switch (cmd) {
		case 'N': 
			y--;
			break;
		case 'S':
			y++;
			break;
		case 'E':
			x++;
			break;
		case 'W':
			x--;
			break;
	}
}