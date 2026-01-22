void setup() {
  Serial.begin(9600);      // USB Serial Monitor
  Serial1.begin(9600);     // Bluetooth on pins 18,19

  Serial.println("Bluetooth Debug Mode Started");
}

void loop() {
  if (Serial1.available()) {
    char incomingChar = Serial1.read();

    // Print raw character
    Serial.print("Char received: ");
    Serial.println(incomingChar);

    // Print ASCII value (VERY IMPORTANT)
    Serial.print("ASCII value: ");
    Serial.println((int)incomingChar);
    Serial.println("----------------");
  }
}
