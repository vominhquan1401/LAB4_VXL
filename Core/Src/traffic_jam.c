/*
 * traffic_jam.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */
#include "traffic_jam.h"
#include "display.h"
#include "timer.h"
#include "input_processing.h"
//counter time = { 0 };
void setTimeForTraffic(counter *time, int red, int yellow, int green) {
	time->CounterRed = red;
	time->CounterYellow = yellow;
	time->CounterGreen = green;
	time->count = red;
	time->direction = 0;
}
void checkTime(counter *time) {
	if (time->CounterRed > 99) {
		time->CounterRed = 0;
	}
	if (time->CounterYellow > 99) {
		time->CounterYellow = 0;
	}
	if (time->CounterGreen > 99) {
		time->CounterGreen = 0;
	}
}
void set_light(GPIO_TypeDef *GPIOx, uint16_t red, uint16_t yellow,
		uint16_t green, uint8_t state) {
	if (state == 0) { // đỏ
		HAL_GPIO_WritePin(GPIOx, red, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOx, yellow | green, GPIO_PIN_RESET);
	} else if (state == 1) { //vàng
		HAL_GPIO_WritePin(GPIOx, yellow, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOx, red | green, GPIO_PIN_RESET);
	} else if (state == 2) { //xanh
		HAL_GPIO_WritePin(GPIOx, green, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOx, red | yellow, GPIO_PIN_RESET);
	}
}

void trafficNormal(counter *time) {
	if (time->direction == 0) {
		if (time->count <= time->CounterRed) { // Thằng trên đang đỏ
			set_light(GPIOB, LED_RED_ABOVE_Pin, LED_YELLOW_ABOVE_Pin,
			LED_GREEN_ABOVE_Pin, 0);
			displayLED7SEG_ABOVE(time->count);
			if (time->count >= time->CounterYellow) {
				set_light(GPIOB, LED_RED_RIGHT_Pin, LED_YELLOW_RIGHT_Pin,
				LED_GREEN_RIGHT_Pin, 2);
				displayLED7SEG_RIGHT(time->count - time->CounterYellow);
			} else {
				set_light(GPIOB, LED_RED_RIGHT_Pin, LED_YELLOW_RIGHT_Pin,
				LED_GREEN_RIGHT_Pin, 1);
				displayLED7SEG_RIGHT(time->count);
			}
		}
	} else if (time->direction == 1) {
		if (time->count <= time->CounterRed) { // Thằng phải đang đỏ
			set_light(GPIOB, LED_RED_RIGHT_Pin, LED_YELLOW_RIGHT_Pin,
			LED_GREEN_RIGHT_Pin, 0);
			displayLED7SEG_RIGHT(time->count);
			if (time->count >= time->CounterYellow) {
				set_light(GPIOB, LED_RED_ABOVE_Pin, LED_YELLOW_ABOVE_Pin,
				LED_GREEN_ABOVE_Pin, 2);
				displayLED7SEG_ABOVE(time->count - time->CounterYellow);
			} else {
				set_light(GPIOB, LED_RED_ABOVE_Pin, LED_YELLOW_ABOVE_Pin,
				LED_GREEN_ABOVE_Pin, 1);
				displayLED7SEG_ABOVE(time->count);
			}
		}
	}
	time->count--;
	if (time->count <= 0) {
		time->count = time->CounterRed;
		time->direction = !time->direction;
	}
}
void fsm_automatic() {
	if (IsNormalMode()) {
		trafficNormal(&time);
		checkTime(&time);
	}
}
