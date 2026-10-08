#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include <BMEConstants.h>

class BMESPIInterface
{
public:
    BMESPIInterface();

    bool bme280SPISetup();
    float readTemperatureSPI();

private:
    Adafruit_BME280 bme;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
