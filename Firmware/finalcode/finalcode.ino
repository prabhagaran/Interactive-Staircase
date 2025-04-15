jh#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// IR Sensor Pins
const int IR_Entrance = 2;
const int IR_Midway = 3;
const int IR_Top = 4;

// DFPlayer Setup
SoftwareSerial mySoftwareSerial(10, 11); // RX (Arduino pin 10), TX (Arduino pin 11)
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  // Setup IR sensor pins
  pinMode(IR_Entrance, INPUT);
  pinMode(IR_Midway, INPUT);
  pinMode(IR_Top, INPUT);

  // Setup DFPlayer
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin DFPlayer Mini:");
    Serial.println("1. Please check the DFPlayer Mini connection.");
    Serial.println("2. Insert the microSD card.");
    while (true); // Stay stuck if DFPlayer fails to initialize
  }

  myDFPlayer.volume(30);  // Set maximum volume (0 to 30)

  Serial.println("System Ready. Sensors Activated!");
}

void loop() {
  // Check entrance sensor
  if (digitalRead(IR_Entrance) == LOW) {
    Serial.println("Entrance Sensor Triggered");
    myDFPlayer.play(1); // Play 0001.mp3
    delay(2000);  // Simple debounce to avoid multiple rapid triggers
  }

  // Check midway sensor
  if (digitalRead(IR_Midway) == LOW) {
    Serial.println("Midway Sensor Triggered");
    myDFPlayer.play(2); // Play 0002.mp3
    delay(2000);
  }

  // Check top sensor
  if (digitalRead(IR_Top) == LOW) {
    Serial.println("Top Sensor Triggered");
    myDFPlayer.play(3); // Play 0003.mp3
    delay(2000);
  }
}
