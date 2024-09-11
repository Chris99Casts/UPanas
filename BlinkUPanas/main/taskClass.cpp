#pragma once
#ifndef TASKCLASS_CPP
#define TASKCLASS_CPP

#include "taskClass.hpp"
extern "C" {

Task::Task(const char* name, uint32_t stack_size, UBaseType_t prio) {
	taskName  = name;
	stackSize = stack_size;
	priority  = prio;
	taskHandle = NULL;
	xTaskCreate(
		this->taskFunction,
		taskName,
		stack_size,
		NULL,
		prio,
		&taskHandle
	);
}
Task::~Task() {
	xTaskSuspend(taskHandle);
	vTaskDestroy(taskHandle);
}
void Task::start() {
	vTaskResume(taskHandle);
}
void Task::stop() {
	xTaskSuspend(taskHandle)
}

LedTask::LedTask(
	const char* name, uint32_t stack_size, UBaseType_t prio
	int pin, TickType_t delay
) : Task(name, stack_size, prio) {
	ledPin  = pin;
	delayMs = delay;
}
void LedTask::toggleLed(int pin) {
	// asdf
}
virtual void LedTask::taskFunction() {

}

}
#endif
