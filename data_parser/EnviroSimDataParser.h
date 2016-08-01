//====================================================================
// EnviroSimDataParser.h
// Interface file for the data parser.
// Author: Dr. Rick Coleman
//====================================================================
#ifndef ENVIROSIMDATAPARSER_H
#define ENVIROSIMDATAPARSER_H

#include <iostream>
#include <fstream>

using namespace std;

class EnviroSimDataParser
{
private:
    ifstream	*inFile;	// Sensor definition file
    int			m_iNumEarthSensors; // Number of earth sensors in the file
    int			m_iNumAirSensors; // Number of air sensors in the file
    int			m_iNumWaterSensors; // Number of Water sensors in the file
    int			m_iNumDisplays; // Number of display devices in the file
    int			m_iNextEarthSensor; // Next earth sensor number to read
    int			m_iNextAirSensor; // Next air sensor number to read
    int			m_iNextWaterSensor; // Next water sensor number to read
    int			m_iNextDisplay; // Next display number to read
    char        m_sFileName[64]; // Data file


public:
    ~EnviroSimDataParser();
    static EnviroSimDataParser *getInstance();
    void initDataParser(char *fileName);
    void getSensorCounts(int *earth, int *air, int *water);
    int getDisplayCount();
    bool getSensorData(char *type, char *material, int *ID,
                       char *units, double *minVal, double *maxVal);
    bool getDisplayData(char *type, int *IDs, int *IDCount);

private:
    EnviroSimDataParser();	// Private constructor for singleton
    bool getNextLine(char *buffer, int n);
};

#endif