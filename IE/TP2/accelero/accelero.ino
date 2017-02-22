#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include "TSL2561.h"

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
TSL2561 tsl(TSL2561_ADDR_LOW); 
int RedLed = 23;
int BlueLed = 6;
int GreenLed = 5; 

void displaySensorDetails(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void setup(void) 
{
  Serial.begin(9600);
  
  if (tsl.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No sensor?");
    while (1);
  }
    
 
  tsl.setGain(TSL2561_GAIN_16X);  
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);    
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  pinMode(RedLed, OUTPUT);  
  pinMode(BlueLed, OUTPUT); 
  pinMode(GreenLed, OUTPUT);  
}

void loop(void) 
{
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);     
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  long visible = full - ir;
  int intensite = visible/15;
  if (intensite > 255){
    intensite = 255;
  }
  
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
 
  /* Display the results (acceleration is measured in m/s^2) */
  if (event.acceleration.x > 9 && event.acceleration.y < 2 && event.acceleration.z < 2){
    Serial.println ("couche sur la droite");
    analogWrite(BlueLed, intensite);
  }
  if (event.acceleration.x < -9 && event.acceleration.y < 2 && event.acceleration.z < 2){
    Serial.println ("couche sur la gauche");
    analogWrite(BlueLed, intensite);
  }
   if (event.acceleration.x < 2 && event.acceleration.y > 9 && event.acceleration.z < 2){
    Serial.println ("debout");
     analogWrite(RedLed, intensite);
  }
   if (event.acceleration.x < 2 && event.acceleration.y < -9  && event.acceleration.z < 2){
    Serial.println ("a l'envers");
     analogWrite(RedLed, intensite);
  }
     if (event.acceleration.x < 2 && event.acceleration.y < 2 && event.acceleration.z > 9){
    Serial.println ("couche sur le dos");
      analogWrite(GreenLed, intensite);
  }
     if (event.acceleration.x < 2 && event.acceleration.y < 2 && event.acceleration.z < -9){
    Serial.println ("couche sur le ventre");
      analogWrite(GreenLed, intensite);
  }
  
  
  
  delay(500);
  analogWrite(RedLed, 0);
  analogWrite(GreenLed, 0);
  analogWrite(BlueLed, 0);


}
