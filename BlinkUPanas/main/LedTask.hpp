#pragma once
#ifndef LEDTASK_HPP
#define LEDTASK_HPP

#include "taskClass.hpp"

extern "C" {
class LedTask : public Task {
	private:
		int ledPin;
		TickType_t delayMs;
	public:
		LedTask(
			const char* name, uint32_t stack_size, UBaseType_t prio,
			int pin, TickType_t delay
		);

		void toggleLed(int pin);
		virtual void taskFunction();
};
}

#endif