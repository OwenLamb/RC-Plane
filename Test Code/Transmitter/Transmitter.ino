/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting setup..."));

  // Initialize the radio
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }

  // Print radio details for debugging
  radio.printDetails();

  // Set the address
  radio.openWritingPipe(address);

  // Set power level
  radio.setPALevel(RF24_PA_MIN);

  // Stop listening
  radio.stopListening();

  Serial.println(F("Setup complete."));
}


void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  Serial.println("Sent");
  delay(1000);
}