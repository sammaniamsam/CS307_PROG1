//====================================================================
// simulation.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
#include <unistd.h>
//---------------------------------
#include "../sensor/sensor.h"
#include "../simpleDisplayFactory/simpleDisplayFactory.h"
#include "../sensor_mount/sensorMount.h"
#include "../data_parser/EnviroSimDataParser.h"
//---------------------------------

#ifndef SIMULATION_H
#define SIMULATION_H

class simulation {

private:
    sensor* sensorPtr;  //ptr to sensor class
    sensorMount* sensorMountPtr;    //ptr to sensor mount class
    EnviroSimDataParser* dataParserPtr; //ptr to data parser class

    void createDisplays(int& count);
    void createSensors(int& count);
    void getFile();
    void buildDevices();
    void attachDevices();
    void simulationDescription();

public:
    simulation();
    ~simulation();
    void runSimulation();

};

#endif
