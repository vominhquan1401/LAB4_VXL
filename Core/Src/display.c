/*
 * display.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "display.h"
#include "input_processing.h"
#include "traffic_jam.h"

typedef struct {
	int CountForRedLed;
	int CountForAmberLed;
	int CountForGreenLed;
} CountTime;
CountTime count;
void InitCount() {
	count.CountForRedLed = 0;
	count.CountForAmberLed = 0;
	count.CountForGreenLed = 0;
}

void displayBlinkRedLed() {
	if (IsModifyRedLeds()) {
		if (timerBlinkTraffic_flag) {
			HAL_GPIO_TogglePin(GPIOB, LED_RED_ABOVE_Pin | LED_RED_RIGHT_Pin);
			timerBlinkTraffic = 25;
		}
	}
}
void displayRedLed() {
	//static int counter;
	if (IsModifyRedLeds()) {
		if (IsPressed(1)) {
			count.CountForRedLed++;
		}
		displayLED7SEG_ABOVE(time.CounterRed + count.CountForRedLed);
		displayLED7SEG_RIGHT(1);
	}
}

void displayBlinkAmberLed() {
	if (IsModifyAmberLeds()) {
		if (timerBlinkTraffic_flag) {
			HAL_GPIO_TogglePin(GPIOB,
					LED_YELLOW_ABOVE_Pin | LED_YELLOW_RIGHT_Pin);
			timerBlinkTraffic = 25;
		}
	}
}
void displayAmberLed() {
	//static int counter;
	if (IsModifyAmberLeds()) {
		if (IsPressed(1)) {
			count.CountForAmberLed++;
		}
		displayLED7SEG_ABOVE(time.CounterYellow + count.CountForAmberLed);
		displayLED7SEG_RIGHT(2);
	}
}

void displayBlinkGreenLed() {
	if (IsModifyGreenLeds()) {
		if (timerBlinkTraffic_flag) {
			HAL_GPIO_TogglePin(GPIOB,
					LED_GREEN_ABOVE_Pin | LED_GREEN_RIGHT_Pin);
			timerBlinkTraffic = 25;
		}
	}
}
void displayGreenLed() {
	//static int counter;
	if (IsModifyGreenLeds()) {
		if (IsPressed(1)) {
			count.CountForGreenLed++;
		}
		displayLED7SEG_ABOVE(time.CounterGreen + count.CountForGreenLed);
		displayLED7SEG_RIGHT(3);
	}
}
void ChangeTime(counter *time, int addRed, int addAmber, int addGreen) {
	time->CounterRed = time->CounterRed + addRed;
	time->CounterYellow = time->CounterYellow + addAmber;
	time->CounterGreen = time->CounterGreen + addGreen;
}
void IncreaseTime() {
	if (time.CounterRed + count.CountForRedLed
			== (time.CounterYellow + count.CountForAmberLed + time.CounterGreen
					+ count.CountForGreenLed)) {
		ChangeTime(&time, count.CountForRedLed, count.CountForAmberLed,
				count.CountForGreenLed);
		InitCount();
	} else {
		InitCount();
	}
}

void BlinkTraffic() {
	displayBlinkRedLed();
	displayBlinkAmberLed();
	displayBlinkGreenLed();
}

void fsm_manual() {
	displayRedLed();
	displayGreenLed();
	displayAmberLed();
	if (IsPressed(2)) {
		IncreaseTime();
	}
}

void displayLED7SEG_RIGHT(int number) {

	int divPart = number / 10;
	int modPart = number % 10;

	// CONVERT TO BINARY
	int arr_1[4] = { 0, 0, 0, 0 };
	int arr_2[4] = { 0, 0, 0, 0 };

	switch (divPart) {
	case 0:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 1:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	case 2:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 1;
		arr_1[3] = 0;
		break;
	case 3:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 1;
		arr_1[3] = 1;
		break;
	case 4:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 5:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	case 6:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 1;
		arr_1[3] = 0;
		break;
	case 7:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 1;
		arr_1[3] = 1;
		break;
	case 8:
		arr_1[0] = 1;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 9:
		arr_1[0] = 1;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	}

	switch (modPart) {
	case 0:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 1:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	case 2:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 1;
		arr_2[3] = 0;
		break;
	case 3:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 1;
		arr_2[3] = 1;
		break;
	case 4:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 5:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	case 6:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 1;
		arr_2[3] = 0;
		break;
	case 7:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 1;
		arr_2[3] = 1;
		break;
	case 8:
		arr_2[0] = 1;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 9:
		arr_2[0] = 1;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	}

	HAL_GPIO_WritePin(GPIOA, IN1_SEG1_Pin, arr_1[3]);
	HAL_GPIO_WritePin(GPIOA, IN2_SEG1_Pin, arr_1[2]);
	HAL_GPIO_WritePin(GPIOA, IN3_SEG1_Pin, arr_1[1]);
	HAL_GPIO_WritePin(GPIOA, IN4_SEG1_Pin, arr_1[0]);

	HAL_GPIO_WritePin(GPIOA, IN1_SEG2_Pin, arr_2[3]);
	HAL_GPIO_WritePin(GPIOA, IN2_SEG2_Pin, arr_2[2]);
	HAL_GPIO_WritePin(GPIOA, IN3_SEG2_Pin, arr_2[1]);
	HAL_GPIO_WritePin(GPIOA, IN4_SEG2_Pin, arr_2[0]);
}

void displayLED7SEG_ABOVE(int number) {

	int divPart = number / 10;
	int modPart = number % 10;

	// CONVERT TO BINARY
	int arr_1[4] = { 0, 0, 0, 0 };
	int arr_2[4] = { 0, 0, 0, 0 };

	switch (divPart) {
	case 0:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 1:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	case 2:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 1;
		arr_1[3] = 0;
		break;
	case 3:
		arr_1[0] = 0;
		arr_1[1] = 0;
		arr_1[2] = 1;
		arr_1[3] = 1;
		break;
	case 4:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 5:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	case 6:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 1;
		arr_1[3] = 0;
		break;
	case 7:
		arr_1[0] = 0;
		arr_1[1] = 1;
		arr_1[2] = 1;
		arr_1[3] = 1;
		break;
	case 8:
		arr_1[0] = 1;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 0;
		break;
	case 9:
		arr_1[0] = 1;
		arr_1[1] = 0;
		arr_1[2] = 0;
		arr_1[3] = 1;
		break;
	}

	switch (modPart) {
	case 0:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 1:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	case 2:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 1;
		arr_2[3] = 0;
		break;
	case 3:
		arr_2[0] = 0;
		arr_2[1] = 0;
		arr_2[2] = 1;
		arr_2[3] = 1;
		break;
	case 4:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 5:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	case 6:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 1;
		arr_2[3] = 0;
		break;
	case 7:
		arr_2[0] = 0;
		arr_2[1] = 1;
		arr_2[2] = 1;
		arr_2[3] = 1;
		break;
	case 8:
		arr_2[0] = 1;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 0;
		break;
	case 9:
		arr_2[0] = 1;
		arr_2[1] = 0;
		arr_2[2] = 0;
		arr_2[3] = 1;
		break;
	}

	HAL_GPIO_WritePin(GPIOA, IN1_SEG3_Pin, arr_1[3]);
	HAL_GPIO_WritePin(GPIOA, IN2_SEG3_Pin, arr_1[2]);
	HAL_GPIO_WritePin(GPIOA, IN3_SEG3_Pin, arr_1[1]);
	HAL_GPIO_WritePin(GPIOA, IN4_SEG3_Pin, arr_1[0]);

	HAL_GPIO_WritePin(GPIOB, IN1_SEG4_Pin, arr_2[3]);
	HAL_GPIO_WritePin(GPIOB, IN2_SEG4_Pin, arr_2[2]);
	HAL_GPIO_WritePin(GPIOB, IN3_SEG4_Pin, arr_2[1]);
	HAL_GPIO_WritePin(GPIOB, IN4_SEG4_Pin, arr_2[0]);
}
