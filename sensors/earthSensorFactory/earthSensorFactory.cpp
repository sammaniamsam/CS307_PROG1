//====================================================================
// earthSensorFactory.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "earthSensorFactory.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Constructor
//---------------------------------
earthSensorFactory::earthSensorFactory() { }

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Destructor
//---------------------------------
earthSensorFactory::~earthSensorFactory() { }

//---------------------------------
//function: getInstanceNumber()
//Returns instance number
//---------------------------------
int earthSensorFactory::getInstanceNumber() {
    return this->instanceNumber;
}

//---------------------------------
//function: getInstance()
//Returns the singleton instance of
//earthSensorFactory
//---------------------------------
earthSensorFactory* earthSensorFactory::getInstance() {

    static earthSensorFactory *theInstance;
    static int counter = 1;
    if(theInstance == NULL)
    {
        theInstance = new earthSensorFactory();
        theInstance->instanceNumber = counter;
        counter++;
    }
    return theInstance;
};

///---------------------------------
//function: createSensorInstance()
//Returns dynamic instance of earth sensor
//---------------------------------
sensorType* earthSensorFactory::createSensorInstance() {
    return new earthSensor();
}