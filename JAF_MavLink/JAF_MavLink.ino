/*
Name:		FrequencyScheduler.ino
Created:	12/16/2015 8:30:32 PM
Author:	JohnF
Editor:	http://www.visualmicro.com
*/

#include <Arduino.h>
#include "JAF_MavLink.h"

JAF_MavLink MainMavLink;

void setup()
{

	Serial.begin(9600);
	Serial1.begin(57600);

	MainMavLink.init(66, 01, MAV_TYPE_QUADROTOR);

}

void loop()
{
	mavlink_msg_heartbeat_send(MAVLINK_COMM_1, MAV_TYPE_QUADROTOR, MAV_AUTOPILOT_GENERIC, MAV_MODE_FLAG_TEST_ENABLED, 0, MAV_STATE_UNINIT);

	delay(500);

	MainMavLink.communicationReceived();
}
