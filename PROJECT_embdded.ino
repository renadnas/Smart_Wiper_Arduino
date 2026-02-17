#include <Servo.h>

#define DEG 160

// Pin Definitions
int rainSensorPin = A0;
int ledPin = 3;

Servo wiperServo1;
Servo wiperServo2;

int ledBrightness;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Attach the servos to pins
  wiperServo1.attach(9);
  wiperServo2.attach(10);

  // Initialize servos to 0 degrees
  wiperServo1.write(0);
  wiperServo2.write(180);
}

void loop() {
  int sensorValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(sensorValue);

  // Map rain level to LED brightness (more rain = brighter)
  ledBrightness = map(sensorValue, 1023, 0, 0, 255);
  analogWrite(ledPin, ledBrightness);

  // Rain level detection and wiper speed control
  if (sensorValue >= 950) {
    Serial.println("No Rain");
    wiperServo1.write(0);
    wiperServo2.write(0);
    delay(1000); // Wait a bit before next reading
  } 
  else if (sensorValue >= 650 && sensorValue < 950) {
    Serial.println("Medium Rain");
    servoCtrl(DEG, 15); // slower sweep
  } 
  else if (sensorValue < 650) {
    Serial.println("Heavy Rain");
    servoCtrl(DEG, 4); // Faster sweep
  }
}

// Function to move both wipers back and forth
void servoCtrl(int degree, int spd_dly) {
  for(int pos = 0; pos <= degree; pos++) {
    wiperServo1.write(pos);
    wiperServo2.write(pos);
    delay(spd_dly);
  }
  for(int pos = degree; pos >= 0; pos--) {
    wiperServo1.write(pos);
    wiperServo2.write(pos);
    delay(spd_dly);
  }
}