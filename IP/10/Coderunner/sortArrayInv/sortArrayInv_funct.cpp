#include "sortArrayInv_funct.h"
void sortArrayInv(int *t, int size) {
  int maxIndex = 0;
  int temp=0;
  for (int i = 0; i < size; i++) {
    maxIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (*(t + j) > *(t + maxIndex)) {
        maxIndex=j;
      }
    }
    temp=*(t+i);
    *(t+i)=*(t+maxIndex);
    *(t+maxIndex)=temp;
  }
}
