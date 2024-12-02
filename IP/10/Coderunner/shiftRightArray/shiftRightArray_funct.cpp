#include "shiftRightArray_funct.h"
void shiftRightArray(int *t, int size) {
  int temp = *(t + size - 1);
  for (int i = size; i > 0; i--) {
    *(t + i - 1) = *(t + i - 2);
  }
  *t = temp;
}
