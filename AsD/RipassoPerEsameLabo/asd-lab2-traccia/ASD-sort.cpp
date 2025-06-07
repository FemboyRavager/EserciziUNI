#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ASD-sort.h"

using namespace std;

/**************************************************/
/*       funzioni ausiliare                      */
/**************************************************/

/*scambia le posizione i e j in v assumendo che siano posizione correte*/
void swap_ind(vector<int> &v, int i, int j) {
  int tmp = v.at(j);
  v.at(j) = v.at(i);
  v.at(i) = tmp;
}

/**************************************************/
/*       funzioni da implementare                 */
/**************************************************/

int partition(vector<int> &v, int start, int end) {
  int pivot = start;
  int i = start + 1;
  for (int j = i; j <= end; j++) {
    if (v.at(j) < v.at(pivot)) {
      swap_ind(v, j, i);
      i++;
    }
  }
  swap_ind(v, pivot, i - 1);
  return (i - 1);
}

void quickSortAux(vector<int> &v, int start, int end) {
  if (end - start < 1 || end < start) {
    return;
  }
  int pivot = partition(v, start, end);
  if (pivot != start) {
    quickSortAux(v, start, pivot - 1);
  }
  quickSortAux(v, pivot + 1, end);
}

/*quicksort con scelta banale del pivot*/
void quickSortTrivial(vector<int> &v) {
  /* Implementare quickSort banale con partizione in place */
  if (v.size() <= 1) {
    return;
  }
  quickSortAux(v, 0, v.size() - 1);
}

int partitionRand(vector<int> &v, int start, int end) {

  int pivot = start + (rand() % (end - start));

  if (pivot != start) {
    swap_ind(v, pivot, start);
    pivot = start;
  }

  int i = start + 1;
  for (int j = i; j <= end; j++) {
    if (v.at(j) < v.at(pivot)) {
      swap_ind(v, j, i);
      i++;
    }
  }

  swap_ind(v, pivot, i - 1);

  return (i - 1);
}

void quickSortRandAux(vector<int> &v, int start, int end) {
  if (end - start < 1 || end < start) {
    return;
  }
  int pivot = partitionRand(v, start, end);
  if (pivot != start) {
    quickSortRandAux(v, start, pivot - 1);
  }
  quickSortRandAux(v, pivot + 1, end);
}

/*quicksort randomizzato*/
void quickSortRandom(vector<int> &v) {
  /* Implementare quickSort randomizzato con partizione in place */
  quickSortRandAux(v, 0, v.size() - 1);
}
/**************************************************/
/*      funzioni implementate                     */
/**************************************************/

/* selection sort in place*/
void selectionSort(vector<int> &v) {
  unsigned int current_min_index;
  unsigned int size = v.size();
  for (unsigned int i = 0; i < size; ++i) {
    current_min_index = i;
    for (unsigned int j = i + 1; j < size; ++j) {
      if (v.at(current_min_index) > v.at(j)) {
        current_min_index = j;
      }
    }
    swap_ind(v, i, current_min_index);
  }
}

/* insertion sort in place*/
void insertionSort(vector<int> &v) {
  unsigned int current, prev;
  unsigned int size = v.size();
  for (unsigned int i = 1; i < size; ++i) {
    current = i;
    prev = i - 1;
    while (v.at(current) < v.at(prev)) {
      swap_ind(v, current, prev);
      --current;
      if (prev > 0) {
        --prev;
      } else {
        break;
      }
    }
  }
}

/* bubble sort in place*/
void bubbleSort(vector<int> &v) {
  unsigned int size = v.size();
  bool swapped = false;
  do {
    swapped = false;
    for (unsigned int i = 1; i < size; ++i) {
      if (v.at(i - 1) > v.at(i)) {
        swap_ind(v, i - 1, i);
        swapped = true;
      }
    }
  } while (swapped);
}

/*merge sort in place*/
void merge(vector<int> &v, unsigned int beg, unsigned int cent, unsigned int end) {
  unsigned int p1 = beg;
  unsigned int p2 = cent;
  vector<int> mv;
  while (p1 < cent && p2 < end) {
    if (v.at(p1) <= v.at(p2)) {
      mv.push_back(v.at(p1));
      ++p1;
    } else {
      mv.push_back(v.at(p2));
      ++p2;
    }
  }
  while (p1 < cent) {
    mv.push_back(v.at(p1));
    ++p1;
  }
  while (p2 < end) {
    mv.push_back(v.at(p2));
    ++p2;
  }
  for (unsigned int i = 0; i < mv.size(); ++i) {
    v.at(beg + i) = mv.at(i);
  }
}

void mergeSort(vector<int> &v) {
  unsigned int s = v.size();
  for (unsigned int width = 1; width < s; width = 2 * width) {
    for (unsigned int i = 0; i < s; i = i + 2 * width) {
      if (i + width < s) {
        unsigned int end = (i + 2 * width <= s) ? (i + 2 * width) : s;
        merge(v, i, i + width, end);
      }
    }
  }
}
