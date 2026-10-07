#include <Arduino.h>
#include <LEDController.h>

#define LED_PIN LED_BUILTIN

void ledSetup()
{
    pinMode(LED_PIN, OUTPUT);
}

void ledBlink(int delayTime)
{
    digitalWrite(LED_PIN, HIGH);
    delay(delayTime);

    digitalWrite(LED_PIN, LOW);
    delay(delayTime);
}
