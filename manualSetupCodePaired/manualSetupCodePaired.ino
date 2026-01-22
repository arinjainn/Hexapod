#include <Servo.h>

// Declare servos EXACTLY
Servo s1, s2, s3, s5, s7, s8, s9;
Servo s10, s11, s12;
Servo s13, s14, s15;
Servo s16, s17, s18;
Servo s19, s20, s21;
Servo s22, s23, s24;

// Pointer table indexed by servo number
Servo* servoMap[25]; // index 1–24 used

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);   // Bluetooth (Mega)

  // Attach exactly as you specified
  s15.attach(35,600,2400);
  s14.attach(34,600,2400);
  s13.attach(33,600,2400);

  s5.attach(32,600,2400);

  s10.attach(30,600,2400);
  s11.attach(29,600,2400);
  s12.attach(28,600,2400);

  s7.attach(25,600,2400);
  s8.attach(26,600,2400);
  s9.attach(27,600,2400);

  s1.attach(22,600,2400);
  s2.attach(23,600,2400);
  s3.attach(24,600,2400);

  s18.attach(38,600,2400);
  s17.attach(37,600,2400);
  s16.attach(36,600,2400);

  s21.attach(41,600,2400);
  s20.attach(40,600,2400);
  s19.attach(39,600,2400);

  s24.attach(45,600,2400);
  s23.attach(44,600,2400);
  s22.attach(43,600,2400);

  // Servo number mapping (DO NOT CHANGE)
  servoMap[1]  = &s1;
  servoMap[2]  = &s2;
  servoMap[3]  = &s3;
  servoMap[5]  = &s5;
  servoMap[7]  = &s7;
  servoMap[8]  = &s8;
  servoMap[9]  = &s9;
  servoMap[10] = &s10;
  servoMap[11] = &s11;
  servoMap[12] = &s12;
  servoMap[13] = &s13;
  servoMap[14] = &s14;
  servoMap[15] = &s15;
  servoMap[16] = &s16;
  servoMap[17] = &s17;
  servoMap[18] = &s18;
  servoMap[19] = &s19;
  servoMap[20] = &s20;
  servoMap[21] = &s21;
  servoMap[22] = &s22;
  servoMap[23] = &s23;
  servoMap[24] = &s24;

  // Safe startup: center slowly
  for (int i = 1; i <= 24; i++) {
    if (servoMap[i]) {
      servoMap[i]->write(90);
      delay(200);
    }
  }

  Serial.println("READY: <servo> <angle>");
}

void loop() {
  if (Serial1.available()) {
    int num   = Serial1.parseInt();
    int angle = Serial1.parseInt();

    if (num >= 1 && num <= 24 && servoMap[num] && angle >= 0 && angle <= 180) {
      servoMap[num]->write(angle);
      Serial.print("s");
      Serial.print(num);
      Serial.print(" -> ");
      Serial.println(angle);
    }
  }
}
