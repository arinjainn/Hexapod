#include <Servo.h>

Servo servos[21];
int pins[21] = {
  43,44,45,   // 1-3 LF
  39,40,41,   // 4-6 LM
  36,37,38,   // 7-9 LR
  24,23,22,   // 10-12 RF
  27,26,25,   // 13-15 RM
  28,29,30,   // 16-18 RR
  35,34,32    // 19-21 Head, Tail
};

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);   // Bluetooth on pins 19 (RX), 18 (TX)

  for (int i = 0; i < 21; i++) {
    servos[i].attach(pins[i]);
    delay(40);
    servos[i].write(90);   // start safe
    delay(200);
  }

  Serial.println("READY: Send -> servo angle");
}

void loop() {
  if (Serial1.available()) {
    int servoNum = Serial1.parseInt();
    int angle    = Serial1.parseInt();

    if (servoNum >= 1 && servoNum <= 21 && angle >= 0 && angle <= 180) {
      servos[servoNum - 1].write(angle);

      Serial.print("Servo ");
      Serial.print(servoNum);
      Serial.print(" -> ");
      Serial.println(angle);
    }
  }
}
