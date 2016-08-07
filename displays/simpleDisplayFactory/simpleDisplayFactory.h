//====================================================================
// simpleDisplayFactory.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#ifndef CS307_PROG1_SIMPLEDISPLAYFACTORY_H
#define CS307_PROG1_SIMPLEDISPLAYFACTORY_H
//---------------------------------
#include <iostream>
//---------------------------------
#include "../display/display.h"
//---------------------------------

class simpleDisplayFactory {

    private:
        int instanceNumber = 0; //number of instances created
        simpleDisplayFactory();

    public:
        ~simpleDisplayFactory();
        int getInstanceNumber();
        static simpleDisplayFactory *getInstance();
        display *createDisplayInstance();


};

#endif //CS307_PROG1_SIMPLEDISPLAYFACTORY_H
