/*
 Name:		FrequencyScheduler.ino
 Created:	12/16/2015 8:30:32 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "FrequencySchedulerLib.h"

void BlinkToggle();

static uint8_t ledValue = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);

	FrequencyScheduler::Task entry1{ &BlinkToggle, 1 };
	FrequencyScheduler::Task entry2{ &BlinkToggle, 2 };

	FrequencyScheduler scheduler;

	scheduler.init(2);


}

// the loop function runs over and over again forever
void loop() {
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);              // wait for a second
}

void BlinkToggle()
{
	if (ledValue)
	{
		digitalWrite(13, HIGH);
	}
	else
	{
		digitalWrite(13, LOW);
	}
}
