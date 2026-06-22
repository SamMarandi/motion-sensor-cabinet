# Motion Sensor Cabinet

## Overview

The Motion Sensor Cabinet is an automated storage compartment that opens when a user's hand is detected nearby and closes automatically after the user moves away. The project combines embedded programming, mechanical design, electronics integration, and additive manufacturing into a complete functional system.

The cabinet uses an ESP32 microcontroller, ultrasonic distance sensor, and MG90S servo motor to control a custom-designed rack-and-pinion mechanism housed inside a 3D-printed enclosure.

## Features

* Detects a hand within approximately 20 cm of the sensor
* Requires a continuous detection period of 2 seconds before opening
* Remains open while the user's hand stays within range
* Automatically closes 3 seconds after the hand is removed
* Custom rack-and-pinion mechanism driven by an MG90S servo
* Fully custom 3D-printed enclosure and mechanical components

## Hardware Components

* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* MG90S Servo Motor
* Voltage Divider for sensor level shifting
* Breadboard and jumper wires
* PLA 3D-printed components

## Mechanical Design

The enclosure and motion system were designed in SolidWorks. The assembly consists of:

* Cabinet body
* Base
* Base lid
* Spur gear
* Rack gear mechanism

Components are assembled using M2 screws.

## Electrical Design

The ultrasonic sensor provides distance measurements used to determine when a user's hand is present.

Because the ultrasonic sensor's Echo pin outputs 5V logic and the ESP32 GPIO pins operate at 3.3V logic, a voltage divider was implemented to safely interface the sensor with the microcontroller.

The servo motor is controlled directly by the ESP32 to drive the rack-and-pinion opening mechanism.

## Manufacturing

* Material: PLA
* Layer Height: 0.2 mm
* Total Print Time: Approximately 3 hours (excluding failed prototypes)

## Design Challenges

### Mechanical Tolerances

Several components initially did not fit together due to dimensional tolerances introduced by 3D printing. Multiple design iterations were required to achieve reliable assembly.

### Gear Alignment

Proper spacing between the spur gear and rack gear was critical. Small alignment errors resulted in binding, skipping, or poor motion transfer.

### Servo Retention

Securing the MG90S servo within the enclosure while maintaining proper gear alignment required multiple design revisions and mounting adjustments.

## Lessons Learned

* Designing for real-world manufacturing tolerances
* Integrating mechanical, electrical, and software subsystems
* Using voltage level shifting between 5V and 3.3V devices
* Optimizing 3D print orientation and support strategies
* Debugging servo-driven mechanical systems

## Future Improvements

* Replace breadboard wiring with soldered connections
* Add battery-powered operation
* Add a power switch
* Add power filtering and decoupling capacitors near the servo
