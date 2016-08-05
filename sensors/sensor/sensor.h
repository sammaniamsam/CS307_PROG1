//====================================================================
// sensor.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include <vector>
#include <time.h>
//---------------------------------

#ifndef SENSOR_H
#define SENSOR_H

//---------------------------------
struct sensorNode {
    char type[64];
    char material[64];
    int ID;
    char units[64];
    double minVal;
    double maxVal;
    double sensorData;
};
//---------------------------------

class sensor {

private:
    std::vector<sensorNode*> *vPtr; //vector ptr to vector of sensorNode ptrs

    void generateSensorData(unsigned long& vSize);

public:
    sensor();
    ~sensor();
    void getSensor(sensorNode* snPtr);
    void updateSensors();
    std::vector<sensorNode*>* relaySensorData();
};

#endif