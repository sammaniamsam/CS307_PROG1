/*******************************************************************
* sensorMount.cpp
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/

#include "sensorMount.h"

/***********************************/
sensorMount::sensorMount() {
    vDisplayPtr = NULL;
    vSensorPtr = NULL;
};
/***********************************/
sensorMount::~sensorMount() {
    vDisplayPtr = NULL;
    vSensorPtr = NULL;
};
/***********************************/
void sensorMount::attachSensors(std::vector<sensorNode *> *vSensors) {
    vSensorPtr = vSensors;
};
/***********************************/
void sensorMount::attachDisplays(std::vector<displayNode *> *vDisplays) {
    vDisplayPtr = vDisplays;
};
/***********************************/
void sensorMount::displayConnectedDevices() {
    unsigned long dSize = (vDisplayPtr->size()) - 1;
    unsigned long sSize = (vSensorPtr->size()) - 1;
    std::cout << "\n\n" << "The following data is provided for information" <<
    "\n" << std::setw(37) << "and data check purposes only.";
    std::cout << "\n\n" << "Sensor Mount holds the following sensors";
    displayConnectedSensors(sSize);
    std::cout << "\n\n" << "Sensor Mount holds the following display"
                            << " devices";
    displayConnectedDisplays(dSize);
};
/***********************************/
void sensorMount::displayConnectedDisplays(unsigned long numDisplays) {
    std::cout << "\n" << std::setw(15) << "Type = " <<
    vDisplayPtr->at(numDisplays)->type;
    for(int i=0; i < vDisplayPtr->at(numDisplays)->IDCount; i++){
        std::cout << "\n" << std::setw(23) << "Sensor " << i << " ID = " <<
        vDisplayPtr->at(numDisplays)->IDs[i];
    }
    if(numDisplays == 0) return;
    displayConnectedDisplays(numDisplays-1);
};
/***********************************/
void sensorMount::displayConnectedSensors(unsigned long numSensors) {
    std::cout << "\n" << std::setw(15) << "Type = " <<
    vSensorPtr->at(numSensors)->type << std::setw(8) << "ID = " <<
    vSensorPtr->at(numSensors)->ID;
    std::cout << "\n" << std::setw(28) << "Material = " <<
    vSensorPtr->at(numSensors)->material << std::setw(10) <<
    "Units = " << vSensorPtr->at(numSensors)->units;
    std::cout << "\n" << std::setw(23) << "Min = " <<
    vSensorPtr->at(numSensors)->minVal << std::setw(8) << "Max = " <<
    vSensorPtr->at(numSensors)->maxVal << std::setw(8) << "Cur = " <<
    vSensorPtr->at(numSensors)->sensorData;
    if(numSensors == 0) return;
    displayConnectedSensors(numSensors-1);
};
/***********************************/
bool sensorMount::linkSensorsToDisplays() {
    long int links = 0;

    for(int i=0; i < vSensorPtr->size(); i++){
        for(int j=0; j < vDisplayPtr->size(); j++){
            for(int k=0; k < vDisplayPtr->at(j)->IDCount; k++){
                if(vSensorPtr->at(i)->ID == vDisplayPtr->at(j)->IDs[k]) {
                    vDisplayPtr->at(j)->vSensorNodePtrs
                    .push_back(vSensorPtr->at(i));
                    ++links;
                }
            }
        }
    }

    if(vSensorPtr->size() == links){
        return true;
    } else return false;
};
