//====================================================================
// observer.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#ifndef CS307_PROG1_OBSERVER_H
#define CS307_PROG1_OBSERVER_H
//---------------------------------
#include "../subject/subject.h"
//---------------------------------
class subject;

class observer {
    public:
        observer();
        ~observer();
        virtual void update(subject* subjectPtr);
};

#endif //CS307_PROG1_OBSERVER_H
