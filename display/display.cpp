//====================================================================
// sensor.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "display.h"

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: display()
//Dynamically creates displayNode vector
//and sets vPtr to dynamically
//created vector.
//---------------------------------
display::display(){
    vPtr = new std::vector<displayNode*>;
};

//---------------------------------
//function: ~display()
//Deletes dynamic vector and nodes,
//sets private pointer to null,
//sets vSensorNodePtrs to null.
//---------------------------------
display::~display(){
    for(unsigned long i=0; i < vPtr->size(); i++) {
        for(unsigned long j=0; j < vPtr->at(i)->vSensorNodePtrs.size(); j++)
            vPtr->at(i)->vSensorNodePtrs.at(j) = NULL;
        delete vPtr->at(i);
        vPtr->at(i) = NULL;
    }
    delete vPtr;
    vPtr = NULL;
};

//---------------------------------
//function: getDisplay()
//Fills dynamically created displayNode
//vector with displayNode ptrs.
//---------------------------------
void display::getDisplay(displayNode* dnPtr){
    vPtr->push_back(dnPtr);
};

//---------------------------------
//function: displayData()
//Displays all display devices and
//their associated sensor(s).
//---------------------------------
void display::displayData(){
    for(unsigned long i=0; i < vPtr->size(); i++){
        std::cout << "Display Device: " << vPtr->at(i)->type
        << "\n";
        for(unsigned long j=0; j < vPtr->at(i)->vSensorNodePtrs.size(); j++) {
            std::cout << std::setw(15) << "Sensor " <<
            vPtr->at(i)->vSensorNodePtrs.at(j)->ID << "\n"
            << std::setw(23) <<"Type = " <<
            vPtr->at(i)->vSensorNodePtrs.at(j)->type << "  " <<
            "Material = " <<
            vPtr->at(i)->vSensorNodePtrs.at(j)->material << "\n"
            << std::setw(34) << "Current Reading = " <<
            vPtr->at(i)->vSensorNodePtrs.at(j)->sensorData << " " <<
            vPtr->at(i)->vSensorNodePtrs.at(j)->units << "\n\n";
        }
    }
};

//---------------------------------
//function: relayDisplayData()
//Returns the private pointer vPtr,
//which is pointing to a vector
//container containing ptrs to
//display nodes.
//---------------------------------
std::vector<displayNode*>* display::relayDisplayData(){
    return vPtr;
};

