/*******************************************************************
* simulation.h
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/
#include <iostream>
#include <unistd.h>
/********************************/
#include "../sensor/sensor.h"
#include "../display/display.h"
#include "../sensor_mount/sensorMount.h"
#include "../data_parser/EnviroSimDataParser.h"
/********************************/

#ifndef SIMULATION_H
#define SIMULATION_H

class simulation {

private:
    sensor* sensorPtr;
    display* displayPtr;
    sensorMount* sensorMountPtr;
    EnviroSimDataParser* dataParserPtr;

    /***********************************/
    //recursive function which creates display
    //structures, assigns them data from
    //data parser, and passes each one
    //to the get display function getDisplay
    void createDisplays(int& count);

    /***********************************/
    //recursive function which creates sensor
    //structures, assigns them data from
    //data parser, and passes each one
    //to the get sensor function getSensor
    void createSensors(int& count);

    /***********************************/
    //will prompt user to enter file
    //pass file name (char array) into
    //data parser fctn EnviroSimDataParser
    void getFile();

    /***********************************/
    //calls data parser fctns to get sensor
    //and display counts and then passes the
    //counts to simulations fctns
    /******************/
    //createDisplays and createSensors
    //to build the devices
    /******************/
    //At end of function the dynamic
    //data parser instance is deleted and
    //its ptr set to null
    void buildDevices();

    /***********************************/
    //sensor and display relay fctns are
    //called
    //data is passed to sensor mount's display
    //and sensor attach fctns
    //Finally, sensor mount's linkSensorsToDisplays
    //is called
    void attachDevices();

    /***********************************/
    //displays a description of the program
    void simulationDescription();

public:
    /***********************************/
    //dynamically create instances of
    //display, sensor, sensor mount, data
    //parser and assign to private ptrs
    simulation();

    /***********************************/
    //deallocate memory for: display, sensor,
    //sensor mount, data parser
    //set all private pointers to null
    ~simulation();

    /***********************************/
    void runSimulation();

};


#endif
