#include "gsm_config.h"
#include <globals.h>

// Declate the GsmCom class
class GsmCom
{
    TinyGsm* modem;
    TinyGsmClient* client;

public:
    // Default constructor to pass TinyGsm and TinyGsmClient object
    GsmCom(TinyGsm* modem, TinyGsmClient* client);

    // function to bootstrap the modem
    bool bootstrap();

    // function to connect to the network
    bool connectNetwork();
    
    // function to restart the modem 
    void restart();

    // function to send telemetry data to the server
    bool sendData(const char *server, const char *port, const char *data);

private:
    // function to connect to the GPRS network
    bool connectGPRS();

    // fuction to disconnect from GPRS network
    bool disconnectGPRS();
};