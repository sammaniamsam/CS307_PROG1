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
        dnPtr = this->vDisplayPtr->at(i)->relayDisplayData();

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
        this->vSensorPtr->at(i)->type << std::setw(8) << "ID = " <<
        this->vSensorPtr->at(i)->ID;
        std::cout << "\n" << std::setw(28) << "Material = " <<
        this->vSensorPtr->at(i)->material << std::setw(10) <<
        "Units = " << vSensorPtr->at(i)->units;
        std::cout << "\n" << std::setw(23) << "Min = " <<
        this->vSensorPtr->at(i)->minVal << std::setw(8) << "Max = " <<
        this->vSensorPtr->at(i)->maxVal << std::setw(8) << "Cur = " <<
        this->vSensorPtr->at(i)->sensorData;
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
    this->vSensorPtr = NULL;
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
    this->vDisplayPtr = NULL;


    this->vSensorPtr = NULL;
};

//---------------------------------
//function: attachSensors()
//attaches sensors to sensor mount
//---------------------------------
void sensorMount::attachSensors(std::vector<sensorNode *> *vSensors) {
    this->vSensorPtr = vSensors;
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
    unsigned long dSize = this->vDisplayPtr->size();
    unsigned long sSize = this->vSensorPtr->size();
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

    /*for(unsigned long i=0; i < vSensorPtr->size(); i++){
        for(unsigned long j=0; j < vDisplayPtr->size(); j++){
            for(int k=0; k < vDisplayPtr->at(j)->IDCount; k++){
                if(vSensorPtr->at(i)->ID == vDisplayPtr->at(j)->IDs[k]) {
                    vDisplayPtr->at(j)->vSensorNodePtrs
                    .push_back(vSensorPtr->at(i));
                    ++links;
                }
            }
        }
    }*/

    //------------------------------------
    //re-configure sensor class to allow
    //code below to work
    //------------------------------------

    //for each sensor in vSensorPtr
    for(unsigned long i = 0; i < this->vSensorPtr->size(); i++){

        //for each display in vDisplayPtr
        for(unsigned long j = 0; j < this->vDisplayPtr->size(); j++){

            //for each sensor ID in a given display
            for(int k = 0; k < this->vDisplayPtr->at(j)->relayDisplayData()->IDCount; k++){

                //compare sensor i's ID to each sensor ID in display's
                //list of sensor ID(s)
                if(this->vSensorPtr->at(i)->relaySensorData()->ID ==
                        this->vDisplayPtr->at(j)->relayDisplayData()->IDs[k]) {

                    //ID match, link sensor to display
                    this->vDisplayPtr->at(j)->relayDisplayData()->vSensorNodePtrs
                            .push_back(this->vSensorPtr->at(i)->relaySensorData());
                    ++links;
                }
            }
        }
    }

    //check to ensure all sensors were
    //linked AT LEAST ONCE
    if(this->vSensorPtr->size() <= links){
        return true;
    } else return false;
};
