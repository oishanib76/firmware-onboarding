#include <Arduino.h>

#include <BMEConstants.h>
#include <BMEI2CInterface.h>
#include <BMEI2CInterface.cpp>
#include <LEDController.h>
#include <LEDController.cpp>

#define ERROR_LED LED_BUILTIN

int temperatureToDelay(float temperature)
{
    if (temperature < MIN_TEMPERATURE)
    {
        temperature = MIN_TEMPERATURE;
    }

    if (temperature > MAX_TEMPERATURE)
    {
        temperature = MAX_TEMPERATURE;
    }

    return map(
        (long)temperature,
        MIN_TEMPERATURE,
        MAX_TEMPERATURE,
        SLOW_BLINK_DELAY,
        FAST_BLINK_DELAY
    );
}

void setup()
{
    Serial.begin(9600);

    bme280I2CSetup();
    ledSetup();

    if (!bme280I2CSetup())
    {
        Serial.println("BME280 setup failed!");
        while (true) {
            digitalWrite(ERROR_LED, HIGH);
            delay(100);
            digitalWrite(ERROR_LED, LOW);
            delay(100);
        }
    }

}

void loop()
{
    float temperature = readTemperatureI2C();

    int delayTime = temperatureToDelay(temperature);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Delay: ");
    Serial.println(delayTime);

    ledBlink(delayTime);
}
