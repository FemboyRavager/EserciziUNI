#include <string>
#include "ll.h"

using namespace std;

void addhead(ll &s, char & c) {
	ll tmp = new elem;
	tmp->next = s;
	tmp->c = c;
	s = tmp;
}

bool removehead(ll &s, char & c) {
	if (!s)
		return false;
	c = s->c;
	ll aux = s;
	s = s->next;
	delete aux;
	return true;
}

int size(ll s) {
	ll cur = s;
	int count=0;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}