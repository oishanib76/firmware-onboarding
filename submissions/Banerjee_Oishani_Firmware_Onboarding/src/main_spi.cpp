#include <Arduino.h>

#include <BMEConstants.h>
#include <BMESPIInterface.h>
#include <LEDController.h>

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

    ledSetup();
    bme280SPISetup();
}

void loop()
{
    float temperature = readTemperatureSPI();

    int delayTime = temperatureToDelay(temperature);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Delay: ");
    Serial.println(delayTime);

    ledBlink(delayTime);
}
