/*******************************************************************
* sensor.cpp
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/

#include "display.h"

/***********************************/
display::display(){
    vPtr = new std::vector<displayNode*>;
};
/***********************************/
display::~display(){
    for(int i=0; i < vPtr->size(); i++) {
        for(int j=0; j < vPtr->at(i)->vSensorNodePtrs.size(); j++)
            vPtr->at(i)->vSensorNodePtrs.at(j) = NULL;
        delete vPtr->at(i);
        vPtr->at(i) = NULL;
    }
    delete vPtr;
    vPtr = NULL;
};
/***********************************/
void display::getDisplay(displayNode* dnPtr){
    vPtr->push_back(dnPtr);
};
/***********************************/
void display::displayData(){
    for(int i=0; i < vPtr->size(); i++){
        std::cout << "Display Device: " << vPtr->at(i)->type
        << "\n";
        for(int j=0; j < vPtr->at(i)->vSensorNodePtrs.size(); j++) {
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
/***********************************/
std::vector<displayNode*>* display::relayDisplayData(){
    return vPtr;
};

