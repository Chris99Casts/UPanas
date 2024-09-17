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
	gpio_num_t selected_pin;
	switch (ledPin) {
		case  0: selected_pin = GPIO_NUM_0; break;
		case  1: selected_pin = GPIO_NUM_1; break;
		case  2: selected_pin = GPIO_NUM_2; break;
		case  3: selected_pin = GPIO_NUM_3; break;
		case  4: selected_pin = GPIO_NUM_4; break;
		case  5: selected_pin = GPIO_NUM_5; break;
		case  6: selected_pin = GPIO_NUM_6; break;
		case  7: selected_pin = GPIO_NUM_7; break;
		case  8: selected_pin = GPIO_NUM_8; break;
		case  9: selected_pin = GPIO_NUM_9; break;
		case 10: selected_pin = GPIO_NUM_10; break;
		case 11: selected_pin = GPIO_NUM_11; break;
		case 12: selected_pin = GPIO_NUM_12; break;
		case 13: selected_pin = GPIO_NUM_13; break;
		case 14: selected_pin = GPIO_NUM_14; break;
		case 15: selected_pin = GPIO_NUM_15; break;
		case 16: selected_pin = GPIO_NUM_16; break;
		case 17: selected_pin = GPIO_NUM_17; break;
		case 18: selected_pin = GPIO_NUM_18; break;
		case 19: selected_pin = GPIO_NUM_19; break;
		case 20: selected_pin = GPIO_NUM_20; break;
		case 21: selected_pin = GPIO_NUM_21; break;
		case 22: selected_pin = GPIO_NUM_22; break;
		case 23: selected_pin = GPIO_NUM_23; break;
		// case 24: selected_pin = GPIO_NUM_24; break;
		case 25: selected_pin = GPIO_NUM_25; break;
		case 26: selected_pin = GPIO_NUM_26; break;
		case 27: selected_pin = GPIO_NUM_27; break;
		case 28: selected_pin = GPIO_NUM_28; break;
		case 29: selected_pin = GPIO_NUM_29; break;
		case 30: selected_pin = GPIO_NUM_30; break;
		case 31: selected_pin = GPIO_NUM_31; break;
		case 32: selected_pin = GPIO_NUM_32; break;
		case 33: selected_pin = GPIO_NUM_33; break;
		case 34: selected_pin = GPIO_NUM_34; break;
		case 35: selected_pin = GPIO_NUM_35; break;
		case 36: selected_pin = GPIO_NUM_36; break;
		case 37: selected_pin = GPIO_NUM_37; break;
		case 38: selected_pin = GPIO_NUM_38; break;
		case 39: selected_pin = GPIO_NUM_39; break;
		default: selected_pin = GPIO_NUM_MAX;
	}
	gpio_set_level(selected_pin, pin);
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