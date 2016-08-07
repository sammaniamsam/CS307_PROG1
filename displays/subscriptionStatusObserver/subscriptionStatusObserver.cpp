//====================================================================
// subscriptionStatusObserver.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "subscriptionStatusObserver.h"

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: subscriptionStatusObserver()
//---------------------------------
subscriptionStatusObserver::subscriptionStatusObserver() {
    this->subscriptionCount = 0;
}

//---------------------------------
//function: ~subscriptionStatusObserver()
//---------------------------------
subscriptionStatusObserver::~subscriptionStatusObserver() { }

//---------------------------------
//function: update()
//---------------------------------
void subscriptionStatusObserver::update(subject *subjectPtr) {

    this->subscriptionCount = ((display* )subjectPtr)->relaySubscriptionCount();

    if(this->subscriptionCount > 0){
        std::cout << this->subscriptionCount << " sensors are not being monitored.";
    }
}