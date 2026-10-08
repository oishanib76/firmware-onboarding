#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include <BMEConstants.h>
#include <BMEI2CInterface.h>

bool BMEI2CInterface::bme280I2CSetup()
{
    Wire.begin();

    if (!bme.begin(BMEConstants::BME_I2C_ADDRESS))
    {
        Serial.println("Could not find BME280!");
        return false;
    }

    Serial.println("BME280 found!");
    return true;
}

float BMEI2CInterface::readTemperatureI2C()
{
    return bme.readTemperature();
}