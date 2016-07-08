/*******************************************************************
* sensorMount.h
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include "../display/display.h"
#include "../sensor/sensor.h"

#ifndef SENSORMOUNT_H
#define SENSORMOUNT_H

class sensorMount {

private:
    std::vector<displayNode*> *vDisplayPtr;
    std::vector<sensorNode*> *vSensorPtr;

    /***********************************/
    //prints to the screen all the displays
    //connected to sensor mount
    void displayConnectedDisplays(unsigned long numDisplays);

    /***********************************/
    //prints to the screen all sensors
    //connected to sensor mount
    void displayConnectedSensors(unsigned long numSensors);

public:
    sensorMount();	//set private pointers to null
    ~sensorMount();	//set private pointers to null

    /***********************************/
    //assigns the address in memory of the
    //vector container containing ALL sensors
    //to the private pointer vSensorPtr
    void attachSensors(std::vector<sensorNode*>* vSensors);

    /***********************************/
    //assigns the address in memory of the
    //vector container containing ALL displays
    //to the private pointer vDisplayPtr
    void attachDisplays(std::vector<displayNode*>* vDisplays);

    /***********************************/
    //calls displayConnectedDisplays and
    //displayConnectedSensors to print all
    //connected devices
    void displayConnectedDevices();

    /***********************************/
    //matches the ID(s) stored in displayNode with
    //the proper sensor ID(s). Then,
    //creates ptrs of type sensorNode and pushes
    //them into the vSensorNodePtrs property of
    //displayNode
    //Note: needs to return a bool because a display could
    //contain a list of sensor ID's and a sensor for a
    //certain ID may NOT actually exist
    bool linkSensorsToDisplays();
};

#endif