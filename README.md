# Hexapod

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Platform](https://img.shields.io/badge/platform-Arduino_Mega-blue)
![Hardware](https://img.shields.io/badge/hardware-3D_Printed-orange)
![License](https://img.shields.io/badge/license-MIT-green)

## 🤖 Project Overview

The **Arin Hexapod** is an advanced, bio-inspired robotics platform designed to replicate the locomotion and behavior of an ant. Built on the **Arduino Mega 2560** architecture, this robot utilizes a non-linear tripod gait algorithm to navigate complex terrains with realistic movement.

Unlike standard wheeled robots, this hexapod features **18 degrees of freedom** for locomotion, plus an articulated head and tail system for environmental interaction. It operates in dual modes: autonomous navigation via ultrasonic telemetry and manual control via a custom Android Bluetooth application.

### ✨ Key Features
* **Tripod Gait Locomotion:** Smooth, multi-directional walking (Forward, Backward, Rotation).
* **Interactive Appendages:** Fully articulated head with biting mandibles and an expressive tail.
* **Autonomous Intelligence:** Obstacle detection and avoidance using ultrasonic sensor arrays.
* **Wireless Telemetry:** Real-time manual control via HC-05 Bluetooth integration.
* **Power Management:** High-current power distribution system for stable 22-servo operation.

---

## 🛠️ Hardware Specifications

* **Microcontroller:** Arduino Mega 2560
* **Actuators:** 22x MG996R High-Torque Metal Gear Servos
* **Communication:** HC-05 Bluetooth Module (Hardware Serial)
* **Sensors:** HC-SR04 Ultrasonic Range Finder
* **Power:** 3S LiPo Battery (11.1V) with High-Amp Buck Converter (5V/6V output)

---

## 🔌 Pin Configuration (Arin Architecture)

This project uses a custom pinout configuration optimized for the Arduino Mega hardware serial ports.

### Communication & Sensors
| Component | Interface | Pin Assignment |
| :--- | :--- | :--- |
| **Bluetooth (HC-05)** | Serial1 (TX/RX) | **18 / 19** |
| **Ultrasonic Sensor** | Digital I/O | **Trig: 5 / Echo: 6** |
| **Battery Monitor** | Analog Input | **A3** |

### Servo Mapping
*All servos are MG996R standard.*

| Leg Group | Position | Coxa (Hip) | Femur (Knee) | Tibia (Foot) |
| :--- | :--- | :--- | :--- | :--- |
| **Leg 1** | Front Right | 38 | 37 | 36 |
| **Leg 2** | Mid Right | 41 | 40 | 39 |
| **Leg 3** | Back Right | 45 | 44 | 43 |
| **Leg 4** | Back Left | 30 | 29 | 28 |
| **Leg 5** | Mid Left | 25 | 26 | 27 |
| **Leg 6** | Front Left | 22 | 23 | 24 |

### Articulation System
| Component | Function | Pin Assignment |
| :--- | :--- | :--- |
| **Head** | Pan / Tilt / Grip | 35 / 34 / 33 |
| **Tail** | Lateral Motion | 32 |

---

## 🚀 Getting Started

1.  **Assembly:** Print the 3D components and assemble the chassis.
2.  **Wiring:** Connect servos and sensors according to the **Pin Configuration** table above.
    * *Note: Ensure the HC-05 is connected to pins 18/19 (Serial1), not the default 0/1.*
3.  **Power:** Connect the Buck Converter to the LiPo battery and adjust output to 5V-6V before connecting servos.
4.  **Flash Firmware:** Upload the `.ino` file to the Arduino Mega.
5.  **Control:** Pair with the Android App and begin operation.

## 👨‍💻 Author

**Arin**
*Lead Engineer & Developer*

---
*Based on the original hexapod concepts by Dejan (HowToMechatronics), adapted and re-engineered for the Arin Architecture.*
