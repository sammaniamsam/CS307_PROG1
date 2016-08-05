//====================================================================
// simpleDisplayFactory.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================

#include "simpleDisplayFactory.h"

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: simpleDisplayFactory()
//---------------------------------
simpleDisplayFactory::simpleDisplayFactory() { };

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: ~simpleDisplayFactory()
//---------------------------------
simpleDisplayFactory::~simpleDisplayFactory() { };

//---------------------------------
//function: getInstanceNumber()
//Returns instance number
//---------------------------------
int simpleDisplayFactory::getInstanceNumber() {
    return this->instanceNumber;
};

//---------------------------------
//function: getInstance()
//Returns the singleton instance of
//simpleDisplayFactory
//---------------------------------
simpleDisplayFactory* simpleDisplayFactory::getInstance() {

        static simpleDisplayFactory *theInstance;
        static int counter = 1;
        if(theInstance == NULL)
        {
            theInstance = new simpleDisplayFactory();
            theInstance->instanceNumber = counter;
            counter++;
        }
        return theInstance;
};

//---------------------------------
//function: createDisplayInstance()
//Returns dynamic instance of display
//---------------------------------
display* simpleDisplayFactory::createDisplayInstance() {
    display *displayPtr =  new display();
    return displayPtr;
};



