#include<GsmCom.hpp>

// Implement the GsmCom class
// Default constructor to set the APN, GPRS user, password and simPIN to empty strings

GsmCom::GsmCom()
{
    // Set the APN, GPRS user, password and simPIN to empty strings
    apn[0] = '\0';
    gprsUser[0] = '\0';
    gprsPass[0] = '\0';
    simPIN[0] = '\0';
}

// Constructor to set the APN, GPRS user, password and simPIN with default values as empty strings
GsmCom::GsmCom(const char *apn, const char *gprsUser, const char *gprsPass, const char *simPIN)
{
    // Set the APN, GPRS user, password and simPIN
    strcpy(this->apn, apn);
    strcpy(this->gprsUser, gprsUser);
    strcpy(this->gprsPass, gprsPass);
    strcpy(this->simPIN, simPIN);
}

// function to bootstrap the modem
bool GsmCom::bootstrap()
{
    // Set-up modem reset, enable, power pins
    pinMode(MODEM_PWKEY, OUTPUT);
    pinMode(MODEM_RST, OUTPUT);
    pinMode(MODEM_POWER_ON, OUTPUT);

    digitalWrite(MODEM_PWKEY, LOW);
    digitalWrite(MODEM_RST, HIGH);
    digitalWrite(MODEM_POWER_ON, HIGH);

    // Set GSM module baud rate and UART pins
    SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
    delay(3000);

    // Restart takes quite some time
    // To skip it, call init() instead of restart()
    SerialMon.println("Initializing modem...");
    modem.restart();
    // Or, use modem.init() if you don't need the complete restart

    String modemInfo = modem.getModemInfo();
    SerialMon.print("Modem: ");
    SerialMon.println(modemInfo);

    // Unlock your SIM card with a PIN if needed
    if (strlen(simPIN) && modem.getSimStatus() != 3)
    {
        if (modem.simUnlock(simPIN))
        {
            SerialMon.println("SIM card unlocked");
        }
        else
        {
            SerialMon.println("SIM card unlock failed");
            return false;
        }
    }
    else{
        SerialMon.println("SIM card is already unlocked");
    }
    return true;
}

// function to connect to the network
bool GsmCom::connectNetwork()
{
    SerialMon.print("Waiting for network...");
    if (!modem.waitForNetwork(240000L))
    {
        SerialMon.println(" failed. Retrying...");
        delay(2000);
        return false;
    }
    SerialMon.println(" OK");

    if (modem.isNetworkConnected())
    {
        SerialMon.println("Connected to network");
    }
    return true;
}

// function to connect to the GPRS network
bool GsmCom::connectGPRS()
{
    SerialMon.print("Connecting to APN: ");
    SerialMon.print(apn);
    if (!modem.gprsConnect(this->apn, this->gprsUser, this->gprsPass))
    {
        SerialMon.println(" failed. Retrying...");
        delay(10000);
        return false;
    }
    SerialMon.println(" OK");
    SerialMon.println("GPRS connection established");
    return true;
}

// function to disconnect from the GPRS network
bool GsmCom::disconnectGPRS()
{
    SerialMon.println("Disconnecting from GPRS network...");
    if (!modem.gprsDisconnect())
    {
        SerialMon.println(" failed. Retrying...");
        delay(10000);
        return false;
    }
    SerialMon.println(" OK");
    return true;
}

// function to restart the modem
void GsmCom::restart()
{
    SerialMon.println("Restarting modem...");
    modem.restart();
    SerialMon.println("Modem restarted");

    this->bootstrap();
    this->connectNetwork();
}

// function to send telemetry data to the server
bool GsmCom::sendData(const char *server, const char *port, const char *data)
{
    // Connect to the GPRS network
    if (!this->connectGPRS())
    {
        SerialMon.println("Failed to connect to GPRS network");
        return false;
    }

    // Print debug information
    SerialMon.print("Sending data to ");
    SerialMon.print(server);
    SerialMon.print(":");
    SerialMon.println(port);
   


    return true;
}