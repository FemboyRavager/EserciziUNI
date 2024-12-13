#include "string_ord_list.h"
#include <iostream>

using namespace std;

int main() {
  ordList L = nullptr;
  cerr << endl
       << (isEmptyList(L) ? "List is empty" : "List is not empty") << endl;
  cerr << "\nInserting elements\n";
  insertElement(L, "a");
  insertElement(L, "b");
  insertElement(L, "z");
  insertElement(L, "c");
  insertElement(L, "ab");
  insertElement(L, "0");
  printList(L);
  cerr << endl
       << (isEmptyList(L) ? "List is empty" : "List is not empty") << endl;
  /*
  cerr << endl << "Testing readList" << endl;
  readList(L);
  printList(L);*/
  cerr << endl
       << "--The list is currently " << listSize(L) << " cells long" << endl;
  unsigned int index = 3;
  cerr << endl << "Testing getElement with index: " << index << endl;
  cerr << "--The element at post" << index << " is " << getElement(L, index)
       << endl;
  cerr << endl << "Testing deleteElementAt with index: " << index << endl;
  deleteElementAt(L, index);
  printList(L);

  cerr << endl << "Testing deleteElementOnce with element: 0" << endl;
  deleteElementOnce(L, "0");
  printList(L);

  cerr << endl << "Testing deleteElementOnce with element: z" << endl;
  deleteElementOnce(L, "z");
  printList(L);

  cerr << endl << "Testing deleteElementOnce with element: ab" << endl;
  deleteElementOnce(L, "ab");
  printList(L);

  string deleteVictim = "H";
  cerr << endl << "Inserting a bunch of identical elements" << endl;
  insertElement(L, deleteVictim);
  insertElement(L, deleteVictim);
  insertElement(L, deleteVictim);
  printList(L);
  cerr << endl << "Testing deleteAllElements with element: " <<deleteVictim <<endl;
  deleteAllElements(L, deleteVictim);
  printList(L);

  cerr << endl << "Creating copy of list"<<endl;
  ordList L2 = nullptr;
  insertElement(L2, "a");
  insertElement(L2, "b");
  insertElement(L2, "c");
  
  cerr << "\nL: ";
  printList(L);
  cerr << "\nL2: ";
  printList(L2);
  cerr << endl << (listAreEqual(L, L2)?"Sono uguali\n":"Sono diverse\n");
  cerr << "Inserisco elemento extra in L"<<endl;
  insertElement(L, "b");
  printList(L);
  cerr << endl;
  printList(L2);
  cerr << endl << (listAreEqual(L, L2)?"Sono uguali\n":"Sono diverse\n");

  cerr << "\n\nNow testing concatList\n";
  ordList concatL = nullptr;
  concatL = concatLists(L, L2);
  cerr << endl;
  printList(concatL);
  
  cerr << "\n\nNow testing unionList with different lists\n";
  insertElement(L2, "4");
  insertElement(L2, "h");
  insertElement(L2, "P");
  insertElement(L2, "P");
  cerr << "\nL: ";
  printList(L);
  cerr << "\nL2: ";
  printList(L2);
  ordList unitedList = nullptr;
  unitedList = unionLists(L, L2);
  cerr << endl;
  cerr << "unitedList: ";
  printList(unitedList);
  cerr << endl;

  cerr << "\n\nNow testing intersectLists\n";
  cerr << "\nL: ";
  printList(L);
  cerr << "\nL2: ";
  printList(L2);
  ordList intersectedList = nullptr;
  intersectedList = intersectLists(L, L2);
  cerr << endl;
  cerr << "interesctedList: ";
  printList(intersectedList);
  cerr << endl;
}
