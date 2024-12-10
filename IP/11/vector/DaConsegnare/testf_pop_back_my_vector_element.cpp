#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare** */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}

std::string my_print(const my_vector& v) {
  string out = "Cap: ";
  out+=to_string(v.capacity)+" Size: ";
  out+=to_string(v.size)+"->[";
  for (unsigned int i = 0; i < v.size; i++) {
    if (i > 0) out = out + ",";
    out = out + std::to_string(v.store[i]);
  }
  out += "]";
  return out;
}

bool my_equal(const my_vector& v1,const my_vector& v2){
  if(v1.capacity!=v2.capacity || v1.size!=v2.size){
    return false;
  }
  for (unsigned int i = 0; i < v1.size; i++) {
    if(v1.store[i]!=v2.store[i]){
      return false;
    }
  }
  return true;
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
  
  
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n**** TEST  pop_back_my_vector_element(...)  *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 5 TEST DA SUPERARE !!!!";
  int nTest = 1;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    my_vector v={3,10,new double[10]};
    v.store[0]=2.0; v.store[1]=3.0; v.store[2]=4.0;
    my_vector vres={2,10,new double[10]};
    vres.store[0]=2.0; vres.store[1]=3.0;
    cout<<"\nCall pop_back_my_vector_element(v)";
    cout << "\n con v: " << my_print(v);
    double dreq=pop_back_my_vector_element(v);
    double dres=4.0;
    cout << "\nLa funzione cambia v in: "<<my_print(v);
    cout<< "\n e ritorna:"<<dreq;
    bool ans=my_equal(v,vres) && dreq==dres;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione doveva cambiare v in:"<<my_print(vres);
      cout<< "\ne ritornare:"<<dres;
    }
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    my_vector v={10,10,new double[10]};
    v.store[0]=2.0; v.store[1]=3.0; v.store[2]=4.0;
    v.store[3]=5.0; v.store[4]=6.0; v.store[5]=7.0;
    v.store[6]=8.0; v.store[7]=9.0; v.store[8]=10.0;
    v.store[9]=11.0;
    my_vector vres={9,10,new double[10]};
    vres.store[0]=2.0; vres.store[1]=3.0; vres.store[2]=4.0; vres.store[3]=3.0;
    vres.store[3]=5.0; vres.store[4]=6.0; vres.store[5]=7.0;
    vres.store[6]=8.0; vres.store[7]=9.0; vres.store[8]=10.0;
    cout<<"\nCall pop_back_my_vector_element(v)";
    cout << "\n con v: " << my_print(v);
    double dreq=pop_back_my_vector_element(v);
    double dres=11.0;
    cout << "\nLa funzione cambia v in: "<<my_print(v);
    cout<< "\n e ritorna:"<<dreq;
    bool ans=my_equal(v,vres) && dreq==dres;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione doveva cambiare v in:"<<my_print(vres);
      cout<< "\ne ritornare:"<<dres;
    }
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;
    
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    my_vector v={1,10,new double[10]};
    v.store[0]=2.0;
    my_vector vres={0,10,new double[10]};
    cout<<"\nCall pop_back_my_vector_element(v)";
    cout << "\n con v: " << my_print(v);
    double dreq=pop_back_my_vector_element(v);
    double dres=2.0;
    cout << "\nLa funzione cambia v in: "<<my_print(v);
    cout<< "\n e ritorna:"<<dreq;
    bool ans=my_equal(v,vres) && dreq==dres;
    if(ans) ++ret;
    else{
      cout << "\nLa funzione doveva cambiare v in:"<<my_print(vres);
      cout<< "\ne ritornare:"<<dres;
    }
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(ans)<<endl;    
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    my_vector v={0,2,new double[2]};
    cout<<"\nCall pop_back_my_vector_element(v)";
    cout << "\n con v: " << my_print(v);
    bool except=false;
    try{
      pop_back_my_vector_element(v);
    }catch(string& st){
      except=true;
    }
    cout << "\nLa funzione deve sollevare un eccezione ";
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(except)<<endl;
    if(except) ++ret;
  }
  nTest++;
  {
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest;
    cout << "\n-----------------------------------------";

    my_vector v={0,0,nullptr};
    cout<<"\nCall pop_back_my_vector_element(v)";
    cout << "\n con v: " << my_print(v);
    bool except=false;
    try{
      pop_back_my_vector_element(v);
    }catch(string& st){
      except=true;
    }
    cout << "\nLa funzione deve sollevare un eccezione ";
    cout << "\nIl test e' superato? ================================> "
         << siOrNo(except)<<endl;
    if(except) ++ret;
  }
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
    }
