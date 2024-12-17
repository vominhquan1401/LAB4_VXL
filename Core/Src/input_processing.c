/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "input_processing.h"

typedef enum {
	NORMAL, MODIFY_RED_LEDS, MODIFY_AMBER_LEDS, MODIFY_GREEN_LEDS
} Mode;

typedef enum {
	RELEASE, PRESS
} State;

Mode mode = NORMAL;

int IsNormalMode() {
	if (mode == NORMAL) {
		return 1;
	}
	return 0;
}
int IsModifyRedLeds() {
	if (mode == MODIFY_RED_LEDS) {
		return 1;
	}
	return 0;
}
int IsModifyAmberLeds() {
	if (mode == MODIFY_AMBER_LEDS) {
		return 1;
	}
	return 0;
}
int IsModifyGreenLeds() {
	if (mode == MODIFY_GREEN_LEDS) {
		return 1;
	}
	return 0;
}


void fsm_setting(void) {
	switch (mode) {
	case NORMAL: //đèn hoạt động bình thường
		if (IsPressed(0)) {
			mode = MODIFY_RED_LEDS;
			//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
		}
		break;
	case MODIFY_RED_LEDS:
		if (IsPressed(0)) {
			mode = MODIFY_AMBER_LEDS;
			//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
		}
		break;
	case MODIFY_AMBER_LEDS:
		if (IsPressed(0)) {
			mode = MODIFY_GREEN_LEDS;
			//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
		}
		break;
	case MODIFY_GREEN_LEDS:
		if (IsPressed(0)) {
			mode = NORMAL;
			//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
		}
		break;
	}
}
