#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include <BMEConstants.h>
#include <BMEI2CInterface.h>

BMEI2CInterfaceInstance::create();


bool bme280I2CSetup()
{
    Wire.begin();

    if (!bme.begin(0x76))
    {
        Serial.println("Could not find BME280!");
        return false;
    }
    return true;
}

float readTemperatureI2C()
{
    return bme.readTemperature();
}
