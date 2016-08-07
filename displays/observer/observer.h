//====================================================================
// observer.h
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include <iostream>
//---------------------------------
#include "../subject/subjecct.h"
//---------------------------------

#ifndef CS307_PROG1_OBSERVER_H
#define CS307_PROG1_OBSERVER_H


class observer {
    public:
        observer();
        ~observer();
        virtual void updateate(subject* subjectPtr);

};


#endif //CS307_PROG1_OBSERVER_H
