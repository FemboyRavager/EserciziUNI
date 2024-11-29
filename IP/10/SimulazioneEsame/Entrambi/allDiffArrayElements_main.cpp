#include <iostream>
#include <string>
#include "allDiffArrayElements_funct.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}
////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */

std::string printArray(int* arrayInteri, unsigned int size) {
	std::string out = "[";
	for (unsigned int i = 0; i < size; i++) {
	if (i > 0) out = out + ",";
	out = out + std::to_string(arrayInteri[i]);
  }
  out += "]";
  return out;
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n**** TEST  allDiffArrayElements(...)    *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 12 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[0]={};
    int s=0;
    bool bres = allDiffArrayElements(a,s);
    bool breq = true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[1]={2};
    int s=1;
    bool bres = allDiffArrayElements(a,s);
    bool breq = true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[2]={2,1};
    int s=2;
    bool bres = allDiffArrayElements(a,s);
    bool breq = true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[2]={2,2};
    int s=2;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={1,3,2};
    int s=3;
    bool bres = allDiffArrayElements(a,s);
    bool breq = true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={1,1,2};
    int s=3;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={1,2,1};
    int s=3;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={2,1,1};
    int s=3;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={1,1,1};
    int s=3;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,18,17,16};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = true;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,18,17,1};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,10,9,8,7,6,11,11,13,14,15,20,19,18,17,16};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,18,16,16};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,1,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,18,17,16};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,3,17,16};
    int s=20;
    bool bres = allDiffArrayElements(a,s);
    bool breq = false;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<breq;
    cout << "\nLa funzione ritorna "<<bres;
    bool ans=(bres==breq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }

  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
