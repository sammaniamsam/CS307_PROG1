//====================================================================
// simulation.cpp
// Programming Assignment 1 : Sensor Simulation
// Author: Samuel Sikes
// Date: June 2016
// This program is entirely my own work
//====================================================================
#include "simulation.h"

//---------------------------------
//---------------------------------
//--------PRIVATE METHODS----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: simulationDescription()
//Displays a description of the
//program.
//---------------------------------
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

//---------------------------------
//function: getFile()
//Prompts user to enter the name
//of the file that they want parsed.
//---------------------------------
void simulation::getFile(){

    char fileName[64];
    std::cout << "Please enter the name of the simulation data file then press Enter: ";
    std::cin >> fileName;
    dataParserPtr = new EnviroSimDataParser(fileName);
};

//---------------------------------
//function: buildDevices()
//Gets the number of sensor and
//display devices to create and
//passes those counts to the create
//functions for both displays and
//sensors. Then, deletes instance of
//data parser.
//---------------------------------
void simulation::buildDevices(){

    //use new data parser to get display counts (air, water, earth)
    int sensorCount = dataParserPtr->getSensorCount();

    //use new data parser to get display count
    int displayCount = dataParserPtr->getDisplayCount();

    this->createDisplays(displayCount);
    this->createSensors(sensorCount);

    delete dataParserPtr; dataParserPtr = NULL;
};

//---------------------------------
//function: createDisplays()
//Creates the appropriate number of
//displays and passes each display
//to display's getDisplay() method
//---------------------------------
void simulation::createDisplays(int& count){

    //create singleton
    simpleDisplayFactory* SDFptr = simpleDisplayFactory::getInstance();

    for(int i=0; i < count; i++){
        //create display class instance
        display* displayPtr = SDFptr->createDisplayInstance();
        //create display node instance
        displayNode* displayNodePtr = new displayNode;
        //print message if parsing fails
        if(!dataParserPtr->getDisplayData(displayNodePtr->type,displayNodePtr->IDs,&displayNodePtr->IDCount))
            cout << "\n" << "Parsing for Display " << i << " failed" << "\n";
        else {
            displayPtr->getDisplay(displayNodePtr);
            //link display node to display class
            //link display class to sensor mount
        }
    }
};

//---------------------------------
//function: createSensors()
//Creates the appropriate number of
//sensors and passes each sensor
//to sensor's getSensor() method
//---------------------------------
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

//---------------------------------
//function: attachDevices()
//Attaches all sensors and display
//devices to sensor mount. Then,
//calls sensor mount funciton to
//link all sensors to the appropriate
//display devices.
//---------------------------------
void simulation::attachDevices(){

    sensorMountPtr->attachDisplays(displayPtr->relayDisplayData());
    sensorMountPtr->attachSensors(sensorPtr->relaySensorData());
    if(!sensorMountPtr->linkSensorsToDisplays())
        std::cout << "\n" << "Linking Sensors To Displays FAILED" << "\n";
};

//---------------------------------
//---------------------------------
//--------PUBLIC METHODS-----------
//---------------------------------
//---------------------------------

//---------------------------------
//function: simulation()
//dynamically creates instances of
//sensor, display, and sensor mount
//---------------------------------
simulation::simulation(){

    sensorPtr = new sensor;
    displayPtr = new display;
    sensorMountPtr = new sensorMount;
};

//---------------------------------
//function: ~simulation()
//deallocates memory for: display,
//sensor, and sensor mount
//sets all private pointers to NULL
//---------------------------------
simulation::~simulation(){

    delete sensorPtr; sensorPtr = NULL;
    delete displayPtr; displayPtr = NULL;
    delete sensorMountPtr; sensorMountPtr = NULL;
};

//---------------------------------
//function: runSimulation()
//calls appropriate simulation
//methods. Then, generates sensor
//data and displays it every 5
//seconds
//---------------------------------
void simulation::runSimulation() {

    this->simulationDescription();
    this->getFile();
    this->buildDevices();
    this->attachDevices();
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
