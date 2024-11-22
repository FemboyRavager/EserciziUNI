#include <iostream>

using namespace std;

struct err {
  string functionName;
  string variableName;
  int variableValue;
};

int populationSim(int initPop, int birthRatePercent, int immigrantRate) {
  int popNextYear = 0;
  if (initPop < 0) {
    err error;
    error.functionName = "populationSim";
    error.variableName = "initPop";
    error.variableValue = initPop;
    throw error;
  }
  if (birthRatePercent < -100 || birthRatePercent > 100) {
    err error;
    error.functionName = "populationSim";
    error.variableName = "birthRatePercent";
    error.variableValue = birthRatePercent;
    throw error;
  }
  int birthRateNet = (initPop * birthRatePercent) / 100;
  popNextYear = initPop + birthRateNet + immigrantRate;

  return popNextYear;
}
struct popData {
  int initPop;
  int birthRate;
  int immigrantRate;
};
int main() {
  const int N=5;
  popData inputData[N];
  inputData[0].initPop = -50;
  inputData[0].birthRate = 10;
  inputData[0].immigrantRate = 6;

  inputData[1].initPop = 300;
  inputData[1].birthRate = 315;
  inputData[1].immigrantRate = 6;

  inputData[2].initPop = 300;
  inputData[2].birthRate = 10;
  inputData[2].immigrantRate = 6;

  inputData[3].initPop = 300;
  inputData[3].birthRate = -10;
  inputData[3].immigrantRate = 6;

  inputData[4].initPop = 300;
  inputData[4].birthRate = 10;
  inputData[4].immigrantRate = -26;

  for (int i = 0; i < N; i++) {
    try {
      cout << "Current population: " << inputData[i].initPop << endl;
      cout << "Birth rate: " << inputData[i].birthRate << "%, equal to "
           << (inputData[i].initPop * inputData[i].birthRate) / 100 << " net" << endl;
      cout << "Immigrant rate: " << inputData[i].immigrantRate << endl;
      cout << populationSim(inputData[i].initPop, inputData[i].birthRate,
                            inputData[i].immigrantRate)
           << endl;
    } catch (err &error) {
      cout << "Errore in funzione '" << error.functionName << "', variable '"
           << error.variableName << "' with invalid value "
           << error.variableValue << endl;
    }
    cout<<"------------------------------------------------------------"<<endl;
  }
}
