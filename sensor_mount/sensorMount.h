//====================================================================
// sensorMount.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include <iomanip>
#include <vector>
//---------------------------------
#include "../displays/display/display.h"
#include "../sensors/sensorType/sensorType.h"
//---------------------------------

#ifndef SENSORMOUNT_H
#define SENSORMOUNT_H

class sensorMount {

    private:
        std::vector<display*> *vDisplayPtr;     //ptr to vector of display class ptrs
        std::vector<sensorType*> *vSensorPtr;   //ptr to vector of sensor class ptrs

        void displayConnectedDisplays(unsigned long& numDisplays);
        void displayConnectedSensors(unsigned long& numSensors);

    public:
        sensorMount();
        ~sensorMount();
        void attachSensor(sensorType* sensorPtr);
        void attachDisplay(display* displayPtr);
        void displayConnectedDevices();
        bool linkSensorsToDisplays();
};

#endif