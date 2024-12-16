#include <iostream>
#include <list>
using namespace std;

string concat(list<string> l) {
  // cerr << "Current l: " << l.front() << endl;
  if (l.size() == 0) {
    // cout << "End reached";
    return "";
  }
  string result = l.front();
  l.pop_front();
  return result + concat(l);
}

int listLength(list<string> l) {
  // return l.size();
  if (l.size() == 0) {
    return 0;
  }
  l.pop_front();
  return 1 + listLength(l);
}

int main() {
  list<string> l1 = {"Hello", " ", "World", "!"};
  string result = concat(l1);
  cout << endl << "Final result: " << result << endl;
  cout << "List length: " << listLength(l1) << endl;
}
