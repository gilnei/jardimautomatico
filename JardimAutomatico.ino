#define SW_VERSION "   SW Ver. 3.0" // SW version will appears at innitial LCD Display
#include "definicoes.h"       // Project definitions
#include "credenciais.h"


/* ESP & Blynk */
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>

WidgetLED PUMPa(V5); // Echo signal to Actuators Tab at Blynk App

/* DHT22*/
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);


/*HTTP CLIENT*/
#include <ESP8266HTTPClient.h>

 

/* TIMER */
//#include <SimpleTimer.h>
BlynkTimer CoreTimer;


/* OLED */
#include <ACROBOTIC_SSD1306.h> // library for OLED: SCL ==> D1; SDA ==> D2
#include <SPI.h>
#include <Wire.h>



void setup() {

   if (DEBUG_CONSOLE) {
      Serial.begin(115200);
      Serial.println("Debug mode on ");
    }
    
  pinMode(relayPin, OUTPUT); // initialize pin as OUTPUT
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input


    dht.begin();
 
    Blynk.config(auth, server, port);
    Blynk.connectWiFi(ssid, pass);
    Blynk.connect(); 
    //Blynk.begin(auth);  
    digitalWrite(trigPin, LOW);
    
    startTimers();
  

}

void loop() {
  CoreTimer.run(); // Initiates SimpleTimer
  Blynk.run();

}

BLYNK_WRITE(V5) // Pump remote control
{

   int i=param.asInt();
   
  if (DEBUG_CONSOLE) {
      Serial.begin(115200);
      Serial.println("Blynk push?");
       Serial.println(i);
    }
    
 /*
  if (i==1) 
  {
 
 turnPumpOn();
 
  }else{
    turnPumpOff();
  }*/


  pumpStatus=!pumpStatus;
  
  
}
