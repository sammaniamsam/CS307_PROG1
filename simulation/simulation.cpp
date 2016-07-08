/*******************************************************************
* simulation.cpp
* Programming Assignment 1 : Sensor Simulation
* Author: Samuel Sikes
* Date: June 2016
* This program is entirely my own work
*******************************************************************/
#include "simulation.h"
/********************************/
/********************************/
/*********PRIVATE METHODS********/
/********************************/
/***********************************/
void simulation::simulationDescription(){

    for (int i = 0; i < 60; i++)
        std::cout << "=";

    std::cout <<  "\n" << "|" << std::setw(52) <<
    "ENVIRONMENTAL SENSORS SIMULATION DEMONSTRATION" <<
    std::setw(7) << "|" << "\n" <<
    "|" << std::setw(46) <<
    "CS 307 -- Programming Assignment 1" <<
    std::setw(13) << "|" << "\n";

    for (int i = 0; i < 60; i++)
        std::cout << "=";
    std::cout << "\n\n";
};
/***********************************/
void simulation::getFile(){

    char fileName[64];
    std::cout << "Please enter the name of the simulation data file then press Enter: ";
    std::cin >> fileName;
    dataParserPtr = new EnviroSimDataParser(fileName);
};
/***********************************/
void simulation::buildDevices(){

    int sensorCount = dataParserPtr->getSensorCount();
    int displayCount = dataParserPtr->getDisplayCount();
    createDisplays(displayCount);
    createSensors(sensorCount);

    delete dataParserPtr; dataParserPtr = NULL;
};
/***********************************/
void simulation::createDisplays(int& count){

    for(int i=0; i < count; i++){
        displayNode* displayNodePtr = new displayNode;
        if(!dataParserPtr->getDisplayData(displayNodePtr->type,displayNodePtr->IDs,&displayNodePtr->IDCount))
            cout << "\n" << "Parsing for Display " << i << " failed" << "\n";
        displayPtr->getDisplay(displayNodePtr);
    }
};
/***********************************/
void simulation::createSensors(int& count){

    for(int i=0; i < count; i++){
        sensorNode* sensorNodePtr = new sensorNode;
        if(!dataParserPtr->getSensorData(sensorNodePtr->type,sensorNodePtr->material,&sensorNodePtr->ID,
                                         sensorNodePtr->units,&sensorNodePtr->minVal,&sensorNodePtr->maxVal))
            cout << "\n" << "Parsing for Sensor " << i << " failed" << "\n";
        sensorNodePtr->sensorData = 0;
        sensorPtr->getSensor(sensorNodePtr);
    }
};
/***********************************/
void simulation::attachDevices(){

    sensorMountPtr->attachDisplays(displayPtr->relayDisplayData());
    sensorMountPtr->attachSensors(sensorPtr->relaySensorData());
    if(!sensorMountPtr->linkSensorsToDisplays())
        std::cout << "\n" << "Linking Sensors To Displays FAILED" << "\n";
};
/********************************/
/********************************/
/*********PUBLIC METHODS*********/
/********************************/
/***********************************/
simulation::simulation(){

    sensorPtr = new sensor;
    displayPtr = new display;
    sensorMountPtr = new sensorMount;
};
/***********************************/
simulation::~simulation(){

    delete sensorPtr; sensorPtr = NULL;
    delete displayPtr; displayPtr = NULL;
    delete sensorMountPtr; sensorMountPtr = NULL;
};
/***********************************/
void simulation::runSimulation() {

    simulationDescription();
    getFile();
    buildDevices();
    attachDevices();
    sensorMountPtr->displayConnectedDevices();
    /*- - - - - - - - - - - - -*/
    std::cout << "\n\n\n" << "Beginning simulation run..." << "\n\n";
    for (int i = 0; i < 20; i++)
        std::cout << "=";
    std::cout << " Running simulation ";
    for (int i = 0; i < 20; i++)
        std::cout << "=";
    std::cout << "\n\n" << "Press Ctrl-c to terminate the simulation" << "\n\n";
    /*- - - - - - - - - - - - -*/
    while(true){
        usleep(5000000);
        /*- - - - - - - - - - - - -*/
        for (int i = 0; i < 60; i++)
            std::cout << "=";
        std::cout << "\n\n";
        /*- - - - - - - - - - - - -*/
        sensorPtr->updateSensors();
        displayPtr->displayData();
        /*- - - - - - - - - - - - -*/
        std::cout << "\n\n\n";
        /*- - - - - - - - - - - - -*/
    }
};
