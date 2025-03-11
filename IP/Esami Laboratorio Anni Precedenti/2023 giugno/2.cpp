#include <string>
#include "list.h"

using namespace std;

void inserimentoInTesta(List &list, City newCity) {
	if (!list) {
		List aux = new Cell;
		aux->city = newCity;
		aux->next = nullptr;
		aux->prev = nullptr;
		list = aux;
		return;
	}
	
	List aux = new Cell;
	list->prev = aux;
	aux->city = newCity;
	aux->next = list;
	aux->prev = nullptr;
	list = aux;
}


string stampaAndata(List list) {
	List cur = list;
	string out = "";
	while(cur) {
		out = out + cur->city;
		cur = cur->next;
	}
	return out;
}

string stampaRitorno(List list) { //sfrutto prev invece di usare ricorsione
	List cur = list;
	string out = "";
	while(cur->next) {
		cur = cur->next;
	}
	while(cur) {
		out = out + cur->city;
		cur = cur->prev;
	}
	return out;
}

string stampaAdiacenti(List list, City newCity) {
	if (!list) {
		return "";
	}
	List cur = list;
	string out = "-,-,-";
	while(cur){
		if(cur->city == newCity) {
			if (cur->prev && cur->next) {
				out = cur->prev->city + "," + cur->city + "," + cur->next->city;
			} else if (cur->prev && !cur->next) {
				out = cur->prev->city + "," + cur->city + ",-";
			} else if (!cur->prev && cur->next) {
				out = "-," + cur->city + "," + cur->next->city;
			} else if (!cur->prev && !cur->next) {
				out = "-," +  cur->city + ",-";
			}
			return out;
		}
		cur=cur->next;	
	}
	return out;
}
