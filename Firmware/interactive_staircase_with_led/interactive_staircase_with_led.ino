#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// IR Sensor Pins
const int IR_Entrance = 2;
const int IR_Midway = 3;
const int IR_Top = 4;

// LED Pins
const int LED_Entrance = 5;
const int LED_Midway = 6;
const int LED_Top = 7;

// DFPlayer Setup
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  pinMode(IR_Entrance, INPUT);
  pinMode(IR_Midway, INPUT);
  pinMode(IR_Top, INPUT);

  pinMode(LED_Entrance, OUTPUT);
  pinMode(LED_Midway, OUTPUT);
  pinMode(LED_Top, OUTPUT);

  // Initialize LEDs to OFF
  digitalWrite(LED_Entrance, LOW);
  digitalWrite(LED_Midway, LOW);
  digitalWrite(LED_Top, LOW);

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin DFPlayer Mini:");
    while (true);
  }

  myDFPlayer.volume(30);  // Set max volume

  Serial.println("System Ready. Chaser started!");
}

void loop() {
  // Check if any sensor triggered
  if (digitalRead(IR_Entrance) == LOW) {
    Serial.println("Entrance Sensor Triggered");
    handleSensor(LED_Entrance, 1); // LED 5, play 0001.mp3
  }
  else if (digitalRead(IR_Midway) == LOW) {
    Serial.println("Midway Sensor Triggered");
    handleSensor(LED_Midway, 2); // LED 6, play 0002.mp3
  }
  else if (digitalRead(IR_Top) == LOW) {
    Serial.println("Top Sensor Triggered");
    handleSensor(LED_Top, 3); // LED 7, play 0003.mp3
  }
  else {
    // No sensor triggered ➔ run LED chaser
    runChaser();
  }
}

void handleSensor(int ledPin, int audioNumber) {
  // Turn off all LEDs first
  digitalWrite(LED_Entrance, LOW);
  digitalWrite(LED_Midway, LOW);
  digitalWrite(LED_Top, LOW);

  myDFPlayer.play(audioNumber); // Play selected audio
  digitalWrite(ledPin, HIGH);    // Turn ON the matching LED
  delay(1000);                   // Wait
  digitalWrite(ledPin, LOW);     // Turn OFF after action
}

void runChaser() {
  digitalWrite(LED_Entrance, HIGH);
  delay(200);
  digitalWrite(LED_Entrance, LOW);

  digitalWrite(LED_Midway, HIGH);
  delay(200);
  digitalWrite(LED_Midway, LOW);

  digitalWrite(LED_Top, HIGH);
  delay(200);
  digitalWrite(LED_Top, LOW);
}
