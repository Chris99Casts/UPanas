#pragma once
#ifndef TASKCLASS_H
#define TASKCLASS_H

#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

extern "C" {

class Task {
	private:
		const char*  taskName;
		uint32_t     stackSize;
		UBaseType_t  priority;
		TaskHandle_t taskHandle;
	public:
		Task(const char* name, uint32_t stack_size, UBaseType_t prio);
		~Task();

		virtual void taskFunction() = 0;

		void start();
		void stop();
}

class LedTask : public Task {
	private:
		int ledPin;
		TikcType_t delayMs;
	public:
		LedTask(
			const char* name, uint32_t stack_size, UBaseType_t prio,
			int pin, TickType_t delay
		);

		void toggleLed(int pin);
}

}

#endif