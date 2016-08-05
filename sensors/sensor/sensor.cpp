//====================================================================
// sensor.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "sensor.h"

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: generateSensorData()
//Generates data for each sensor node
//in the sensor node vector that
//the private member variable vPtr
//points to.
//---------------------------------
void sensor::generateSensorData(unsigned long& vSize) {
    for(unsigned long i = 0; i < vSize; i++) {
        vPtr->at(i)->sensorData = vPtr->at(i)->minVal + (rand() %
                (int) (vPtr->at(i)->maxVal - vPtr->at(i)->minVal + 1));
    }
};

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: sensor()
//Dynamically create sensorNode vector
//set vPtr to dynamically created vector.
//---------------------------------
sensor::sensor(){
    vPtr = new std::vector<sensorNode*>;
};

//---------------------------------
//function: ~sensor()
//Deletes ptrs within dynamic vector
//of sensor node ptrs and
//deletes dynamic vector.
//---------------------------------
sensor::~sensor() {
    for(unsigned int i=0; i < vPtr->size(); i++) {
        delete vPtr->at(i);
        vPtr->at(i) = NULL;
    }
    delete vPtr;
    vPtr = NULL;
};

//---------------------------------
//function: getSensor()
//Fills dynamically created sensorNode
//vector with sensorNode(s).
//---------------------------------
void sensor::getSensor(sensorNode* snPtr){
    vPtr->push_back(snPtr);
};

//---------------------------------
//funciton: updateSensors()
//Calls fctn generateSensorData
//and passes it the size of the vector
//container containing sensor nodes.
//---------------------------------
void sensor::updateSensors() {
    unsigned long size = vPtr->size();
    this->generateSensorData(size);
};

//---------------------------------
//funciton: relaySensorData()
//Returns the private pointer vPtr,
//which is pointing to a vector
//container containing ptrs to all
//the sensor nodes.
//---------------------------------
std::vector<sensorNode*>* sensor::relaySensorData(){
    return vPtr;
};