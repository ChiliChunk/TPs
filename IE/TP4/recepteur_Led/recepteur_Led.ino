// This code is an example for using the SimpleWiNo library.
// See comments in the code for help on usage

#include <SPI.h>
#include <RH_RF22.h>
#include <SimpleWiNo.h>

#define MAX_DATA_LEN 64 // Maximum payload 
#define DESTINATION_ADDRESS 0xFFFF // 0xFFFF is the broadcast address

SimpleWiNo wino;

uint16_t srcAddr;
uint8_t len;
unsigned char data[MAX_DATA_LEN];
int RedLed = 23;
int BlueLed = 6;
int GreenLed = 5;
uint8_t intensiteRed = 100;
uint8_t intensiteGreen = 100;
uint8_t intensiteBlue = 100;
void setup() {
  
  pinMode(RedLed, OUTPUT);  
  pinMode(BlueLed, OUTPUT); 
  pinMode(GreenLed, OUTPUT);

  // Init SimpleWiNo
  wino.init();
  
  // Set SimpleWiNo properties
  wino.set(NODE_SHORT_ADDRESS, 1); // WiNo address
  wino.set(NODE_PANID, 0xFECA); // Logical isolation in the PAN
  wino.set(NODE_TXPOWER, 4); // Transmit power (0-7)
  wino.set(NODE_CHANNEL, 10); // Radio channel (0-17)

  // Init Serial and print some informations
  Serial.begin(115200);
  Serial.print("My PANid is 0x");
  Serial.println(wino.get(NODE_PANID), HEX);
  Serial.print("My address is 0x");
  Serial.println(wino.get(NODE_SHORT_ADDRESS), HEX);
}


void loop() {
    wino.process();
  // Check if something has been received by MAC layer. Print it on Serial
  if ( wino.recv(&srcAddr, &data[0], &len )){
    int i;
    for (i = 0 ; i < len ; i = i +1 ){
      if (i == 0){
        intensiteRed = data[i];
      }
      else if (i == 1){
        intensiteGreen = data[i];
      }
      else if (i == 2){
        intensiteBlue = data[i];
      }
    }
     Serial.print((char)data[i]);
  }
  analogWrite(BlueLed, intensiteBlue);
  analogWrite(RedLed, intensiteRed);
  analogWrite(GreenLed, intensiteGreen);
  //Serial.println(intensiteRed);
 // Serial.println(intensiteGreen);
  //Serial.println(intensiteBlue);

}
