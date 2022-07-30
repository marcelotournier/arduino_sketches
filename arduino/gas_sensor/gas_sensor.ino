/*******
 
 All the resources for this project:
 https://www.hackster.io/Aritro

 CO (Carbon Monoxide) sensor with output to the serial monitor.

 The objective is to have a sensor to measure CO concentration in different spaces.

 I want in the near future to get measures in different locations so I will be able
 to have a proxy the concentration of micro-particles like viruses, in the air

 The POC (Proof of Concept) will light the built in led of the arduino once the
 concentration reaches a given threshold.

 Components:
 - Arduino (I am using a nano)
 - MQ-7 gas sensor "Flying fish"
   (https://www.hackster.io/ingo-lohs/gas-sensor-carbon-monoxide-mq-7-aka-flying-fish-e58457)

 Wiring (arduino <=> sensor):
 - 5V <=> 5V
 - GND <=> GND
 - A0 <=> Sensor Analog Out

 TODO:
 - Draw Schematics
 - Add a digital LCD panel to have a practical way to measure

 REFS:
 - https://electropeak.com/learn/interfacing-mq-7-smoke-gas-sensor-module-with-arduino/
 

*******/

// PARAMS: 
int redLed = LED_BUILTIN;
int smokeA0 = A0; // 
// Your threshold value
int sensorThres = 250;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
  }
  else
  {
    digitalWrite(redLed, LOW);
  }
  delay(100);
}
