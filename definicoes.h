 /*
  * se estiver usando nodemcu 0.9 - lolin, manter esta parte comentada
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
*/

// DISTANCE 
const int trigPin =  2;  //D4
const int echoPin =  0;  //D3
long duration;
int distance;
const int minDistance = 20;
 


// RELAY
int relayPin = 14; // the input to the relay pin
#define PUMP_PIN D5              //PUMP (Red LED)
boolean pumpStatus = 1;

//OLED
#define OLED_DISPLAY_DATA 5L

// DHT
#define READ_DHT_REFRESH 10L

/* TIMER */
#define FEEDBACK_REFRESH   20L  // definitions in seconds
#define READSENSOR_REFRESH 10L
#define PUSH_BLYNK_REFRESH 2L // keep +2 sec from read sensor

#define DEBUG_CONSOLE     1
#define BLYNK_UPDATE      2L      
int timerID;


/* Automatic Control Parameters Definition */
#define DRY_SOIL      10
#define WET_SOIL      55
#define COLD_TEMP     12
#define HOT_TEMP      27
#define TIME_PUMP_ON  10
#define TIME_LAMP_ON  15


 
/* DHT22*/
#define DHTPIN D6  
#define DHTTYPE DHT22 
float airHum = 0;
float airTemp = 0;
 
 
 
 
