/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

//typedef enum {
//	IDLE, DEBOUNCE, PRESSED, LONGPRESSED
//} ButtonState;
//
//typedef struct {
//	int KeyReg0;
//	int KeyReg1;
//	int KeyReg2;
//	int KeyReg3;
//	GPIO_TypeDef *GPIOx;
//	uint16_t GPIO_Pin;
//	ButtonState state;
//	int FlagPressed;
//} ButtonX;
//extern ButtonX button[3];
int IsPressed();
void InitThreeButton();
void getKeyInput();
#endif /* INC_BUTTON_H_ */
