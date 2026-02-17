# Smart_Wiper_Arduino
This project implements an automated windshield wiper system using an Arduino, a rain sensor, and dual servo motors. The system dynamically adjusts the wiper speed and an indicator LED's brightness based on the intensity of detected rainfall.

Overview
The system operates on a simple feedback loop:
Sensing: An analog rain sensor monitors moisture levels.
Visual Feedback: An LED increases in brightness as the rainfall becomes heavier.
Mechanical Action: Two servo motors (acting as wipers) sweep back and forth. The delay between movements decreases as rain intensity increases, resulting in faster wiping speeds.

Hardware Components
Microcontroller: Arduino (Uno or compatible).
Sensors: Analog Rain Sensor (connected to A0).
Actuators: 2x Servo Motors (connected to pins 9 and 10).
Indicators: 1x LED (connected to PWM pin 3).

Features & Logic
The system categorizes weather conditions into three states based on the sensor's analog output:
Installation & Setup
Connect the Hardware:
Attach Servo 1 to Pin 9 and Servo 2 to Pin 10.
Connect the Rain Sensor Signal pin to A0.
Connect the LED (with a resistor) to Pin 3.

Software:
Ensure the Servo.h library is installed in your Arduino IDE.
Upload the provided .ino code to your board.
Calibration:
Open the Serial Monitor (9600 baud) to view real-time sensor values and adjust the threshold constants (950 and 650) if necessary to match your specific sensor sensitivity.

Code Structure
setup(): Initializes serial communication, sets pin modes, and resets wipers to their starting positions.
loop(): Continuously reads the rain sensor, maps the value to LED brightness, and triggers the appropriate wiper speed.
servoCtrl(int degree, int spd_dly): A modular function that handles the "sweep" animation for both servos simultaneously, using spd_dly to control the frequency of movement.


