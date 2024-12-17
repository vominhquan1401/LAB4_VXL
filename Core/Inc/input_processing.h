/*
 * input_processing.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "button.h"

int IsNormalMode();
int IsModifyRedLeds();
int IsModifyAmberLeds();
int IsModifyGreenLeds();
void fsm_setting(void);
#endif /* INC_INPUT_PROCESSING_H_ */
