/*
 * button.h
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "timer.h"

#define NO_OF_BUTTONS 3
#define TIME_KEY_PRESSED 200
#define WAITING_TIME 1000

#define PRESSED_STATE 0
#define RELEASED_STATE 1

#define BUTTON_IS_PRESSED 100
#define BUTTON_IS_RELEASED 102
#define BUTTON_IS_LONG_PRESSED 103

void button_reading();
void button_process(int);
int isButtonPressed(int);

#endif /* INC_BUTTON_H_ */
