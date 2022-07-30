/*
 * Bare minimum prototype for the arduino game console I am building.
 * 
 * Components:
 * - Arduino nano
 * - OLED Screen 128x32 with 4 connector pins (GND, VCC, SCL, SDA)
 * - 3 push buttons
 * 
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ref : https://learn.adafruit.com/adafruit-gfx-graphics-library/rotating-the-display
// ref : https://www.elithecomputerguy.com/2019/07/print-text-to-oled-screen-on-arduino/
// ref : https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/

#define button1 2
#define button2 3
#define button12 12

boolean button1State;
boolean button2State;
boolean button12State;

void setup()
{
 pinMode(button1,INPUT_PULLUP);
 pinMode(button2,INPUT_PULLUP);
 pinMode(button12,INPUT_PULLUP);
 pinMode(LED_BUILTIN, OUTPUT);

 Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(1500); // Pause for 1.5 seconds

  // Clear the buffer
  display.clearDisplay();

  // rotate 270 degrees
  display.setRotation(3);
}
void loop()
{
 // Clear the buffer
  display.clearDisplay();

  display.setTextSize(0.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  
  
 button1State = digitalRead(button1);
 button2State = digitalRead(button2);
 button12State = digitalRead(button12);
 
 if (button1State == 1)
   digitalWrite(LED_BUILTIN, LOW);
 else {
   display.println("Botao 1");
   display.display();
   delay(1);
  }

 if (button2State == 1)
   digitalWrite(LED_BUILTIN, LOW);
 else {
  display.println("Botao 2");
  display.display();
  delay(1);
  }

 if (button12State == 1)
   digitalWrite(LED_BUILTIN, LOW);
 else {
    display.println("Botao 3");
    display.display();
    delay(1);
  }
}
