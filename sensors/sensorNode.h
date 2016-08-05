//====================================================================
// sensorType.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------

#ifndef CS307_PROG1_SENSORNODE_H
#define CS307_PROG1_SENSORNODE_H

struct sensorNode {
    char type[64];
    char material[64];
    int ID;
    char units[64];
    double minVal;
    double maxVal;
    double sensorData;
};

#endif //CS307_PROG1_SENSORNODE_H
