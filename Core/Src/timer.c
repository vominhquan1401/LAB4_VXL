/*
 * timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#include "timer.h"

//int timer1_counter = 0;
//int timer1_flag = 0;

void setTimer1(int duration) {
	timer1_counter = duration / 10;
	timer1_flag = 0;
}

void timerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;

		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
	if (timerBlinkTraffic > 0) {
		timerBlinkTraffic--;

		if (timerBlinkTraffic <= 0) {
			timerBlinkTraffic_flag = 1;
		}
	}
}


