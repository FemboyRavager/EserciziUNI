#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

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

unsigned int partition(vector<int> &data, unsigned int start, unsigned int end, unsigned int pivot) {
  // cerr << "Partition called on start:"<<start<<"|end:"<<end<<"\n\t";
  // for(unsigned int  i=start;i<=end;i++) {
  //    cerr << "["<<data[i]<<"] ";
  // }
  // cerr << endl;
  unsigned int i = start + 1;
  for (unsigned int j = start + 1; j <= end; j++) {
    // cerr << "\tj: "<<j<<"|i: "<<i<<endl;
    if (data[j] < data[pivot]) {
      swap_ind(data, (int)i, (int)j);
      i++;
    }
  }
  // cerr << "\nPlacing pivot "<< data[pivot] << "in pos " << i-1 << "(switching with " <<data[i-1] << ")\n";
  swap_ind(data, pivot, i - 1);
  // cerr << "Partition result: \n\t";
  // for(unsigned int  i=0;i<=end;i++) {
  //    cerr << "["<<data[i]<<"] ";
  // }
  // cerr <<"\tand returning "<< i-1 <<" as pivot pos."<< endl;
  // cerr << endl;
  return i - 1;
}

void quickSortTrivialRec(vector<int> &v, unsigned int start, unsigned int end) {
  // cerr << "Current recursion called on start:"<<start<<"|end:"<<end<<"-> pivot pos: "<<start<<endl;
  if (end - start < 1 || end < start) {
    return;
  }
  // for(unsigned int  i=start;i<=end;i++) {
  //    cerr << "["<<v[i]<<"] ";
  // }
  // cerr << "\n";
  unsigned int pivot = start;
  unsigned int pivotFinalPos = partition(v, start, end, pivot);
  // cerr <<endl<<"==FIRST HALF with pivot: "<<pivotFinalPos<<"\n";
  if (pivotFinalPos != 0)
    quickSortTrivialRec(v, start, pivotFinalPos - 1);
  // cerr <<endl<<"==SECOND HALF with pivot: "<<pivotFinalPos<<"\n";
  quickSortTrivialRec(v, pivotFinalPos + 1, end);
  // cerr << "Current vector:\n";
  // for(unsigned int  i=0;i<=end;i++) {
  //    cerr << "["<<v[i]<<"] ";
  // }
  // cerr << endl;
}

void quickSortRandomRec(vector<int> &v, unsigned int start, unsigned int end) {
  if (end - start < 1 || end < start) {
    return;
  }
  // for(unsigned int  i=start;i<=end;i++) {
  //    cerr << "["<<v[i]<<"] ";
  // }
  // cerr << "\n";
  unsigned int pivot = (rand() % (end - start)) + start;
  // cerr << "\nCurrent call start: "<<start<<"| end: "<<end<<"| pivot: "<<pivot<<endl;
  swap_ind(v, start, pivot); // sposto pivot nella prima cella
  unsigned int pivotFinalPos = partition(v, start, end, pivot);
  // cerr <<endl<<"==FIRST HALF with pivot: "<<pivotFinalPos<<"\n";
  if (pivotFinalPos != 0)
    quickSortRandomRec(v, start, pivotFinalPos - 1);
  // cerr <<endl<<"==SECOND HALF with pivot: "<<pivotFinalPos<<"\n";
  quickSortRandomRec(v, pivotFinalPos + 1, end);
  // cerr << "Current vector:\n";
  // for(unsigned int  i=0;i<=end;i++) {
  //    cerr << "["<<v[i]<<"] ";
  // }
  // cerr << endl;
}
/*quicksort con scelta banale del pivot*/
void quickSortTrivial(vector<int> &v) {
  /* Implementare quickSort banale con partizione in place */
  if (v.size() <= 1) {
    return;
  }
  quickSortTrivialRec(v, 0, v.size() - 1);
}

/*quicksort randomizzato*/
void quickSortRandom(vector<int> &v) {
  /* Implementare quickSort randomizzato con partizione in place */

  if (v.size() <= 1) {
    return;
  }
  quickSortRandomRec(v, 0, v.size() - 1);
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
