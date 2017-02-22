#include <Wire.h>
#include "TSL2561.h"

TSL2561 tsl(TSL2561_ADDR_LOW); 
int RedLed = 23;
int BlueLed = 6;
int GreenLed = 5;
void setup(void) {
  Serial.begin(9600);
  
  if (tsl.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No sensor?");
    while (1);
  }
    
 
  tsl.setGain(TSL2561_GAIN_16X);  
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);  
  pinMode(RedLed, OUTPUT);  
  pinMode(BlueLed, OUTPUT); 
  pinMode(GreenLed, OUTPUT);   
}

void loop(void) {
  
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);     
  
  Serial.println(x, DEC);
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  long visible = full - ir;
  int intensite = visible/15;
  if (intensite > 255){
    intensite = 255;
  }
  analogWrite(BlueLed, intensite);
  analogWrite(RedLed, intensite);
  analogWrite(GreenLed, intensite);
  delay(100); 
}
