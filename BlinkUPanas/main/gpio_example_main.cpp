/* GPIO Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#include "taskClass.hpp"
#include "taskClass.cpp"
#include "LedTask.hpp"
#include "LedTask.cpp"
#include "DelayTask.hpp"
#include "DelayTask.cpp"

extern "C" {

void app_main(void) {
    LedTask blink_25("LED PIN 25", 2048, 10, 25,  500);
    LedTask blink_26("LED PIN 26", 2048, 10, 26, 2000);
    LedTask blink_27("LED PIN 27", 2048, 10, 27, 1000);
    DelayTask delay_200("Delay 2000 cy", 2048, 10, 2000);

    blink_25.start();
    blink_26.start();
    blink_27.start();
    delay_200.start();

    while(true) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

}
