//====================================================================
// subject.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================

#include "subjecct.h"

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//-------------------------------
//Constructor
//-------------------------------
subject::subject() { }

//-------------------------------
//Destructor
//-------------------------------
subject::~subject() { }

//-------------------------------
// Add an observer
//-------------------------------
void subject::registerObserver(observer *obs) { }

//-------------------------------
// Remove an observer
//-------------------------------
bool subject::removeObserver(observer *obs) { }

//-------------------------------
// Notify all observers
//-------------------------------
void subject::notifyObservers() { }