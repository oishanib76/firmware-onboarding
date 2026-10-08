#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BME280.h>

#include <BMEConstants.h>
#include <BMESPIInterface.h>

BMESPIInterface::BMESPIInterface()
    : bme(10)
{
}

bool BMESPIInterface::bme280SPISetup()
{
    SPI.begin();

    if (!bme.begin())
    {
        Serial.println("Could not find BME280 using SPI!");
        return false;
    }

    Serial.println("BME280 found!");
    return true;
}

float BMESPIInterface::readTemperatureSPI()
{
    return bme.readTemperature();
}