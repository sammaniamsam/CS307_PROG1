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

    //pass user's file to data parser
    this->dataParserPtr->initDataParser(fileName);
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

    int air = 0, water = 0, earth = 0;

    //get air, earth and water sensor counts
    this->dataParserPtr->getSensorCounts(&earth, &air, &water);

    //create different sensors
    this->createAirSensors(air);
    this->createWaterSensors(water);
    this->createEarthSensors(earth);

    //create displays
    this->createDisplays();
};

//---------------------------------
//function: createDisplays()
//Creates the appropriate number of
//displays and passes each display
//to display's setDisplay() method
//---------------------------------
void simulation::createDisplays(){

    int count = this->dataParserPtr->getDisplayCount();

    for(int i=0; i < count; i++){

        //create display class instance
        display* displayPtr = this->SDFptr->createDisplayInstance();

        //create display node instance
        displayNode* displayNodePtr = new displayNode;

        //print message if parsing fails
        if(!this->dataParserPtr->getDisplayData(displayNodePtr->type,displayNodePtr->IDs,&displayNodePtr->IDCount))
            cout << "\n" << "Parsing for Display " << i << " failed" << "\n";

        else {

            //link display node to display class
            displayPtr->setDisplay(displayNodePtr);

            //link display class to sensor mount
            this->sensorMountPtr->attachDisplay(displayPtr);
        }
    }
};

//---------------------------------
//function: createAirSensors()
//---------------------------------
void simulation::createAirSensors(int& airCtr) {

    //if there are air sensors
    if (airCtr != 0) {

        //swap to air sensor factory
        this->ASFptr = airSensorFactory::getInstance();

        for (int i = 0; i < airCtr; i++) {

            //create sensorNode instance
            sensorNode *sensorNodePtr = new sensorNode;
            strcpy(sensorNodePtr->type, "Air");

            //print message if parsing fails
            if (!this->dataParserPtr->getSensorData(sensorNodePtr->type, sensorNodePtr->material,
            &sensorNodePtr->ID, sensorNodePtr->units, &sensorNodePtr->minVal, &sensorNodePtr->maxVal))
                cout << "\n" << "Parsing for Sensor " << i << " failed" << "\n";

            //initialize data
            sensorNodePtr->sensorData = 0;

            //create air sensor
            this->sensorTypePtr = this->ASFptr->createSensorInstance();
            this->sensorTypePtr->setSensor(sensorNodePtr);
            //---------------------------------
            //pass sensor to sensorMount function
            //that has an argument of sensorTypePtr
            //---------------------------------
        }
    }
}

//---------------------------------
//function: createWaterSensors()
//---------------------------------
void simulation::createWaterSensors(int& waterCtr) {

    //if there are water sensors
    if (waterCtr != 0) {

        //swap to water sensor factory
        this->ASFptr = waterSensorFactory::getInstance();

        for (int i = 0; i < waterCtr; i++) {

            //create sensorNode instance
            sensorNode *sensorNodePtr = new sensorNode;
            strcpy(sensorNodePtr->type, "Water");

            //print message if parsing fails
            if (!this->dataParserPtr->getSensorData(sensorNodePtr->type, sensorNodePtr->material,
            &sensorNodePtr->ID, sensorNodePtr->units, &sensorNodePtr->minVal, &sensorNodePtr->maxVal))
                cout << "\n" << "Parsing for Sensor " << i << " failed" << "\n";

            //initialize data
            sensorNodePtr->sensorData = 0;

            //create water sensor
            this->sensorTypePtr = this->ASFptr->createSensorInstance();
            this->sensorTypePtr->setSensor(sensorNodePtr);
            //---------------------------------
            //pass sensor to sensorMount function
            //that has an argument of sensorTypePtr
            //---------------------------------
        }
    }
}

//---------------------------------
//function: createEarthSensors()
//---------------------------------
void simulation::createEarthSensors(int& earthCtr) {

    //if there are earth sensors
    if (earthCtr != 0) {

        //swap to earth sensor factory
        this->ASFptr = earthSensorFactory::getInstance();

        for (int i = 0; i < earthCtr; i++) {

            //create sensorNode instance
            sensorNode *sensorNodePtr = new sensorNode;
            strcpy(sensorNodePtr->type, "Earth");

            //print message if parsing fails
            if (!this->dataParserPtr->getSensorData(sensorNodePtr->type, sensorNodePtr->material,
            &sensorNodePtr->ID, sensorNodePtr->units, &sensorNodePtr->minVal, &sensorNodePtr->maxVal))
                cout << "\n" << "Parsing for Sensor " << i << " failed" << "\n";

            //initialize data
            sensorNodePtr->sensorData = 0;

            //create earth sensor
            this->sensorTypePtr = this->ASFptr->createSensorInstance();
            this->sensorTypePtr->setSensor(sensorNodePtr);
            //---------------------------------
            //pass sensor to sensorMount function
            //that has an argument of sensorTypePtr
            //---------------------------------
        }
    }
}

//---------------------------------
//function: attachDevices()
//Attaches all sensors and display
//devices to sensor mount. Then,
//calls sensor mount funciton to
//link all sensors to the appropriate
//display devices.
//---------------------------------
void simulation::attachDevices(){

    //sensorMountPtr->attachDisplay(displayPtr);
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

    //create singleton of air sensor factory
    this->ASFptr = airSensorFactory::getInstance();
    //create singleton of water sensor factory
    this->ASFptr = waterSensorFactory::getInstance();
    //create singleton of earth sensor factory
    this->ASFptr = earthSensorFactory::getInstance();
    //create singleton of data parser
    this->dataParserPtr = EnviroSimDataParser::getInstance();
    //create singleton of simple display factory
    this->SDFptr = simpleDisplayFactory::getInstance();

    sensorPtr = new sensor;
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

        //need iterative solution to display
        //data for each display class
        //may want to add private display vector
        displayPtr->displayData();
        /*- - - - - - - - - - - - -*/
        std::cout << "\n\n\n";
        /*- - - - - - - - - - - - -*/
    }
};
