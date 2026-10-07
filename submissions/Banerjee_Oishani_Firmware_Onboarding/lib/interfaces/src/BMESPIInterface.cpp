#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BME280.h>

#include <BMEConstants.h>
#include <BMESPIInterface.h>

static Adafruit_BME280 bme;

void bme280SPISetup()
{
    if (!bme.begin(BME_SPI_CS_PIN))
    {
        Serial.println("Could not find BME280!");
        while (1);
    }
}

float readTemperatureSPI()
{
    return bme.readTemperature();
}
