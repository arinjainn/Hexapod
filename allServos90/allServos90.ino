#include <Servo.h>

Servo servos[21];
int pins[21] = {
  43, 44, 45,   // LF
  39, 40, 41,   // LM
  36, 37, 38,   // LR
  24, 23, 22,   // RF
  27, 26, 25,   // RM
  28, 29, 30,   // RR
  35, 34, 32    // Neck Yaw, Neck Pitch, Tail
};

void setup() {
  // Attach all servos
  for (int i = 0; i < 21; i++) {
    servos[i].attach(pins[i]);
    delay(40);              // small delay while attaching
  }

  delay(1000);              // let power rail stabilize

  // Move ONE servo at a time to 90°
  for (int i = 0; i < 21; i++) {
    servos[i].write(90);
    delay(300);             //  KEY: limits inrush current
  }
}

void loop() {
  // Hold position, no movement
}
