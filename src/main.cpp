#include "globals.h"
#include <GsmCom.hpp>
#include "utilities.h"

// include TinyGSM library
#include <TinyGsmClient.h>

TinyGsm* modem;
TinyGsmClient* client;

void setup()
{
    
    // Set console baud rate
    SerialMon.begin(115200);
    delay(10);

    // instantiate TinyGsm and TinyGsmClient object
    TinyGsm* modem = new TinyGsm(SerialAT);
    TinyGsmClient* client = new TinyGsmClient(*modem);

    // Keep power when running from battery
    Wire.begin(I2C_SDA, I2C_SCL);
    bool isOk = setPowerBoostKeepOn(1);
    SerialMon.println(String("IP5306 KeepOn ") + (isOk ? "OK" : "FAIL"));

    GsmCom gsmComDevice();
}

void loop()
{
}