#include <iostream>

using namespace std;

struct err {
  string functionName;
  string variableName;
  int variableValue;
};

int populationSim(int initPop, int birthRatePercent, int immigrantRate,
                  int years) {
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
  if (years < 1) {
    err error;
    error.functionName = "populationSim";
    error.variableName = "years";
    error.variableValue = years;
    throw error;
  }

  int currentYearPop = initPop, birthRateNet = 0;
  for (int i = 0; i < years; i++) {
    birthRateNet = (currentYearPop * birthRatePercent) / 100;
    popNextYear = currentYearPop + birthRateNet + immigrantRate;
    currentYearPop = popNextYear;
  }

  return popNextYear;
}
struct popData {
  int initPop;
  int birthRate;
  int immigrantRate;
  int years;
};
int main() {
  const int N = 5;
  popData inputData[N];
  inputData[0].initPop = -50;       //caso non valido
  inputData[0].birthRate = 10;
  inputData[0].immigrantRate = 6;
  inputData[0].years = 3;

  inputData[1].initPop = 300;
  inputData[1].birthRate = 315;     //caso non valido
  inputData[1].immigrantRate = 6;
  inputData[1].years = 3;

  inputData[2].initPop = 300;
  inputData[2].birthRate = 10;
  inputData[2].immigrantRate = 6;
  inputData[2].years = -2;          //caso non valido

  inputData[3].initPop = 300;
  inputData[3].birthRate = -10;     //caso birth rate negativo
  inputData[3].immigrantRate = 6;
  inputData[3].years = 2;

  inputData[4].initPop = 300;
  inputData[4].birthRate = 10;
  inputData[4].immigrantRate = -26; //caso immigrant rate negativo
  inputData[4].years = 4;

      for (int i = 0; i < N; i++) {
    try {
      cout << "Current population: " << inputData[i].initPop << endl;
      cout << "Birth rate: " << inputData[i].birthRate << "%, equal to "
           << (inputData[i].initPop * inputData[i].birthRate) / 100 << " net"
           << endl;
      cout << "Immigrant rate: " << inputData[i].immigrantRate << endl;
      cout << "Years: " << inputData[i].years << endl;
      cout << populationSim(inputData[i].initPop, inputData[i].birthRate,
                            inputData[i].immigrantRate, inputData[i].years)
           << endl;
    } catch (err &error) {
      cout << "Errore in funzione '" << error.functionName << "', variable '"
           << error.variableName << "' with invalid value "
           << error.variableValue << endl;
    }
    cout << "------------------------------------------------------------"
         << endl;
  }
}
