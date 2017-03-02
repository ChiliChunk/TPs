// rf22_client.pde
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messageing client
// with the RH_RF22 class. RH_RF22 class does not provide for addressing or
// reliability, so you should only use RH_RF22 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example rf22_server
// Tested on Duemilanove, Uno with Sparkfun RFM22 wireless shield
// Tested on Flymaple with sparkfun RFM22 wireless shield
// Tested on ChiKit Uno32 with sparkfun RFM22 wireless shield

#include <SPI.h>
#include <RH_RF22.h>

// Singleton instance of the radio driver
RH_RF22 rf22 (SS,9);
uint8_t data[] = {
    0x5A,           /* entête */
    0x01,           /* numéro de protocole */
    0x00,           /* numéro de séquence */
    0x00, 0x56,     /* adresse source */
    0x00, 0x02,     /* numéro d'application */
    0x1c,  0x00, 0x00,  0x82,  0x42 };
void setup() 
{
  SPI.setSCK(14);
  Serial.begin(9600);
  if (!rf22.init())
    Serial.println("init failed");
}

void loop()
{
  Serial.println("Sending to rf22_server");
  // Send a message to rf22_server
  
  rf22.send(data, sizeof(data));
  rf22.waitPacketSent();
  data[2]++;
  delay(5000);
}

