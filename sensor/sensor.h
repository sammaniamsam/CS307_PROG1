/*******************************************************************
* sensor.h
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/
#include <iostream>
#include <vector>
#include <time.h>

#ifndef SENSOR_H
#define SENSOR_H

struct sensorNode {
    char type[64];
    char material[64];
    int ID;
    char units[64];
    double minVal;
    double maxVal;
    double sensorData;
};

class sensor {

private:
    /***********************************/
    //vector pointer to vector
    //of sensorNode pointers
    std::vector<sensorNode*> *vPtr;


    /***********************************/
    //A recursive function that generates data
    //for each sensor node in a vector container
    void generateSensorData(unsigned long vSize);

public:
    /***********************************/
    //dynamically create sensorNode vector
    //set vPtr to dynamically created vector
    sensor();

    /***********************************/
    //deletes dynamic vector and nodes
    //set private pointer to null
    ~sensor();

    /***********************************/
    //fills dynamically created sensorNode
    //vector with sensorNode(s)
    void getSensor(sensorNode* snPtr);

    /***********************************/
    //calls the recursive fctn generateSensorData
    //and passes it the size of the vector
    //container containing sensor nodes
    void updateSensors();

    /***********************************/
    //returns the private pointer vPtr,
    //which is pointing to a vector
    //container containing all the sensor
    //nodes
    std::vector<sensorNode*>* relaySensorData();
};

#endif