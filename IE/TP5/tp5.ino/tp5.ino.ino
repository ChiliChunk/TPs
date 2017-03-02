void setup() {
  uint8_t data[] = {
    0x5A,           /* entête */
    0x01,           /* numéro de protocole */
    0x00,           /* numéro de séquence */
    0x00, 0xBD,     /* adresse source */
    0x00, 0x02,     /* numéro d'application */
    0b00011100, 0x00, 0x00, 0x00, 0x00,
  };
}

void loop() {
  // put your main code here, to run repeatedly:

}
