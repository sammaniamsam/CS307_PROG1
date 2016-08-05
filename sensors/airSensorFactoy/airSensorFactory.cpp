//====================================================================
// airSensorFactory.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "airSensorFactory.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Constructor
//---------------------------------
airSensorFactory::airSensorFactory() { }

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Destructor
//---------------------------------
airSensorFactory::~airSensorFactory() { }

//---------------------------------
//function: getInstanceNumber()
//Returns instance number
//---------------------------------
int airSensorFactory::getInstanceNumber() {
    return this->instanceNumber;
}

//---------------------------------
//function: getInstance()
//Returns the singleton instance of
//airSensorFactory
//---------------------------------
airSensorFactory* airSensorFactory::getInstance() {

    static airSensorFactory *theInstance;
    static int counter = 1;
    if(theInstance == NULL)
    {
        theInstance = new airSensorFactory();
        theInstance->instanceNumber = counter;
        counter++;
    }
    return theInstance;
};

///---------------------------------
//function: createAirSensorInstance()
//Returns dynamic instance of air sensor
//---------------------------------
sensorType* airSensorFactory::createSensorInstance() {
    return new airSensor();
}