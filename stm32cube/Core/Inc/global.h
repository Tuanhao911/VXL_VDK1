/*
 * global.h
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"

#define INIT		1

#define AUTO_RED1	2
#define AUTO_RED2	3
#define AUTO_GREEN	4
#define AUTO_YELLOW 5

#define MAN_RED 	10
#define MAN_GREEN	11
#define MAN_YELLOW	12

#define BLINKY_TIME	500

extern int status;

extern int config_red;
extern int config_green;
extern int config_yellow;

extern int counter_red;
extern int counter_green;
extern int counter_yellow;

#endif /* INC_GLOBAL_H_ */
