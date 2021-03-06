//====================================================================
// display.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include <iomanip>
#include <vector>
//---------------------------------
#include "../sensor/sensor.h"
//---------------------------------

#ifndef DISPLAY_H
#define DISPLAY_H

//---------------------------------
struct displayNode {
    char type[64];
    int IDs[7];
    int IDCount;
    std::vector<sensorNode*> vSensorNodePtrs;
};
//---------------------------------

class display {

private:
    std::vector<displayNode*> *vPtr; //ptr to vector of displayNode ptrs
public:
    display();
    ~display();
    void getDisplay(displayNode* dnPtr);
    void displayData();
    std::vector<displayNode*>* relayDisplayData();
};

#endif