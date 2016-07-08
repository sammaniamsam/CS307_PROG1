#include <iostream>
#include "simulation/simulation.h"
using namespace std;

int main() {
    simulation *simulationPtr = new simulation;
    simulationPtr->runSimulation();
}