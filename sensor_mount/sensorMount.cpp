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

    displayNode* dnPtr;

    for(unsigned long i = 0; i < numDisplays; i++) {

        //set dnPtr
        dnPtr = vDisplayPtr->at(i)->relayDisplayData();

        //print connected display type
        std::cout << "\n" << std::setw(15) << "Type = " << dnPtr->type;

        for (int j = 0; j < dnPtr->IDCount; j++) {

            //print ID of sensor stored in display
            std::cout << "\n" << std::setw(23) << "Sensor " << j << " ID = " <<
                    dnPtr->IDs[j];
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
//Creates dynamic display and sensor
//vectors
//---------------------------------
sensorMount::sensorMount() {
    this->vDisplayPtr = new std::vector<display*>;
    vSensorPtr = NULL;
};

//---------------------------------
//function: ~sensorMount()
//Deallocates memory for each
//dynamic class instance stored in
//sensor mount's private display and
//sensor vectors. Then, sets private
//member pointers to NULL
//---------------------------------
sensorMount::~sensorMount() {

    for(std::vector<display *>::iterator it = this->vDisplayPtr->begin();
        it != this->vDisplayPtr->end(); it++) {

        delete it;
        it = NULL;
    }
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
//Add display to sensor mount's
//private display vector
//---------------------------------
void sensorMount::attachDisplay(display* displayPtr) {
    this->vDisplayPtr->push_back(displayPtr);
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
