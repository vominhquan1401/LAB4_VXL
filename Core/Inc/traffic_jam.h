/*
 * traffic_jam.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_JAM_H_
#define INC_TRAFFIC_JAM_H_

#include "main.h"
#include "global.h"

void fsm_automatic();
void trafficNormal(counter *time);
void checkTime();
void setTimeForTraffic(counter *time, int red, int yellow, int green);

#endif /* INC_TRAFFIC_JAM_H_ */
