#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    bool bme280I2CSetup();
    float readTemperatureI2C();

    
    static Adafruit_BME280 bme;

private:

   // Code here!

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;