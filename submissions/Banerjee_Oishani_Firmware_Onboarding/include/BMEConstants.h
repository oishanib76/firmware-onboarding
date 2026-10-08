#pragma once
#include <Arduino.h>

namespace BMEConstants
{
#ifndef BME_CONSTANTS_H
#define BME_CONSTANTS_H

#define BME_I2C_ADDRESS 0x76

#define BME_SPI_CS_PIN 10

#define MIN_TEMPERATURE 26
#define MAX_TEMPERATURE 30

#define SLOW_BLINK_DELAY 1000
#define FAST_BLINK_DELAY 100

#endif
}
