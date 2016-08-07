//====================================================================
// subject.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//===================================================================
#ifndef CS307_PROG1_SUBJECT_H
#define CS307_PROG1_SUBJECT_H
//---------------------------------
#include "../observer/observer.h"
//---------------------------------
class observer;

class subject {

    public:
        subject();
        ~subject();
        virtual void registerObserver(observer *obs);
        virtual void notifyObservers();
};

#endif //CS307_PROG1_SUBJECT_H
