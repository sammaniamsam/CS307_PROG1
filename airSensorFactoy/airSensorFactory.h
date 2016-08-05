//====================================================================
// sensorType.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include "../abstractSensorFactory/abstractSensorFactory.h"
#include "../sensorType/sensorType.h"
//---------------------------------

#ifndef CS307_PROG1_AIRSENSORFACTORY_H
#define CS307_PROG1_AIRSENSORFACTORY_H


class airSensorFactory: public abstractSensorFactory {

    private:
        int instanceNumber = 0; //number of instances created
        airSensorFactory();

    public:
        ~airSensorFactory();
        int getInstanceNumber();
        static airSensorFactory* getInstance();
        sensorType* createSensorInstance();
};


#endif //CS307_PROG1_AIRSENSORFACTORY_H
