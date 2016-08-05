//====================================================================
// waterSensorFactory.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "waterSensorFactory.h"
//---------------------------------

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Constructor
//---------------------------------
waterSensorFactory::waterSensorFactory() { }

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//Destructor
//---------------------------------
waterSensorFactory::~waterSensorFactory() { }

//---------------------------------
//function: getInstanceNumber()
//Returns instance number
//---------------------------------
int waterSensorFactory::getInstanceNumber() {
    return this->instanceNumber;
}

//---------------------------------
//function: getInstance()
//Returns the singleton instance of
//waterSensorFactory
//---------------------------------
waterSensorFactory* waterSensorFactory::getInstance() {

    static waterSensorFactory *theInstance;
    static int counter = 1;
    if(theInstance == NULL)
    {
        theInstance = new waterSensorFactory();
        theInstance->instanceNumber = counter;
        counter++;
    }
    return theInstance;
};

///---------------------------------
//function: createSensorInstance()
//Returns dynamic instance of water sensor
//---------------------------------
sensorType* waterSensorFactory::createSensorInstance() {
    return new waterSensor();
}