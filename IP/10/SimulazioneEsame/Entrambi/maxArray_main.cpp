#include <iostream>
#include <string>
#include "maxArray_funct.h"

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
  cout << "\n****   TEST  maxArray(...)              *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 12 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[1]={10};
    int s=1;
    int ires =  maxArray(a,s);
    int ireq =10;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[2]={2,10};
    int s=2;
    int ires =  maxArray(a,s);
    int ireq =10;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[2]={10,2};
    int s=2;
    int ires =  maxArray(a,s);
    int ireq =10;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={10,1,20};
    int s=3;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={20,20,20};
    int s=3;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[3]={0,20,-20};
    int s=3;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15,17,18,19,20};
    int s=20;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={20,2,3,4,5,20,7,8,9,10,11,12,13,14,15,15,17,18,19,1};
    int s=20;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,2,3,4,5,20,7,8,9,10,11,12,13,14,15,15,17,18,19,20};
    int s=20;
    int ires =  maxArray(a,s);
    int ireq =20;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1};
    int s=20;
    int ires =  maxArray(a,s);
    int ireq =2;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    int a[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int s=20;
    int ires =  maxArray(a,s);
    int ireq =1;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve ritornare "<<ireq;
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    //int a[]={};
	int* a = nullptr; // Puntatore nullo per rappresentare l'assenza di elementi.
    int s=0;
    bool raisedexc=false;
    try{
      int ires =  maxArray(a,s);
    }catch(string& exc){
      raisedexc=true;
    }
    int ireq =0;
    cout << "\nL'array dato e': " << printArray(a, s);
    cout << "\nLa funzione deve sollevare un eccezione ";
       cout << "\nIl test e' superato? ================================> "
         << siOrNo(raisedexc)<<endl;
    if(raisedexc) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
