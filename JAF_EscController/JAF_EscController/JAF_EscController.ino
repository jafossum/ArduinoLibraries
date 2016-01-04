/*
Name:		JAF_EscController.ino
Created:	12/26/2015 8:47:41 PM
Author:	JohnF
*/

#include <Servo.h>
#include <Arduino.h>
#include "JAF_EscControllerlib.h"

int charToInt;
String numberString = "0";

JAF_EscControllerLib escTest;
JAF_EscControllerLib escTest2;

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(57600);

	escTest.init(9, 1000, 2000);
	escTest2.init(10, 1000, 2000);

	Serial.println("Ready...type a numer to set PWM in microseconds");
}

// the loop function runs over and over again until power down or reset
void loop() {

	while (Serial.available() > 0){
		charToInt = Serial.read();

		if (isDigit(charToInt)){
			numberString += (char)charToInt;
		}
		if (charToInt == '\n'){
			Serial.print("String number is: ");
			Serial.println(numberString);
			Serial.print("Int value is: ");
			Serial.println(numberString.toInt());

			// Writing to servo in procentage value
			if ((numberString.toInt() <= 100) && (numberString.toInt() >= 0)){
				Serial.println("Setting value in procetage direct");

				escTest.writeRelativeOuput(numberString.toInt());
			}
			// Writing to servo in microseconds direct
			else if ((numberString.toInt() > 100) && (numberString.toInt() <= 2300)){
				Serial.println("Setting value in microseconds direct");

				escTest.writeMicrosec(numberString.toInt());
			}
		}
		if (charToInt == 'R'){
			numberString = "0";
		}
	}

	// Setting loop time close to 50Hz
	delay(20);

}
