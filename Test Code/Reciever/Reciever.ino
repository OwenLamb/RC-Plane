#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  delay(1000); // Give some time to open the Serial Monitor
  
  radio.begin();
  radio.openReadingPipe(1, address); // Use a different pipe number if needed
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  Serial.println("Receiver started");
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    text[sizeof(text) - 1] = '\0'; // Ensure null-terminated string
    Serial.print("Received: ");
    Serial.println(text);
  }
}
