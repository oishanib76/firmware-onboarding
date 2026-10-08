#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t BME_I2C_ADDRESS = 0x76;

    constexpr uint8_t BME_SPI_CS_PIN = 10;

    constexpr float MIN_TEMPERATURE = 26.0;
    constexpr float MAX_TEMPERATURE = 30.0;

    constexpr unsigned long SLOW_BLINK_DELAY = 1000;
    constexpr unsigned long FAST_BLINK_DELAY = 100;
}
