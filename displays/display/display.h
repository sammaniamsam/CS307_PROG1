//====================================================================
// display.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#ifndef DISPLAY_H
#define DISPLAY_H
//---------------------------------
#include <iostream>
#include <iomanip>
#include <vector>
//---------------------------------
#include "../../sensors/sensorNode.h"
#include "../subject/subject.h"
#include "../observer/observer.h"
//---------------------------------

//---------------------------------
struct displayNode {
    char type[64];
    int IDs[7];
    int IDCount;
    std::vector<sensorNode*> vSensorNodePtrs;
};
//---------------------------------
struct sensorSubscription {
    int ID;
    bool status;
};
//---------------------------------

class display: public subject {

private:
    displayNode* displayNodePtr; //ptr to displayNode
    std::vector<observer* >* vObserversPtr; //ptr to vertor of observer ptrs
    std::vector<sensorSubscription* > vSubscriptions;

    void clearObservers();
    void setSubscriptionVector();
    void clearSubscriptionVector();

public:
    display();
    ~display();
    void setDisplay(displayNode* dnPtr);
    void displayData();
    displayNode* relayDisplayData();
    void displayMonitoredSensors();

    void registerObserver(observer *obs);       /* virtual */
    void notifyObservers();                     /* virtual */
    bool setSubscriptionStatus(int& sensorID);
    int relaySubscriptionCount();
};

#endif //DISPLAY_H