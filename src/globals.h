#include <Arduino.h>
#include <Wire.h>

// Set serial Monitor for Debugging
#define SerialMon Serial
// Set serial for AT commands (to the module)
#define SerialAT Serial1

#define I2C_SDA 21
#define I2C_SCL 22