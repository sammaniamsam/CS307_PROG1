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
    int			m_iNumSensors; // Number of sensors in the file
    int			m_iNumDisplays; // Number of display devices in the file
    int			m_iNextSensor; // Next sensor number to read
    int			m_iNextDisplay; // Next display number to read
    char        m_sFileName[64]; // Data file

public:
    EnviroSimDataParser(char *fileName);
    ~EnviroSimDataParser();
    int getSensorCount();
    int getDisplayCount();
    bool getSensorData(char *type, char *material, int *ID,
                       char *units, double *minVal, double *maxVal);
    bool getDisplayData(char *type, int *IDs, int *IDCount);

private:
    bool getNextLine(char *buffer, int n);
};

#endif