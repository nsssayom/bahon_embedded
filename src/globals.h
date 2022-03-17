#ifndef GLOBALS_H
#define GLOBALS_H

// Set serial Monitor for Debugging
#define SerialMon Serial
// Set serial for AT commands (to the module)
#define SerialAT Serial1


#define I2C_SDA 21
#define I2C_SCL 22

// TTGO T-Call pin definitions for built-in SIM800
#define MODEM_RST 5
#define MODEM_PWKEY 4
#define MODEM_POWER_ON 23
#define MODEM_TX 27
#define MODEM_RX 26

// Configure TinyGSM library
#define TINY_GSM_MODEM_SIM800   // Modem is SIM800
#define TINY_GSM_RX_BUFFER 1024 // Set RX buffer to 1Kb


// Your GPRS credentials (leave empty, if missing)
const char apn[] = "";      // Your APN
const char gprsUser[] = ""; // User
const char gprsPass[] = ""; // Password
const char simPIN[] = "";   // SIM card PIN code, if any

// Server details
const char server[] = "vsh.pp.ua";
const char resource[] = "/TinyGSM/logo.txt";
const int port = 80;

#include <Arduino.h>

#endif