#include <string>
#include "list.h"
#include <vector>
#include <iostream>
using namespace std;

unsigned int computeListSize(const List l) {
	if (!l)
		return 0;
	unsigned int count = 0;
	List cur = l;
	do {
		count++;
		cur = cur->next;
	}while(cur!=l);
	return count;
}

bool allDiffInCircList(const List l) {
	if (!l)
		return true;
	List cur = l;
	vector<Elem> occurrences;
	do {
		for(long unsigned int i=0;i<occurrences.size();i++) {
			if(cur->elem == occurrences.at(i))
				return false;
		}
		occurrences.push_back(cur->elem);
		cur = cur->next;
	}while(cur!=l);
	return true;
}

bool checkOccurrence(List l, int v) {
	List cur = l;
	do {
		if (cur->elem == v)
			return true;
		cur = cur->next;
	} while(cur != l);
	return false;
}

void deleteAllCircList(List &l,int v) {
	if (!l)
		return;
	List cur = l;
	List prev = cur;
	while(checkOccurrence(l, v)) {
		if (cur == cur->next) { //single element list
			delete cur;
			l=nullptr;
			cur = l;
			return;
		}
		if (cur->elem == v && cur == l) { //head deletion
			List cur2 = cur;
			while(cur2->next != cur) {
				cur2 = cur2->next;
			}
			cerr << "\n==cur: "<<cur->elem<< " @ "<<cur<<endl;
			cerr << "==cur2: "<<cur2->elem<< " @ "<<cur2<<endl;
			l = cur->next;
			cur2->next = l;
			delete cur;
			cur = l;
			continue;
		}
		if (cur->elem == v) {
			cerr << "\nCur: "<< cur->elem<<endl;
			cerr << "Prev: "<< prev->elem<<endl;
			prev->next = cur->next;
			delete cur;
			cur = prev;
		}
		cerr << "\nCur: "<< cur->elem<<endl;
		prev = cur;
		cur = cur->next;
	}
}