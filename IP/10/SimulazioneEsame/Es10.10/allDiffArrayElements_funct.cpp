bool allDiffArrayElements(int *t, int size) {
  // DA MODIFICARE
  int *tJ = t;
  int *tI = t;
  for (int i = 0; i < size; i++) {
    tJ = t;
    for (int j = 0; j < size; j++) {
      // cout<<"Comparing "<<*tI<<" and "<<*tJ<<"| i: "<<i<<" and j: "<<j<<endl;
      if (i != j && *tJ == *tI) {
        return false;
      }
      tJ++;
    }
    tI++;
  }
  return true;
}
