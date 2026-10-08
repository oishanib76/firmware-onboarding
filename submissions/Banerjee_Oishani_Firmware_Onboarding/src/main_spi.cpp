#include <Arduino.h>

#include <BMEConstants.h>
#include <BMESPIInterface.h>
#include <LEDController.h>

#define ERROR_LED LED_BUILTIN

int temperatureToDelay(float temperature)
{
    if (temperature < BMEConstants::MIN_TEMPERATURE)
    {
        temperature = BMEConstants::MIN_TEMPERATURE;
    }

    if (temperature > BMEConstants::MAX_TEMPERATURE)
    {
        temperature = BMEConstants::MAX_TEMPERATURE;
    }

    return map(
        (long)temperature,
        (long)BMEConstants::MIN_TEMPERATURE,
        (long)BMEConstants::MAX_TEMPERATURE,
        BMEConstants::SLOW_BLINK_DELAY,
        BMEConstants::FAST_BLINK_DELAY
    );
}

void setup()
{
    Serial.begin(9600);

    pinMode(ERROR_LED, OUTPUT);
    ledSetup();

    BMESPIInterfaceInstance::create();

    if (!BMESPIInterfaceInstance::instance().bme280SPISetup())
    {
        Serial.println("BME280 setup failed!");

        while (true)
        {
            digitalWrite(ERROR_LED, HIGH);
            delay(100);

            digitalWrite(ERROR_LED, LOW);
            delay(100);
        }
    }
}

void loop()
{
    float temperature =
        BMESPIInterfaceInstance::instance().readTemperatureSPI();

    int delayTime = temperatureToDelay(temperature);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C | Delay: ");
    Serial.println(delayTime);

    ledBlink(delayTime);
}
