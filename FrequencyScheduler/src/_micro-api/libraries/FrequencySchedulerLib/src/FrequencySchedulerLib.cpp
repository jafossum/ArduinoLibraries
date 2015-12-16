/*
 Name:		FrequencySchedulerLib.cpp
 Created:	12/16/2015 8:30:32 PM
 Author:	JohnF
 Editor:	http://www.visualmicro.com
*/

#include "FrequencySchedulerLib.h"

uint8_t FrequencyScheduler::currentTask = 0;

// Initializt the Scheduler with task list and frequency
// void FrequencyScheduler::init(FrequencyScheduler::Task *tasks, uint8_t numTasks, uint8_t LoopFrequency)
void FrequencyScheduler::init(uint8_t numTasks)
{
	_numTasks = numTasks;
	_tickCounter = 0;

	Task tasks[_numTasks];
};

// Run once every loop to update the tick counter
void FrequencyScheduler::Tick(void)
{
	_tickCounter++;
}

void FrequencyScheduler::AddTask(FrequencyScheduler::Task task)
{
	
}

// Run this once per tick to run the tasks.
void FrequencyScheduler::Run()
{
	for (uint8_t i = 0; i < _numTasks; i++)
	{
		currentTask = i;
		(*_tasks[i].function)();
		currentTask = 0;
	}
}
