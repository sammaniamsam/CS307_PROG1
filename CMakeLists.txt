cmake_minimum_required(VERSION 3.5)
project(CS307_PROG1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
configure_file(sensorData.xml sensorData.xml COPYONLY)
set(SOURCE_FILES main.cpp sensors/sensor/sensor.h displays/display/display.h simulation/simulation.h sensor_mount/sensorMount.h data_parser/EnviroSimDataParser.h data_parser/EnviroSimDataParser.cpp sensors/sensor/sensor.cpp displays/display/display.cpp sensor_mount/sensorMount.cpp simulation/simulation.cpp displays/simpleDisplayFactory/simpleDisplayFactory.cpp displays/simpleDisplayFactory/simpleDisplayFactory.h sensors/abstractSensorFactory/abstractSensorFactory.cpp sensors/abstractSensorFactory/abstractSensorFactory.h sensors/sensorType/sensorType.h sensors/abstractSensorFactory/abstractSensorFactory.cpp sensors/sensorType/sensorType.cpp sensors/airSensorFactoy/airSensorFactory.cpp sensors/airSensorFactoy/airSensorFactory.h sensors/airSensor/airSensor.cpp sensors/airSensor/airSensor.h sensors/sensorNode.h sensors/waterSensorFactory/waterSensorFactory.cpp sensors/waterSensorFactory/waterSensorFactory.h sensors/waterSensor/waterSensor.cpp sensors/waterSensor/waterSensor.h)
add_executable(CS307_PROG1 ${SOURCE_FILES})