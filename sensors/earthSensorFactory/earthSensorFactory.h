//====================================================================
// earthSensorFactory.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------
#include "../abstractSensorFactory/abstractSensorFactory.h"
#include "../sensorType/sensorType.h"
#include "../earthSensor/earthSensor.h"
//---------------------------------

#ifndef CS307_PROG1_EARTHSENSORFACTORY_H
#define CS307_PROG1_EARTHSENSORFACTORY_H


class earthSensorFactory: public abstractSensorFactory {

private:
    int instanceNumber = 0; //number of instances created
    earthSensorFactory();

public:
    ~earthSensorFactory();
    int getInstanceNumber();
    static earthSensorFactory* getInstance();
    sensorType* createSensorInstance();     /* virtual */
};


#endif //CS307_PROG1_EARTHSENSORFACTORY_H
