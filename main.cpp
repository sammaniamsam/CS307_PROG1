//---------------------------------
#include <iostream>
//---------------------------------
#include "simulation/simulation.h"
//---------------------------------

int main() {
    /*- - - - - - - - - - - - -*/
    //seed random number generator
    /*- - - - - - - - - - - - -*/
    srand((unsigned int) (time(NULL)));
    /*- - - - - - - - - - - - -*/
    simulation *simulationPtr = new simulation;
    simulationPtr->runSimulation();
}