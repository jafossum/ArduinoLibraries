/*
Name:		JAF_MavLink.h
Created:	12/21/2015 8:30:32 PM
Author:	JohnF
Editor:	http://www.visualmicro.com
*/

#ifndef _JAF_MAVLINK_H
#define _JAF_MAVLINK_H

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS 1

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "JAF_Protocol/mavlink_types.h"
extern mavlink_system_t mavlink_system;

#include "JAF_Protocol/JAF_QuadProject/mavlink.h"

extern MAV_AUTOPILOT mav_autopilot;
extern MAV_TYPE mav_type;
extern MAV_MODE_FLAG mav_mode_flag;
extern MAV_MODE_FLAG_DECODE_POSITION mav_mode_decode_position;
extern MAV_STATE mav_state;

class JAF_MavLink
{
public:

	// initialise the MavLink setup
	void init(int sysId, int compId, MAV_TYPE mavType);

	// Defining comm_send_ch to make this shit work!
	void comm_send_ch(mavlink_channel_t chan, uint8_t ch);

	// Receive on channels in MavLink
	static void communicationReceived(void);

	static int packetDrops;

private:

};
#endif


