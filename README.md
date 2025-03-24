# Robot Control System Using ESP32 and Servo Motors

## Project Overview

This project is a robot control system using the ESP32 Wi-Fi module and servo motors. The system allows you to control a robot's movement and its servos via a web interface. The ESP32 connects to a Wi-Fi network and listens for HTTP requests to control the motors and servos.

## Features

- **Servo Control**: Control up to 4 servos with 0°, 90°, and 180° angles.
- **Motor Control**: Forward, backward, left, and right movement using motor drivers (L298N or H-bridge).
- **Web Interface**: Use a simple web interface to send commands for controlling the robot.

## Components Used

- **MG995 Servo Motor**: High-torque servo motor for controlling robotic arms.
- **L298N Motor Driver**: Motor driver used to control the direction and speed of motors.
- **TT Gear Motors**: Motors used for the movement of the robot's wheels.
- **ESP32**: Microcontroller used to manage the robot's movements and communication.
- **Robotic Arm Kit**: Kit used to construct the robotic arm, including servo motors.
- **4WD Car Kit**: Chassis and wheels used for building the robot's movement system.
- **Breadboard**: A tool for connecting and testing circuits without soldering.
- **Jumper Wires**: Wires used for making connections between components.
- **USB-A to micro-USB Cable**: Cable used for programming and powering the ESP32.
- **Car Chassis**: The base frame for the robot.
- **12V Battery**: Power source for the motors and the ESP32.
- **On/Off Switch**: Switch used to turn the robot on or off.
- **Connecting Wires**: Wires used to make various connections in the circuit.
- **Soldering Iron**: Tool used for connecting components by melting solder.
- **Solder Wire**: Material used to create permanent connections between electrical components.

## Wiring Diagram

- **ESP32 Pinout**:
  - Servo1: GPIO 15
  - Servo2: GPIO 2
  - Servo3: GPIO 4
  - Servo4: GPIO 5
  - Motor Driver:
    - Motor1A: GPIO 12
    - Motor1B: GPIO 13
    - Motor2A: GPIO 14
    - Motor2B: GPIO 27

## Software Setup

1. Install the ESP32 board library in the Arduino IDE.
2. Upload the provided Arduino sketch to your ESP32.
3. Connect your ESP32 to a Wi-Fi network by setting the `ssid` and `password` in the code.

## Control Interface

After the ESP32 connects to Wi-Fi, it will generate an IP address. You can access the web interface by entering the IP address in your web browser. The following actions can be performed via HTTP requests:

- `/forward`: Move the robot forward.
- `/backward`: Move the robot backward.
- `/left`: Turn the robot left.
- `/right`: Turn the robot right.
- `/stop`: Stop the robot.
- `/servo1_0`, `/servo1_90`, `/servo1_180`: Control Servo 1.
- `/servo2_0`, `/servo2_90`, `/servo2_180`: Control Servo 2.
- `/servo3_0`, `/servo3_90`, `/servo3_180`: Control Servo 3.
- `/servo4_0`, `/servo4_90`, `/servo4_180`: Control Servo 4.

