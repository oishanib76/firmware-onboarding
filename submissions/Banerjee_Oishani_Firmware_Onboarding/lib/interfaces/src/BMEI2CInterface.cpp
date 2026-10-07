#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include <BMEConstants.h>
#include <BMEI2CInterface.h>

static Adafruit_BME280 bme;

void bme280I2CSetup()
{
    Wire.begin();

    if (!bme.begin(BME_I2C_ADDRESS))
    {
        Serial.println("Could not find BME280!");
        while (1);
    }
}

float readTemperatureI2C()
{
    return bme.readTemperature();
}
