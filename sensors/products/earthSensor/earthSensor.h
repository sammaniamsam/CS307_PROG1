//====================================================================
// earthSensor.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------
#include "../../sensorNode.h"
#include "../../sensorType/sensorType.h"
//---------------------------------

#ifndef CS307_PROG1_EARTHSENSOR_H
#define CS307_PROG1_EARTHSENSOR_H


class earthSensor: public sensorType{

private:
    sensorNode* sensorNodePtr; //points to struct w/ sensor data

public:
    earthSensor();
    ~earthSensor();
    void setSensor(sensorNode* snPtr);  /* virtual */
    void updateSensor();                /* virtual */
    sensorNode* relaySensorData();      /* virtual */
};

#endif //CS307_PROG1_EARTHSENSOR_H
