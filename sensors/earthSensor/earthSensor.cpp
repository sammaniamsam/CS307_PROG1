//====================================================================
// earthSensor.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "earthSensor.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: earthSensor()
//Initializes private member variable
//---------------------------------
earthSensor::earthSensor() {

    this->sensorNodePtr = NULL;
}

//---------------------------------
//function: ~earthSensor()
//Deallocates memory for sensorNode
//and sets private member variable
//to NULL
//---------------------------------
earthSensor::~earthSensor() {

    delete this->sensorNodePtr; this->sensorNodePtr = NULL;
}

//---------------------------------
//function setSensor()
//Assigns a sensor node which is defined
//to the private member variable sensorNodePtr
//---------------------------------
void earthSensor::setSensor(sensorNode *snPtr) {

    this->sensorNodePtr = snPtr;
}

//---------------------------------
//function: updateSensor()
//Generates data for earth sensor.
//---------------------------------
void earthSensor::updateSensor() {

    sensorNodePtr->sensorData = sensorNodePtr->minVal + (rand() %
        (int) (sensorNodePtr->maxVal - sensorNodePtr->minVal + 1));
}

//---------------------------------
//function: relaySensorData()
//Returns sensor node containing earth
//sensor data.
//---------------------------------
sensorNode* earthSensor::relaySensorData() {

    return this->sensorNodePtr;
}
