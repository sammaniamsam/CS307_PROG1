//====================================================================
// sensorMount.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "sensorMount.h"

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: displayConnectedDisplays()
//Prints to the screen all the displays
//connected to sensor mount
//---------------------------------
void sensorMount::displayConnectedDisplays(unsigned long& numDisplays) {
    for(unsigned long i = 0; i < numDisplays; i++) {
        std::cout << "\n" << std::setw(15) << "Type = " <<
        vDisplayPtr->at(i)->type;
        for (int j = 0; j < vDisplayPtr->at(i)->IDCount; j++) {
            std::cout << "\n" << std::setw(23) << "Sensor " << j << " ID = " <<
            vDisplayPtr->at(i)->IDs[j];
        }
    }
};

//---------------------------------
//function: displayConnectedSensors()
//Prints to the screen all the sensors
//connected to sensor mount
//---------------------------------
void sensorMount::displayConnectedSensors(unsigned long& numSensors) {
    for(unsigned long i = 0; i < numSensors; i++){
        std::cout << "\n" << std::setw(15) << "Type = " <<
        vSensorPtr->at(i)->type << std::setw(8) << "ID = " <<
        vSensorPtr->at(i)->ID;
        std::cout << "\n" << std::setw(28) << "Material = " <<
        vSensorPtr->at(i)->material << std::setw(10) <<
        "Units = " << vSensorPtr->at(i)->units;
        std::cout << "\n" << std::setw(23) << "Min = " <<
        vSensorPtr->at(i)->minVal << std::setw(8) << "Max = " <<
        vSensorPtr->at(i)->maxVal << std::setw(8) << "Cur = " <<
        vSensorPtr->at(i)->sensorData;
    }
};

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: sensorMount()
//Sets private member pointers to
//NULL
//---------------------------------
sensorMount::sensorMount() {
    vDisplayPtr = NULL;
    vSensorPtr = NULL;
};

//---------------------------------
//function: ~sensorMount()
//Sets private member pointers to
//NULL
//---------------------------------
sensorMount::~sensorMount() {
    vDisplayPtr = NULL;
    vSensorPtr = NULL;
};

//---------------------------------
//function: attachSensors()
//attaches sensors to sensor mount
//---------------------------------
void sensorMount::attachSensors(std::vector<sensorNode *> *vSensors) {
    vSensorPtr = vSensors;
};

//---------------------------------
//function: attachDisplays()
//attaches displays to sensor mount
//---------------------------------
void sensorMount::attachDisplays(std::vector<displayNode *> *vDisplays) {
    vDisplayPtr = vDisplays;
};

//---------------------------------
//function: displayConnectedDevices()
//Gets the number of displays and sensors
//and passes those counts to:
//displayConnectedSensors()
//displayConnectedDisplays()
//---------------------------------
void sensorMount::displayConnectedDevices() {
    unsigned long dSize = vDisplayPtr->size();
    unsigned long sSize = vSensorPtr->size();
    std::cout << "\n\n" << "The following data is provided for information" <<
    "\n" << std::setw(37) << "and data check purposes only.";
    std::cout << "\n\n" << "Sensor Mount holds the following sensors";
    this->displayConnectedSensors(sSize);
    std::cout << "\n\n" << "Sensor Mount holds the following display"
                            << " devices";
    this->displayConnectedDisplays(dSize);
};

//---------------------------------
//function: linkSensorsToDisplays()
//Matches the ID(s) stored in
//displayNode with the proper sensor
//ID(s). The sensors that are matched
//to a display node are pushed into
//the vSensorNodePtrs property of
//displayNode
//returns: bool value in case a link
//was unsuccessful
//---------------------------------
bool sensorMount::linkSensorsToDisplays() {
    unsigned long links = 0;

    for(unsigned long i=0; i < vSensorPtr->size(); i++){
        for(unsigned long j=0; j < vDisplayPtr->size(); j++){
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
