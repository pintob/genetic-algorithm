#include "SortedArray.h"
#include "../include/Evolution.h"
#include "../include/Population.h"

#include <iostream>

using namespace genAlgo;

int main() {
    auto array = SortedArray(12);
    Evolution evo = {64,25,4};
    Population pop = Population<SortedArray>(array, evo, TypeOfProblem::Maximisation);

   for(int i = 0; i < 10; i++){
       ++pop;
   }

   std::cout << *pop[0].first << '\n';
   pop+=100;
   std::cout << *pop[0].first << '\n';

   return 0;
}