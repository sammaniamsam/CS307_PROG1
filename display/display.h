/*******************************************************************
* display.h
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include "../sensor/sensor.h"

#ifndef DISPLAY_H
#define DISPLAY_H

struct displayNode {
    char type[64];
    int IDs[7];
    int IDCount;
    std::vector<sensorNode*> vSensorNodePtrs;
};

class display {

private:
    std::vector<displayNode*> *vPtr;
public:
    /***********************************/
    //dynamically create displayNode vector
    //set vPtr to dynamically created vector
    display();

    /***********************************/
    //deletes dynamic vector and nodes,
    //sets private pointer to null,
    //sets vSensorNodePtrs to null
    ~display();

    /***********************************/
    //fills dynamically created displayNode
    //vector with displayNode(s)
    void getDisplay(displayNode* dnPtr);

    /***********************************/
    //returns the private pointer vPtr,
    //which is pointing to a vector
    //container containing all the display
    //nodes
    std::vector<displayNode*>* relayDisplayData();

    /***********************************/
    //displays all display devices and
    //their associated sensor(s)
    void displayData();
};

#endif