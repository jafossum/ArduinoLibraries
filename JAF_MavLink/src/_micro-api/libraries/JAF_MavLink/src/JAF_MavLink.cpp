/*
Name:		JAF_MavLink.cpp
Created:	12/16/2015 8:30:32 PM
Author:	JohnF
Editor:	http://www.visualmicro.com
*/

#include "JAF_MavLink.h"

mavlink_system_t mavlink_system;
MAV_AUTOPILOT mav_autopilot;
MAV_TYPE mav_type;
MAV_MODE_FLAG mav_mode_flag;
MAV_MODE_FLAG_DECODE_POSITION mav_mode_decode_position;
MAV_STATE mav_state;

void JAF_MavLink::init(int sysId, int compId, MAV_TYPE mavType){

	// SystemID def
	mavlink_system.sysid = sysId;
	mavlink_system.compid = compId;
	mav_type = mavType;

	// Mode Def (Curently testing)
	mav_autopilot = MAV_AUTOPILOT_GENERIC;
	mav_mode_flag = MAV_MODE_FLAG_TEST_ENABLED;
	mav_mode_decode_position = MAV_MODE_FLAG_DECODE_POSITION_TEST;
	mav_state = MAV_STATE_UNINIT;
}

void JAF_MavLink::comm_send_ch(mavlink_channel_t chan, uint8_t ch)
{
	if (chan == MAVLINK_COMM_0)
	{
		// Serial1 uses XBee for communication with GroundControl
		Serial1.write(ch);
	}
	if (chan == MAVLINK_COMM_1)
	{
		// Serial sends output on standard USB interface
		Serial.write(ch);
	}
}

void JAF_MavLink::communicationReceived(){

	mavlink_message_t msg;
	mavlink_status_t status;

	// COMMUNICATION THROUGH EXTERNAL UART PORT (XBee serial)

	while (Serial1.available())
	{
		uint8_t c = Serial1.read();
		// Try to get a new message
		if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
			// Handle message

			switch (msg.msgid)
			{
			case MAVLINK_MSG_ID_HEARTBEAT:
			{
				// Do Something here
			}
			break;
			default:
				//Do nothing
				break;
			}
		}

		// And get the next one
	}

	// Update global packet drops counter
	// packetDrops += status.packet_rx_drop_count;

	// COMMUNICATION THROUGH SECOND UART

	while (Serial.available())
	{
		uint8_t c = Serial.read();
		// Try to get a new message
		if (mavlink_parse_char(MAVLINK_COMM_1, c, &msg, &status))
		{
			// Handle message the same way like in for UART0
			// you can also consider to write a handle function like
			// handle_mavlink(mavlink_channel_t chan, mavlink_message_t* msg)
			// Which handles the messages for both or more UARTS
		}

		// And get the next one
	}

	// Update global packet drops counter
	// packetDrops += status.packet_rx_drop_count;
}