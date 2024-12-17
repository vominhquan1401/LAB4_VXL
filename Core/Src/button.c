/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#include "button.h"

//ButtonX button[3];
void ButtonInit(ButtonX *button, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	button->state = IDLE;
	button->KeyReg0 = NORMAL_STATE;
	button->KeyReg1 = NORMAL_STATE;
	button->KeyReg2 = NORMAL_STATE;
	button->KeyReg3 = NORMAL_STATE;
	button->GPIOx = GPIOx;
	button->GPIO_Pin = GPIO_Pin;
	button->FlagPressed = 0;
}
void InitThreeButton() {
	ButtonInit(&button[0], GPIOB, BTN1_Pin);
	ButtonInit(&button[1], GPIOB, BTN2_Pin);
	ButtonInit(&button[2], GPIOB, BTN3_Pin);
}

int TimeForKeyPress = 100;
int FlagCheckLongPressFirst = 0;
int IsPressed(int index) {
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	if (button[index].FlagPressed) {
		button[index].FlagPressed = 0;
		return 1;
	}
	return 0;
}

void LongPressed() {
	//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
}

void getInput(ButtonX *button) {
	button->KeyReg0 = button->KeyReg1;
	button->KeyReg1 = button->KeyReg2;
	button->KeyReg2 = HAL_GPIO_ReadPin(button->GPIOx, button->GPIO_Pin);

	switch (button->state) {
	case IDLE:
		if (button->KeyReg2 == PRESSED_STATE) {
			button->state = DEBOUNCE;
		}
		//break;
	case DEBOUNCE:
		if ((button->KeyReg0 == button->KeyReg1)
				&& (button->KeyReg1 == button->KeyReg2)) { //ổn định
			if (button->KeyReg3 != button->KeyReg2) {
				button->KeyReg3 = button->KeyReg2;
				if (button->KeyReg2 == PRESSED_STATE) {
					button->state = PRESSED;
					button->FlagPressed = 1;
					TimeForKeyPress = 100;
				}
			}
		} else {
			button->state = IDLE;
		}
		break;

	case PRESSED:
		if (button->KeyReg2 == NORMAL_STATE) {
			button->state = IDLE;
		} else {
			TimeForKeyPress--;
			if (TimeForKeyPress == 0) {
				if (button->KeyReg2 == PRESSED_STATE) {
					button->state = LONGPRESSED;
					FlagCheckLongPressFirst = 1;
				}
				TimeForKeyPress = 100;
			}
		}
		break;
	case LONGPRESSED:
		if (FlagCheckLongPressFirst) {
			LongPressed();
			FlagCheckLongPressFirst = 0;
		}
		if (button->KeyReg2 == NORMAL_STATE) {
			button->state = IDLE;
		} else {
			TimeForKeyPress--;
			if (TimeForKeyPress == 0) {
				LongPressed();
				TimeForKeyPress = 100;
			}
		}
		break;
	}
}

void getKeyInput() {
	getInput(&button[0]);
	getInput(&button[1]);
	getInput(&button[2]);
}

