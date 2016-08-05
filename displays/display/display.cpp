//====================================================================
// display.cpp
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
//Sets private display node ptr
//to NULL
//---------------------------------
display::display(){
    this->displayNodePtr = NULL;
};

//---------------------------------
//function: ~display()
//Sets sensor node ptrs to null,
//deletes private display node ptr,
//sets private display node ptr to NULL.
//---------------------------------
display::~display(){

    for(unsigned long i = 0; i < this->displayNodePtr->vSensorNodePtrs.size(); i++)
        this->displayNodePtr->vSensorNodePtrs.at(i) = NULL;

    delete this->displayNodePtr;
    this->displayNodePtr = NULL;
};

//---------------------------------
//function: setDisplay()
//Sets private member displayNodePtr
//to displayNode
//---------------------------------
void display::setDisplay(displayNode* dnPtr){
    this->displayNodePtr = dnPtr;
};

//---------------------------------
//function: displayData()
//Displays all display devices and
//their associated sensor(s).
//---------------------------------
void display::displayData(){

    std::cout << "Display Device: " << this->displayNodePtr->type
    << "\n";

    for(unsigned long i = 0; i < this->displayNodePtr->vSensorNodePtrs.size(); i++) {
        std::cout << std::setw(15) << "Sensor " <<
                this->displayNodePtr->vSensorNodePtrs.at(i)->ID << "\n"
        << std::setw(23) <<"Type = " <<
                this->displayNodePtr->vSensorNodePtrs.at(i)->type << "  " <<
        "Material = " <<
                this->displayNodePtr->vSensorNodePtrs.at(i)->material << "\n"
        << std::setw(34) << "Current Reading = " <<
                this->displayNodePtr->vSensorNodePtrs.at(i)->sensorData << " " <<
                this->displayNodePtr->vSensorNodePtrs.at(i)->units << "\n\n";
    }
};

//---------------------------------
//function: relayDisplayData()
//Returns the private pointer to
//display node struct
//---------------------------------
displayNode* display::relayDisplayData(){
    return this->displayNodePtr;
};

