#include <cmath>
#include <iostream>
using namespace std;
// daysLeft assume che la percentuale di evap viene applicata all'attuale volume
double daysLeft(float startingLiters, int evapPercent, float floorLiters) {
  double days = 0, currentLiters = startingLiters, nextLiters = 0;
  //cout << "\nEvaporation %: " << evapPercent;
  //cout << "\nStarting with " << startingLiters;
  nextLiters = currentLiters * ((float)1 - ((float)evapPercent / 100));
  //cout << "\nLiters next day: " << nextLiters;
  while (nextLiters > floorLiters) {
    currentLiters = nextLiters;
    nextLiters = currentLiters * ((float)1 - ((float)evapPercent / 100));
    days++;
    //cout << "\n\tEnd of day: " << days;
    //cout << "\n\tCurrent liters: " << currentLiters;
    //cout << "\n\tLiters next day: " << nextLiters;
    //cout << endl;
  }

  return days;
}
// daysLeftAlt assume che la % è applicata al valore iniziale
double daysLeftAlt(float startingLiters, int evapPercent, float floorLiters) {
  double days = 0, currentLiters = startingLiters, nextLiters = 0,
         evapPerDay = 0;
  evapPerDay = startingLiters * ((float)evapPercent / 100);
  //cout << "\nEvaporation %: " << evapPercent<<" equal to "<<evapPerDay<<" liters";
  //cout << "\nStarting with " << startingLiters;
  nextLiters = currentLiters * ((float)1 - ((float)evapPercent / 100));
  //cout << "\nLiters next day: " << nextLiters;
  while (nextLiters > floorLiters) {
    currentLiters = nextLiters;
    nextLiters = currentLiters - evapPerDay;
    days++;
    //cout << "\n\tEnd of day: " << days;
    //cout << "\n\tCurrent liters: " << currentLiters;
    //cout << "\n\tLiters next day: " << nextLiters;
    //cout << endl;
  }

  return days;
}

int main() {
  const float startingLiters = 100, floorLiters = 10;
  const int evaporationPercentage = 1;
  double days = daysLeft(startingLiters, evaporationPercentage, floorLiters);
  cout << "L'evaporatore puo' operare per " << days << " giorni assumendo che la percentuale di evaporazione e' applicata al volume giornaliero\n";
  days = daysLeftAlt(startingLiters, evaporationPercentage, floorLiters);
  cout << "L'evaporatore puo' operare per " << days << " giorni assumendo che la percentuale di evaporazione e' applicata al volume iniziale\n";
}
