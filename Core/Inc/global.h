/*
 * global.h
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"

typedef struct {
	int CounterRed;
	int CounterYellow;
	int CounterGreen;
	int count;
	int direction;
} counter;

typedef enum {
	IDLE, DEBOUNCE, PRESSED, LONGPRESSED
} ButtonState;

typedef struct {
	int KeyReg0;
	int KeyReg1;
	int KeyReg2;
	int KeyReg3;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	ButtonState state;
	int FlagPressed;
} ButtonX;
extern counter time;
extern ButtonX button[3];
extern int timer1_flag;
extern int timer1_counter;
extern int timerBlinkTraffic_flag;
extern int timerBlinkTraffic;
#endif /* INC_GLOBAL_H_ */
