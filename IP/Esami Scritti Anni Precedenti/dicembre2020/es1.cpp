#include <iostream>
#include <vector>
using namespace std;

bool areMultiple(vector<int> v) {
  for (unsigned int i = 0; i < (v.size() - 1); i++) {
    if (v[i + 1] % v[i] != 0)
      return false;
  }
  return true;
}

int main() {
  vector<int> v = {1, 2, 4, 8, 15};
  cout << (areMultiple(v) ? "Multipli" : "Non multipli") << endl;
}
