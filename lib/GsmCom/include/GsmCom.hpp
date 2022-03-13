#include "gsm_config.h"
#include <TinyGsmClient.h>

// Declate the GsmCom class
class GsmCom
{
    // SIM card and Network information
    char apn[];      // Your APN
    char gprsUser[]; // User
    char gprsPass[]; // Password
    char simPIN[];   // SIM card PIN code, if any

    // Initialize the modem
    TinyGsm modem(SerialAT);

    // Initialize TinyGsmClient
    TinyGsmClient client(modem);

public:
    // Default constructor to set the APN, GPRS user, password and simPIN to empty strings
    GsmCom();

    // Constructor to set the APN, GPRS user, password and simPIN with default values as empty strings
    GsmCom(const char *apn, const char *gprsUser, const char *gprsPass, const char *simPIN);

    // function to bootstrap the modem
    bool bootstrap();

    // function to restart the modem 
    void restart();

    // function to send telemetry data to the server
    bool sendData(const char *server, const char *port, const char *data);

private:
    // function to connect to the network
    bool connectNetwork();

    // function to connect to the GPRS network
    bool connectGPRS();

    // fuction to disconnect from GPRS network
    bool disconnectGPRS();
};