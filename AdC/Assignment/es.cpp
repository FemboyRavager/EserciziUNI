#include <iostream>
#define l 8
int *H = (int *)malloc(l * l * sizeof(int)); // allocatelo direttamente in .data
int f1() {
  int i, j, k, t, u, m = 2;
  for (i = 0; i < l; i++)
    for (j = 0; j < l; j++) {
      if (i == 0 && j == 0) {
        H[i * l + j] = 10;
        //std::cout << "H[" << i * l + j << "]=" << H[i * l + j] << std::endl;
      } else
        for (k = 0; k <= 5; k++) {
          t = 1 << k;
          //std::cout << "==1"<<" bit-shifted to "<<t<<std::endl;
          if (i >= t && j < t) {
            H[i * l + j] = H[(i - t) * l + j];
            std::cout << "H[" << i * l + j << "]=" << H[(i - t) * l + j]
                      << "  \t\t" << "i="<<i << "|j="<<j<<"|t="<<t<< std::endl;
          }
        }
    }
  u = 0;
  for (k = 0; k < 16; ++k)
    u += H[k];
  for (int index = 0; index < 64; index++) { // aggiunto da me
    // std::cout << H[index] << (index < 63 ? "," : "\n");
    std::cout << "-H[" << index << "]=" << H[index] << std::endl;
  }
  
  for (int index = 1; index <= 64; index++) { // aggiunto da me
    // std::cout << H[index] << (index < 63 ? "," : "\n");
    std::cout <<  H[index-1] << ",";
    if(index%8==0)
      std::cout<<std::endl;
  }
  return k;
}

int main() {
  int s;
  s = f1();
  std::cout << std::endl << s<<std::endl; // equivale alla print_int
  exit(0);
}
