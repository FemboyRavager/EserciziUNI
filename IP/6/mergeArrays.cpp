#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

  srand(time(NULL));
  const int N = 9, M = 10;
  int s1[N];
  int s2[M];
  int d[N + M];

  for (int i = 0; i < N; i++) {
    s1[i] = rand() % 256;
  }
  for (int i = 0; i < M; i++) {
    s2[i] = rand() % 256;
  }
  cout << "\nArray s1 (generato) = { ";
  for (int i = 0; i < N; i++) {
    cout << s1[i] << " ";
  }
  cout << "}\nArray s2 (generato) = { ";
  for (int i = 0; i < M; i++) {
    cout << s2[i] << " ";
  }
  cout<<"}";

  int greatestIndex = 0;

  for (int i = 0; i < N; i++) { // sort
    greatestIndex = i;
    for (int j = i + 1; j < N; j++) {
      if (s1[j] < s1[greatestIndex]) {
        greatestIndex = j;
      }
    }
    int temp = s1[i];
    s1[i] = s1[greatestIndex];
    s1[greatestIndex] = temp;
  }
  for (int i = 0; i < M; i++) { // sort
    greatestIndex = i;
    for (int j = i + 1; j < M; j++) {
      if (s2[j] < s2[greatestIndex]) {
        greatestIndex = j;
      }
    }
    int temp = s2[i];
    s2[i] = s2[greatestIndex];
    s2[greatestIndex] = temp;
  }
  cout << "\nArray s1 (ordinato) = { ";
  for (int i = 0; i < N; i++) {
    cout << s1[i] << " ";
  }
  cout << "}\nArray s2 (ordinato) = { ";
  for (int i = 0; i < M; i++) {
    cout << s2[i] << " ";
  }
  cout<<"}";
  int lowestS1pos = 0, lowestS2pos = 0;
  for (int i = 0; i < N + M; i++) {
    // cout << endl << "LowestS1Pos: " << lowestS1pos << "|LowestS2Pos: " << lowestS2pos << "|i:" << i;
    if (lowestS1pos == N) { // se s1 è oltre l'ultimo valore, riempi d con S2
      // cout << "\nS2pos reached max\n";
      for (int j = i; j < (N + M); j++, i++) {
        d[j] = s2[lowestS2pos];
        lowestS2pos++;
      }
      break;
    };
    if (lowestS2pos == M) { // se s2 è oltre l'ultimo valore, riempi d con S1
      // cout << "\nS2pos reached max\n";
      for (int j = i; j < (N + M); j++, i++) {
        // cout << j << "|";
        d[j] = s1[lowestS1pos];
        lowestS1pos++;
      }
      break;
    };
    if (s1[lowestS1pos] < s2[lowestS2pos]) {
      d[i] = s1[lowestS1pos];
      lowestS1pos++;
    } else if (s2[lowestS2pos] < s1[lowestS1pos]) {
      d[i] = s2[lowestS2pos];
      lowestS2pos++;
    } else { // se uguali, metto s1 in [i] e s2 in [i+1]
      d[i] = s1[lowestS1pos];
      lowestS1pos++;
      d[i + 1] = s2[lowestS2pos];
      lowestS2pos++;
      i++; // aumento i di un ulteriore 1 in quanto ho già riempito la cella
           // successiva
    }
  }
  cout << "\nArray d = { ";
  for (int i = 0; i < N + M; i++) {
    cout << d[i] << " ";
  }
  cout <<"}"<< endl;
}
