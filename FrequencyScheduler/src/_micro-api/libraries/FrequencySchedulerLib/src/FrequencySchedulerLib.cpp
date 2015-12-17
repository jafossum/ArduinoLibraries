/*
 Name:		FrequencySchedulerLib.cpp
 Created:	12/16/2015 8:30:32 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "FrequencySchedulerLib.h"

// Set this flag to get DEBUG printouts in the scheduler
//#define DEBUG 1

// Initializt the Scheduler with task list and frequency
// void FrequencyScheduler::init(FrequencyScheduler::Task *tasks, uint8_t numTasks, uint8_t LoopFrequency)
void FrequencyScheduler::init(FrequencyScheduler::Task *tasks, uint8_t numTasks)
{
	_numTasks = numTasks;
	_tickCounter = 0;
	_tasks = tasks;
};

// Run once every loop to update the tick counter
void FrequencyScheduler::Tick(void)
{
	_tickCounter++;
}

// Run this once per tick to run the tasks.
void FrequencyScheduler::Run()
{
	for (uint8_t i = 0; i < _numTasks; i++)
	{
		if (_tickCounter % _tasks[i].intervals == 0){
			currentTask = i;
#ifdef DEBUG
			Serial.print("Running task number: ");
			Serial.println(i);
#endif // DEBUG
#undef DEBUG
			_tasks[i].function();

			currentTask = 0;
		}
		else{
#ifdef DEBUG
			Serial.print("Skipping task: ");
			Serial.println(i);
#endif // DEBUG
		}
	}
}
