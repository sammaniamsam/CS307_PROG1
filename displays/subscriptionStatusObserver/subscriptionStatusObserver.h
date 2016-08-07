//====================================================================
// subscriptionStatusObserver.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#ifndef CS307_PROG1_SUBSCRIPTIONSTATUSOBSERVER_H
#define CS307_PROG1_SUBSCRIPTIONSTATUSOBSERVER_H
//---------------------------------
#include "../observer/observer.h"
#include "../display/display.h"
//---------------------------------

class subscriptionStatusObserver: public observer {

    private:
        int subscriptionCount;

    public:
        subscriptionStatusObserver();
        ~subscriptionStatusObserver();
        void update(subject* subjectPtr);   /* virtual */
};

#endif //CS307_PROG1_SUBSCRIPTIONSTATUSOBSERVER_H
