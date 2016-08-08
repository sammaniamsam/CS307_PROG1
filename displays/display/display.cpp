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
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: clearObservers()
//---------------------------------
void display::clearObservers() {

    for(unsigned long i = 0; i < this->vObserversPtr->size(); i++){
        delete this->vObserversPtr->at(i);
    }
}

//---------------------------------
//function: setSubscriptionVector()
//---------------------------------
void display::setSubscriptionVector() {

    for(unsigned long i = 0; i < this->displayNodePtr->vSensorNodePtrs.size(); i++){
        //create sensorSubscription instance
        sensorSubscription* ssPtr = new sensorSubscription;
        this->vSubscriptions.push_back(ssPtr);
        //initialized sensorSubscription status
        this->vSubscriptions.at(i)->status = true;
        //give sensorSubscription and ID
        this->vSubscriptions.at(i)->ID = this->displayNodePtr->vSensorNodePtrs.at(i)->ID;
    }
}

//---------------------------------
//function: clearSubscriptionVector()
//---------------------------------
void display::clearSubscriptionVector() {

    for(unsigned long i = 0; i < this->vSubscriptions.size(); i++){
        delete this->vSubscriptions.at(i);
    }
}

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: display()
//Sets private display node ptr
//to NULL
//---------------------------------
display::display(){

    this->displayNodePtr = NULL;
    this->vObserversPtr = new std::vector<observer*>;
}

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

    this->clearObservers();
    this->clearSubscriptionVector();
}

//---------------------------------
//function: setDisplay()
//Sets private member displayNodePtr
//to displayNode
//---------------------------------
void display::setDisplay(displayNode* dnPtr){

    this->displayNodePtr = dnPtr;
}

//---------------------------------
//function: displayData()
//Displays all display devices and
//their associated sensor(s).
//---------------------------------
void display::displayData(){

    this->setSubscriptionVector();

    std::cout << "Display Device: " << this->displayNodePtr->type
    << "\n";

    for(unsigned long i = 0; i < this->displayNodePtr->vSensorNodePtrs.size(); i++) {

        //display sensors that are subscribed too
        if(this->vSubscriptions.at(i)->status) {
            std::cout << std::setw(15) << "Sensor " <<
            this->displayNodePtr->vSensorNodePtrs.at(i)->ID << "\n"
            << std::setw(23) << "Type = " <<
            this->displayNodePtr->vSensorNodePtrs.at(i)->type << "  " <<
            "Material = " <<
            this->displayNodePtr->vSensorNodePtrs.at(i)->material << "\n"
            << std::setw(34) << "Current Reading = " <<
            this->displayNodePtr->vSensorNodePtrs.at(i)->sensorData << " " <<
            this->displayNodePtr->vSensorNodePtrs.at(i)->units << "\n\n";
        }
    }
}

//---------------------------------
//function: displayMonitoredSensors()
//---------------------------------
void display::displayMonitoredSensors() {

    std::cout << "\n";
    for(unsigned long i = 0; i < this->displayNodePtr->vSensorNodePtrs.size(); i++) {
        std::cout << std::setw(10) << i+1 << ". Sensor " <<
        this->displayNodePtr->vSensorNodePtrs.at(i)->ID <<
        " - is monitoring" << "\n";
    }
}

//---------------------------------
//function: relayDisplayData()
//Returns the private pointer to
//display node struct
//---------------------------------
displayNode* display::relayDisplayData(){

    return this->displayNodePtr;
}

//---------------------------------
//function: registerObserver()
//---------------------------------
void display::registerObserver(observer *obs) {

    this->vObserversPtr->push_back(obs);
}

//---------------------------------
//function: notifyObservers()
//---------------------------------
void display::notifyObservers() {

    for(unsigned long i = 0; i < this->vObserversPtr->size(); i++){
        //pass display to observer
        this->vObserversPtr->at(i)->update(this);
    }
}

//---------------------------------
//function: setSubscriptionStatus()
//---------------------------------
bool display::setSubscriptionStatus(int& sensorID) {

    for(unsigned long i = 0; i < this->vSubscriptions.size(); i++) {

        //ID found
        if(this->vSubscriptions.at(i)->ID == sensorID) {
            //toggle status
            this->vSubscriptions.at(i)->status = !this->vSubscriptions.at(i)->status;
            return true;
        }
    }

    //ID not found
    return false;
}

//---------------------------------
//function: relaySubscriptionCount()
//---------------------------------
int display::relaySubscriptionCount() {

    int unSubscribedCtr = 0;

    for(unsigned long i = 0; i < this->vSubscriptions.size(); i++){

        //is NOT subscribed
        if(!this->vSubscriptions.at(i)->status)
            //increment counter
            unSubscribedCtr++;
    }

    return unSubscribedCtr;
}
