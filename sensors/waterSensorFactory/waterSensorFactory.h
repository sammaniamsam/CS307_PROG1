//====================================================================
// waterSensorFactory.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------
#include "../abstractSensorFactory/abstractSensorFactory.h"
#include "../sensorType/sensorType.h"
#include "../waterSensor/waterSensor.h"
//---------------------------------

#ifndef CS307_PROG1_WATERSENSORFACTORY_H
#define CS307_PROG1_WATERSENSORFACTORY_H


class waterSensorFactory: public abstractSensorFactory {

    private:
        int instanceNumber = 0; //number of instances created
        waterSensorFactory();

    public:
        ~waterSensorFactory();
        int getInstanceNumber();
        static waterSensorFactory* getInstance();
        sensorType* createSensorInstance();     /* virtual */
};


#endif //CS307_PROG1_WATERSENSORFACTORY_H
