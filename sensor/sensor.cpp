/*******************************************************************
* sensor.cpp
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/

#include "sensor.h"

/***********************************/
sensor::sensor(){
    vPtr = new std::vector<sensorNode*>;
};
/***********************************/
sensor::~sensor() {
    for(int i=0; i < vPtr->size(); i++) {
        delete vPtr->at(i);
        vPtr->at(i) = NULL;
    }
    delete vPtr;
    vPtr = NULL;
};
/***********************************/
void sensor::getSensor(sensorNode* snPtr){
    vPtr->push_back(snPtr);
};
/***********************************/
void sensor::updateSensors() {
    unsigned long size = (vPtr->size()) - 1;
    generateSensorData(size);
};
/***********************************/
void sensor::generateSensorData(unsigned long vSize) {
    srand((unsigned int)(time(NULL)));
    vPtr->at(vSize)->sensorData = vPtr->at(vSize)->minVal + (rand() %
            (int)(vPtr->at(vSize)->maxVal - vPtr->at(vSize)->minVal + 1));
    if(vSize == 0) return;
    generateSensorData(vSize-1);
};
/***********************************/
std::vector<sensorNode*>* sensor::relaySensorData(){
    return vPtr;
};