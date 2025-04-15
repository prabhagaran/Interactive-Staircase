#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin DFPlayer Mini:");
    Serial.println("1. Please check the DFPlayer Mini connection.");
    Serial.println("2. Insert the microSD card.");
    while (true);
  }
  
  Serial.println("DFPlayer Mini online.");
  myDFPlayer.volume(30);  // Volume 0~30

  // Play 0001.mp3
  myDFPlayer.play(1);
}

void loop() {
  // Nothing needed in loop for simple test
}
