# Refs on connecting ESPxxx to wifi:
- https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/server-examples.html
- 

# Installing micropython in ESP8266
- https://docs.micropython.org/en/latest/esp8266/tutorial/intro.html


# Flashing the ESP01 using an Arduino:
- refs: 
	- https://www.youtube.com/watch?v=Tv2RMlIxBXs
	- https://iotcircuithub.com/esp8266-programming-arduino/
	- https://create.arduino.cc/projecthub/pratikdesai/how-to-program-esp8266-esp-01-module-with-arduino-uno-598166
	- https://create.arduino.cc/projecthub/imjeffparedes/add-wifi-to-arduino-uno-663b9e
	- https://create.arduino.cc/projecthub/harshmangukiya/create-esp8266-web-server-9c32ac
	- https://create.arduino.cc/projecthub/ahmedibrrahim/iot-using-esp8266-01-and-arduino-afa35e
	- https://create.arduino.cc/projecthub/harshmangukiya/create-esp8266-web-server-9c32ac

- Check the schematics in the folder "flasher_schematics"
- ESP01 draws a lot of current, so you have to use Arduino Uno R3 or an external supply for 3.3V
- Don't use 5V it will burn the microcontroller
- Load an empty sketch in the arduino before beginning
- For some ESP chips I got, I had to use `esptool.py` to erase the memory before using arduino IDE
- Short the ESPxx RST pin with the Arduino GND once you are ready to flash. In my experience, there is a timing to do that right before you load the sketch, this can be annoying sometimes... 
- To flash it, connect the IO00/IO01 pin of the ESP01 in arduino GND. To use the chip, remove it.

# Connect ESP01 to external power:
- refs: 
	- https://www.hackster.io/ROBINTHOMAS/esp8266-esp-01-webserver-7248ca#code
- In my case, I just needed to power the GND and 3V3 in the microcontroller I was using. Sometimes you have to power the CH_EN pin as well, check the chip datasheet
