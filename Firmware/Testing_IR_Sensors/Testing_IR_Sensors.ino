// Simple IR sensor test

const int IR_Entrance = 2;
const int IR_Midway = 3;
const int IR_Top = 4;

void setup() {
  Serial.begin(9600);

  pinMode(IR_Entrance, INPUT);
  pinMode(IR_Midway, INPUT);
  pinMode(IR_Top, INPUT);

  Serial.println("IR Sensor Test Started");
}

void loop() {
  if (digitalRead(IR_Entrance) == LOW) {
    Serial.println("Entrance Sensor: DETECTED");
    delay(500);  // small debounce delay
  }

  if (digitalRead(IR_Midway) == LOW) {
    Serial.println("Midway Sensor: DETECTED");
    delay(500);
  }

  if (digitalRead(IR_Top) == LOW) {
    Serial.println("Top Sensor: DETECTED");
    delay(500);
  }
}
