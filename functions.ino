/* FUNCTIONS */

/***************************************************
* Receive Commands and act on actuators
****************************************************/
void aplyCmd()
{
  if (pumpStatus == 1) 
  {
    Blynk.notify("Pumper: Warning ==>> Pump ON"); 
    turnPumpOn();
  }
  else
      {
         Blynk.notify("Pumper: Warning ==>> Pump OFF"); 
        turnPumpOff();
      }
  
}


void turnPumpOn(void){
  PUMPa.on();
  digitalWrite(relayPin, HIGH); // turn relay on

}

void turnPumpOff(void){
   digitalWrite(relayPin, LOW); // turn relay off
  PUMPa.off();

}


void getSensor(void){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  
  Serial.print("Distance: ");
  Serial.println(distance);

  // reached the limit, trigger the pump
  if (distance<=minDistance)
    turnPumpOn();
  else  turnPumpOff();
 

}

/***************************************************
 * Get DHT data
 **************************************************/
void getDhtData(void)
{
  float tempIni = airTemp;
  float humIni = airHum;
  airTemp = dht.readTemperature();
  airHum = dht.readHumidity();
  if (isnan(airHum) || isnan(airTemp))   // Check if any reads failed and exit early (to try again).
  {
    Serial.println("Failed to read from DHT sensor!");
    airTemp = tempIni;
    airHum = humIni;
    return;
  }

 /* if (debugSensors==1){
    Serial.begin(115200);
    Serial.println("ait temp ");
    Serial.println( airTemp);
    Serial.println("ait hum ");
    Serial.println(airHum);
  }
  */
  

  
}

/***************************************************
* feedback poing
****************************************************/

void pushBlynk(void){
  
  // convert distance to % --> the lower the fullest it is
  /*
   * 
   * map(value, fromLow, fromHigh, toLow, toHigh)
   * 
   * value: the number to map.
    fromLow: the lower bound of the value’s current range.
    fromHigh: the upper bound of the value’s current range.
    toLow: the lower bound of the value’s target range.
    toHigh: the upper bound of the value’s target range.
   */
  int waterTank = map(distance, minDistance, 48, 0, 100); 
  Blynk.virtualWrite(10, (100-waterTank)); //virtual pin V10
  //Blynk.virtualWrite(10, (distance)); //virtual pin V10
  

  Blynk.virtualWrite(11,(int)airTemp); //virtual pin V11
  Blynk.virtualWrite(12, (int)airHum); // virtual pin V12
  
}
/***************************************************
* Starting Timers
****************************************************/
void startTimers(void)
{
   Serial.println("Timer on");

 // timerID = CoreTimer.setInterval(FEEDBACK_REFRESH*1000, feedback);
 CoreTimer.setInterval(READSENSOR_REFRESH*1000, getSensor);

// oled 
  //CoreTimer.setInterval(OLED_DISPLAY_DATA*1000, displayData);

  CoreTimer.setInterval(PUSH_BLYNK_REFRESH*1000, pushBlynk);
  
  CoreTimer.setInterval(READ_DHT_REFRESH*1000, getDhtData);
  
  
  
  
}
