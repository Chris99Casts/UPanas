#pragma once
#ifndef LEDTASK_CPP
#define LEDTASK_CPP

extern "C" {

#include "LedTask.hpp"

LedTask::LedTask(
	const char* name, uint32_t stack_size, UBaseType_t prio,
	int pin, TickType_t delay
) : Task(name, stack_size, prio) {
	ledPin  = pin;
	delayMs = delay;

	gpio_config_t io_conf = {};
	io_conf.intr_type    = GPIO_INTR_DISABLE;
	io_conf.mode         = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = 1ULL<<ledPin;
	io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
	io_conf.pull_up_en   = GPIO_PULLUP_DISABLE;
	gpio_config(&io_conf);
}
void LedTask::toggleLed(int pin) {
	gpio_set_level((gpio_num_t)ledPin, pin);
}
void LedTask::taskFunction() {
	uint8_t count = 0;
	while(true) {
		toggleLed(++count % 2);
		printf("PIN [%d] count: %3d\n", ledPin, count);
		vTaskDelay(delayMs / portTICK_PERIOD_MS);
	}
}

}

#endif