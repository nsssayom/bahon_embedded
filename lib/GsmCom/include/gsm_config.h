#include <globals.h>

// TTGO T-Call pin definitions for built-in SIM800
#define MODEM_RST 5
#define MODEM_PWKEY 4
#define MODEM_POWER_ON 23
#define MODEM_TX 27
#define MODEM_RX 26


// Configure TinyGSM library
#define TINY_GSM_MODEM_SIM800   // Modem is SIM800
#define TINY_GSM_RX_BUFFER 1024 // Set RX buffer to 1Kb


// Server details
const char server[] = "vsh.pp.ua";
const char resource[] = "/TinyGSM/logo.txt";
const int port = 80;

