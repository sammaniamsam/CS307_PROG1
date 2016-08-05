//====================================================================
// abstractSensorFactory.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "abstractSensorFactory.h"
//-----------------------------------

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Constructor
//---------------------------------
abstractSensorFactory::abstractSensorFactory(){ }

//---------------------------------
//Destructor
//---------------------------------
abstractSensorFactory::~abstractSensorFactory(){ }

//---------------------------------
//Create sensor instance. Virtual
//function that subclasses must
//implement.
//---------------------------------
sensorType * abstractSensorFactory::createSensorInstance() {
    return NULL;
}