//====================================================================
// airSensor.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "airSensor.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: airSensor()
//Initializes private member variable
//---------------------------------
airSensor::airSensor() {

    this->sensorNodePtr = NULL;
}

//---------------------------------
//function: ~airSensor()
//Deallocates memory for sensorNode
//and sets private member variable
//to NULL
//---------------------------------
airSensor::~airSensor() {

    delete this->sensorNodePtr; this->sensorNodePtr = NULL;
}

//---------------------------------
//function setSensor()
//Assigns a sensor node which is defined
//to the private member variable sensorNodePtr
//---------------------------------
void airSensor::setSensor(sensorNode *snPtr) {

    this->sensorNodePtr = snPtr;
}

//---------------------------------
//function: updateSensor()
//Generates data for air sensor.
//---------------------------------
void airSensor::updateSensor() {

    sensorNodePtr->sensorData = sensorNodePtr->minVal + (rand() %
         (int) (sensorNodePtr->maxVal - sensorNodePtr->minVal + 1));
}

//---------------------------------
//function: relaySensorData()
//Returns sensor node containing air
//sensor data.
//---------------------------------
sensorNode* airSensor::relaySensorData() {

    return this->sensorNodePtr;
}