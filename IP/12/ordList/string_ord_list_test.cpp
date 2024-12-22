#include "string_ord_list.h"
#include <iostream>

using namespace std;

int main() {
  ordList L1 = nullptr;
  cerr << endl
       << (isEmptyList(L1) ? "--List is empty" : "--List is not empty") << endl;
  cerr << endl
       << "--The list is currently " << listSize(L1) << " cells long" << endl;
  cerr << "\nInserting elements\n";
  insertElement(L1, "a");
  insertElement(L1, "b");
  insertElement(L1, "z");
  insertElement(L1, "c");
  insertElement(L1, "ab");
  insertElement(L1, "0");
  printList(L1);
  cerr << endl
       << (isEmptyList(L1) ? "--List is empty" : "--List is not empty") << endl;
  /*
  cerr << endl << "Testing readList" << endl;
  readList(L);
  printList(L);*/
  cerr << endl
       << "--The list is currently " << listSize(L1) << " cells long" << endl;
  unsigned int index = 3;
  cerr << endl << "Testing getElement with index: " << index << endl;
  cerr << "--The element at pos: " << index << " is " << getElement(L1, index)
       << endl;
  cerr << endl << "Testing deleteElementAt with index: " << index << endl;
  deleteElementAt(L1, index);
  printList(L1);

  cerr << endl << "Reinserting element: ab" << endl;
  insertElement(L1, "ab");
  printList(L1);

  cerr << endl << "Testing deleteElementOnce with head element: 0" << endl;
  deleteElementOnce(L1, "0");
  printList(L1);

  cerr << endl << "Testing deleteElementOnce with tail element: z" << endl;
  deleteElementOnce(L1, "z");
  printList(L1);

  cerr << endl << "Testing deleteElementOnce with middle element: ab" << endl;
  deleteElementOnce(L1, "ab");
  printList(L1);

  cerr << endl << "Reinserting element: ab" << endl;
  insertElement(L1, "ab");
  printList(L1);

  string deleteVictim = "H";
  cerr << endl << "Inserting a bunch of identical elements at head" << endl;
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  printList(L1);
  cerr << endl
       << "Testing deleteAllElements with element: " << deleteVictim << endl;
  deleteAllElements(L1, deleteVictim);
  printList(L1);

  deleteVictim = "zzz";
  cerr << endl << "Inserting a bunch of identical elements at tail" << endl;
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  printList(L1);
  cerr << endl
       << "Testing deleteAllElements with element: " << deleteVictim << endl;
  deleteAllElements(L1, deleteVictim);
  printList(L1);

  deleteVictim = "bcd";
  cerr << endl
       << "Inserting a bunch of identical elements in the middle" << endl;
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  insertElement(L1, deleteVictim);
  printList(L1);
  cerr << endl
       << "Testing deleteAllElements with element: " << deleteVictim << endl;
  deleteAllElements(L1, deleteVictim);
  printList(L1);

  cerr << endl << endl << "Creating copy of list: ";
  ordList L2 = nullptr;
  insertElement(L2, "a");
  insertElement(L2, "ab");
  insertElement(L2, "b");
  insertElement(L2, "c");

  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  cerr << endl << "Testing listsAreEqual: " << endl;
  cerr << (listAreEqual(L1, L2) ? "--Sono uguali\n" : "--Sono diverse\n");
  cerr << "\nInserisco elemento extra diverso in L1";
  insertElement(L1, "d");
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  cerr << endl << "Testing listsAreEqual: " << endl;
  cerr << (listAreEqual(L1, L2) ? "--Sono uguali\n" : "--Sono diverse\n");
  cerr << endl << "Rimuovo elemento extra diverso in L1";
  deleteElementOnce(L1, "d");
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  cerr << "\nInserisco elemento extra multiplo (doppione) in L1";
  insertElement(L1, "b");
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  cerr << endl
       << (listAreEqual(L1, L2) ? "--Sono uguali\n" : "--Sono diverse\n");
  cerr << endl << "----" << endl;
  cerr << "\nNow testing concatList on:\n";
  insertElement(L1, "g");
  insertElement(L1, "0");
  insertElement(L2, "?");
  insertElement(L2, "y");
  ordList concatL = nullptr;
  concatL = concatLists(L1, L2);
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  cerr << endl;
  cerr << "concatList: ";
  printList(concatL);
  cerr << endl;

  while (concatL) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(concatL, 1);
  }
  delete concatL;

  cerr << endl << "----" << endl;
  cerr << "\nNow testing unionList with different lists\n";
  insertElement(L1, "k");
  insertElement(L2, "4");
  insertElement(L2, "h");
  insertElement(L2, "P");
  insertElement(L2, "P");
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  ordList unitedList = nullptr;
  unitedList = unionLists(L1, L2);
  cerr << endl;
  cerr << "unitedList: ";
  printList(unitedList);
  cerr << endl;
  while (unitedList) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(unitedList, 1);
  }
  delete unitedList;

  cerr << endl << "----" << endl;
  cerr << "\nNow testing intersectLists\n";
  cerr << "\nL1: ";
  printList(L1);
  cerr << "\nL2: ";
  printList(L2);
  ordList intersectedList = nullptr;
  intersectedList = intersectLists(L1, L2);
  cerr << endl;
  cerr << "intersectedList: ";
  printList(intersectedList);
  cerr << endl << endl;
  while (intersectedList) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(intersectedList, 1);
  }
  delete intersectedList;
  cerr << endl << "----" << endl;
  cerr << "Emptying lists L1 and L2";
  while (L1) {
    // cerr << endl << "--deleting element: " << L1->data << endl;
    // printList(L1);
    deleteElementAt(L1, 1);
  }
  while (L2) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(L2, 1);
  }

  cerr << endl
       << (isEmptyList(L1) ? "--List 1 is empty" : "--List 1 is not empty")
       << endl;

  cerr << (isEmptyList(L2) ? "--List 2 is empty" : "--List 2 is not empty")
       << endl;
  delete L1;
  delete L2;

  ordList L3 = nullptr;
  cerr << endl << "Error handling tests: " << endl;
  cerr << "----------------------------------------" << endl;
  cerr << "--FUNCTION: getElement" << endl;
  cerr << "----case empty list:" << endl;
  try {
    getElement(L3, 3);
  } catch (string &err) {
    cerr << err << endl << endl;
  }
  cerr << "----case invalid index:" << endl;
  insertElement(L3, "A");
  insertElement(L3, "B");
  cerr << "-----list: ";
  printList(L3);
  cerr << endl;
  try {
    cerr << "-----The third element is:" << getElement(L3, 3) << endl;
  } catch (string &err) {
    cerr << endl << err << endl;
  }
  cerr << "Emptying list again" << endl;
  while (L3) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(L3, 1);
  }

  cerr << (isEmptyList(L3) ? "--List 3 is empty" : "--List 3 is not empty")
       << endl;

  cerr << "----------------------------------------" << endl;
  cerr << "--FUNCTION: deleteElementAt" << endl;
  cerr << "----case empty list" << endl;
  try {

    deleteElementAt(L3, 1);
  } catch (string &err) {
    cerr << err << endl;
  }
  cerr << "----case invalid index:" << endl;
  insertElement(L3, "A");
  insertElement(L3, "B");
  cerr << "-----list: ";
  printList(L3);
  cerr << endl;
  try {
    cerr << "-----The third element is:" << getElement(L3, 3) << endl;
  } catch (string &err) {
    cerr << endl << err << endl;
  }

  cerr << endl << "Emptying list again" << endl;
  while (L3) {
    // cerr << endl << "--deleting element: " << L2->data << endl;
    // printList(L2);
    deleteElementAt(L3, 1);
  }

  cerr << (isEmptyList(L3) ? "--List 3 is empty" : "--List 3 is not empty")
       << endl;

  cerr << "----------------------------------------" << endl;
  cerr << "--FUNCTION: deleteElementOnce" << endl;
  cerr << "----case empty list" << endl;
  try {
    deleteElementOnce(L3, "A");
  } catch (string &err) {
    cerr << err << endl;
  }
  cerr << "----case element not in list:" << endl;
  insertElement(L3, "A");
  insertElement(L3, "B");
  cerr << "-----list: ";
  printList(L3);
  cerr << endl;
  try {
    deleteElementOnce(L3, "C");
  } catch (string &err) {
    cerr << err << endl;
  }

  cerr << endl << "Emptying list again" << endl;
  while (L3) {
    deleteElementAt(L3, 1);
  }
  cerr << (isEmptyList(L3) ? "--List 3 is empty" : "--List 3 is not empty")
       << endl;

  cerr << "----------------------------------------" << endl;
  cerr << "--FUNCTION: deleteAllElements" << endl;
  cerr << "----case empty list" << endl;
  try {
    deleteAllElements(L3, "A");
  } catch (string &err) {
    cerr << err << endl;
  }

  cerr << "Emptying list" << endl;
  while (L3) {
    deleteElementAt(L3, 1);
  }
  cerr << (isEmptyList(L3) ? "--List 3 is empty" : "--List 3 is not empty")
       << endl;

  delete L3;
}
