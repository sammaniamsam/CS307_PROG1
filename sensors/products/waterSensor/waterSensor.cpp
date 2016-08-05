//====================================================================
// waterSensor.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "waterSensor.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: waterSensor()
//Initializes private member variable
//---------------------------------
waterSensor::waterSensor() {

    this->sensorNodePtr = NULL;
}

//---------------------------------
//function: ~waterSensor()
//Deallocates memory for sensorNode
//and sets private member variable
//to NULL
//---------------------------------
waterSensor::~waterSensor() {

    delete this->sensorNodePtr; this->sensorNodePtr = NULL;
}

//---------------------------------
//function setSensor()
//Assigns a sensor node which is defined
//to the private member variable sensorNodePtr
//---------------------------------
void waterSensor::setSensor(sensorNode *snPtr) {

    this->sensorNodePtr = snPtr;
}

//---------------------------------
//function: updateSensor()
//Generates data for water sensor.
//---------------------------------
void waterSensor::updateSensor() {

    sensorNodePtr->sensorData = sensorNodePtr->minVal + (rand() %
        (int) (sensorNodePtr->maxVal - sensorNodePtr->minVal + 1));
}

//---------------------------------
//function: relaySensorData()
//Returns sensor node containing water
//sensor data.
//---------------------------------
sensorNode* waterSensor::relaySensorData() {

    return this->sensorNodePtr;
}
