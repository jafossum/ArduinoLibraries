/*
 Name:		JAF_Ultrasonic.ino
 Created:	1/19/2016 8:06:39 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "JAF_UltrasonicLib.h"

JAF_UltrasonicLib Ultrasonic;
uint16_t meassurement = 0; 
uint16_t lastMeassurement = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	
	Ultrasonic = JAF_UltrasonicLib();
	Ultrasonic.init();

	attachInterrupt(digitalPinToInterrupt(INTERUPTPIN), Ultrasonic.calculateMeassurement, RISING);

	Serial.begin(57600);
	while(!Serial){}
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	meassurement = Ultrasonic.getMeassurement();
	
	if (meassurement != lastMeassurement)
	{
		Serial.print("New Meassurement: ");
		Serial.print(meassurement);
		Serial.println("cm");

		lastMeassurement = meassurement;
	}
	
	delay(1);
}
