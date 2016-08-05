//====================================================================
// sensorType.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include "../sensorNode.h"
//---------------------------------

#ifndef CS307_PROG1_SENSORTYPE_H
#define CS307_PROG1_SENSORTYPE_H

class sensorType {

public:
    sensorType();
    ~sensorType();
    virtual void setSensor(sensorNode* snPtr);
    virtual sensorNode* relaySensorData();
    virtual void updateSensor();
};

#endif //CS307_PROG1_SENSORTYPE_H
