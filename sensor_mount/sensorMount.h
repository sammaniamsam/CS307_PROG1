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
#include "../display/display.h"
#include "../sensor/sensor.h"
//---------------------------------

#ifndef SENSORMOUNT_H
#define SENSORMOUNT_H

class sensorMount {

private:
    std::vector<display*> *vDisplayPtr; //ptr to vector of display ptrs
    std::vector<sensorNode*> *vSensorPtr;   //ptr to vector of sensorNode ptrs

    void displayConnectedDisplays(unsigned long& numDisplays);
    void displayConnectedSensors(unsigned long& numSensors);

public:
    sensorMount();
    ~sensorMount();
    void attachSensors(std::vector<sensorNode*>* vSensors);
    void attachDisplay(display* displayPtr);
    void displayConnectedDevices();
    bool linkSensorsToDisplays();
};

#endif