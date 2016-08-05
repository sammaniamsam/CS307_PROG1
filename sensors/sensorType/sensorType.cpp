//====================================================================
// sensorType.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "sensorType.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//Constructor
//---------------------------------
sensorType::sensorType() { }

//---------------------------------
//Destructor
//---------------------------------
sensorType::~sensorType() { }

//---------------------------------
//Set sensor data. Virtual function
//that all subclasses must implement
//---------------------------------
void sensorType::setSensor(sensorNode* snPtr) { }

//---------------------------------
//Relay sensor data. Virtual function
//that all subclasses must implement
//---------------------------------
sensorNode* sensorType::relaySensorData() {
    return NULL;
}

//---------------------------------
//Update sensor. Virtual function that
//all subclasses must implement
//---------------------------------
void sensorType::updateSensor() { }