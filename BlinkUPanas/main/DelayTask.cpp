#pragma once
#ifndef DELAYTASK_CPP
#define DELAYTASK_CPP

#include "DelayTask.hpp"

extern "C" {
DelayTask::DelayTask(
	const char* name, uint32_t stack_size, UBaseType_t prio,
	TickType_t delay
) : Task(name, stack_size, prio), delay(delay) {}
void DelayTask::taskFunction() {
	while (true) {
		printf("Delaying for %5ldcy...\n", delay);
		vTaskDelay(delay);
	}
}
}

#endif