//====================================================================
// simulation.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#ifndef SIMULATION_H
#define SIMULATION_H
//---------------------------------
#include <iostream>
#include <unistd.h>
//---------------------------------
//sensors directory
//---------------------------------
#include "../sensors/abstractSensorFactory/abstractSensorFactory.h"
#include "../sensors/factories/airSensorFactoy/airSensorFactory.h"
#include "../sensors/factories/waterSensorFactory/waterSensorFactory.h"
#include "../sensors/factories/earthSensorFactory/earthSensorFactory.h"
#include "../sensors/sensorType/sensorType.h"
#include "../sensors/products/airSensor/airSensor.h"
#include "../sensors/products/waterSensor/waterSensor.h"
#include "../sensors/products/earthSensor/earthSensor.h"
#include "../sensors/sensorNode.h"
//---------------------------------
//displays directory
//---------------------------------
#include "../displays/simpleDisplayFactory/simpleDisplayFactory.h"
#include "../displays/display/display.h"
//---------------------------------
//sensor_mount directory
//---------------------------------
#include "../sensor_mount/sensorMount.h"
//---------------------------------
//data_parser directory
//---------------------------------
#include "../data_parser/EnviroSimDataParser.h"
//---------------------------------

class simulation {

    private:
        abstractSensorFactory* ASFptr; //ptr to air, water and earth sensor factory classes
        sensorType* sensorTypePtr; //ptr to sensor Type class
        simpleDisplayFactory* SDFptr; //ptr to simple display factory class
        sensorMount* sensorMountPtr;    //ptr to sensor mount class
        EnviroSimDataParser* dataParserPtr; //ptr to data parser class
        std::vector<sensorType* >* vSensors; //ptr to vector of sensor ptrs
        std::vector<display* >* vDisplays; //ptr to vector of display ptrs

        void createDisplays();
        void createAirSensors(int& airCtr);
        void createWaterSensors(int& waterCtr);
        void createEarthSensors(int& earthCtr);
        void getFile();
        void buildDevices();
        void updateSensors();
        void simulationDescription1();
        void simulationDescription2();
        void simulationDescription3();

    public:
        simulation();
        ~simulation();
        void runSimulation();

};

#endif //SIMULATION_H
