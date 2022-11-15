/*
 * led7seg.h
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include "timer.h"

void updateBuffer7SEG(int, int);
void update7SEG(int);
void display7SEG(int);
void scan7SEG();

#endif /* INC_LED7SEG_H_ */
