#include <iostream>
#include <string>
#include "string_ord_list.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare** */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}

string my_print(const ordList& l) {
  if(l==nullptr){
    return "NULL";
  }
  return l->data+"->"+my_print(l->next);
}

bool my_equal(const ordList& l1,const ordList& l2){
  if(l1==nullptr && l2==nullptr){
    return true;
  }
  if((l1==nullptr || l2==nullptr) && l1!=l2){
    return false;
  }
  if(l1->data!=l2->data){
    return false;
  }
  return my_equal(l1->next,l2->next);     
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n**** TEST          listSize(...)            *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 6 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l=nullptr;
    unsigned ires=0;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
              << siOrNo(ans)<<endl;
    
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l=new cell{"BAG",nullptr};
    unsigned ires=1;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
              << siOrNo(ans)<<endl;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l2=new cell{"BAG",nullptr};
    ordList l=new cell{"APPLE",l2};
    unsigned ires=2;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
              << siOrNo(ans)<<endl;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l3=new cell{"MILK",nullptr};
    ordList l2=new cell{"BAG",l3};
    ordList l=new cell{"APPLE",l2};
    unsigned ires=3;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
              << siOrNo(ans)<<endl;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l4=new cell{"MILK",nullptr};
    ordList l3=new cell{"FISH",l4};
    ordList l2=new cell{"BAG",l3};
    ordList l=new cell{"APPLE",l2};
    unsigned ires=4;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
              << siOrNo(ans)<<endl;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    ordList l5=new cell{"MILK",nullptr};
    ordList l4=new cell{"FISH",l5};
    ordList l3=new cell{"FISH",l4};
    ordList l2=new cell{"BAG",l3};
    ordList l=new cell{"APPLE",l2};
    unsigned ires=5;
    cout<<"\nCall listSize(l)";
    cout << "\n con l: " << my_print(l);
    unsigned ireq=listSize(l);
    cout << "\nLa funzione ritorna: "<<ireq;
    bool ans=ires==ireq;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione dovevare ritornare:"<<ires;
    }
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
  }
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
