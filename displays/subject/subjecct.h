//====================================================================
// subject.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------

//---------------------------------

#ifndef CS307_PROG1_SUBJECCT_H
#define CS307_PROG1_SUBJECCT_H


class subject {

    public:
        subject();
        ~subject();
        virtual void registerObserver(observer *obs);
        virtual bool removeObserver(observer *obs);
        virtual void notifyObservers();
};


#endif //CS307_PROG1_SUBJECCT_H
