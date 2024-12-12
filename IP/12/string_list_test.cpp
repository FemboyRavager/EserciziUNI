#include "string_list.h"
#include <iostream>

using namespace std;

int main() {
  list L = nullptr;
  try {
    cout << "Is the list empty? " << ((isEmpty(L) ? "Yes" : "No")) << endl;
    headInsert(L, "d");
    headInsert(L, "c");
    headInsert(L, "b");
    headInsert(L, "A");
    tailInsert(L, "Z");
    // read(L);
    cout << "List size: " << size(L) << endl;
    cout << "Is the list empty? " << ((isEmpty(L) ? "Yes" : "No")) << endl;
    unsigned int index = 3;
    cout << "Element at pos" << index << ": " << getElem(L, index) << endl;
    string insertion = "insertion";
    cerr << "Replacing element at pos " << index << " with: " << insertion
         << endl;
    insertAt(L, insertion, index);
    print(L);
    cerr << "Deleting element at pos " << index << endl;
    deleteAt(L, index);
    print(L);
    string deleteVictim = "c";
    cerr << "Deleting first element equal to: " << deleteVictim;
    deleteOnce(L, deleteVictim);
    print(L);
    deleteVictim = "H";
    cerr << "Adding a bunch of identical elements\n";
    headInsert(L, deleteVictim);
    tailInsert(L, deleteVictim);
    insertAt(L, deleteVictim, 3);
    print(L);
    cerr << "Deleting all elements just added ("<<deleteVictim<<")\n";
    deleteAll(L, deleteVictim);
    print(L);
    /*
    cout << "Data: " << L->data << endl;
    cout << "Next: " << L->next << endl;
    cout << "Data: " << L->next->data << endl;
    cout << "Next: " << L->next->next << endl;

    list cur = L;
    while (cur != nullptr) {
      cerr << "--" << cur->data << " | " << cur->next << endl;
      cur = cur->next;
    }*/
  } catch (string &err) {
    cout << err;
  }
}
