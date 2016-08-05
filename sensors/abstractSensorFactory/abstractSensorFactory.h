//====================================================================
// abstractSensorFactory.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------
#include "../sensorType/sensorType.h"
//---------------------------------

#ifndef CS307_PROG1_ABSTRACTSENSORFACTORY_H
#define CS307_PROG1_ABSTRACTSENSORFACTORY_H


class abstractSensorFactory {

    public:
        abstractSensorFactory();
        ~abstractSensorFactory();
        virtual sensorType* createSensorInstance();
};

#endif //CS307_PROG1_ABSTRACTSENSORFACTORY_H
