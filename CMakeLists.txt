cmake_minimum_required(VERSION 3.5)
project(CS307_PROG1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
configure_file(sensorData.xml sensorData.xml COPYONLY)
set(SOURCE_FILES main.cpp sensor/sensor.h display/display.h simulation/simulation.h sensor_mount/sensorMount.h data_parser/EnviroSimDataParser.h data_parser/EnviroSimDataParser.cpp sensor/sensor.cpp display/display.cpp sensor_mount/sensorMount.cpp simulation/simulation.cpp)
add_executable(CS307_PROG1 ${SOURCE_FILES})