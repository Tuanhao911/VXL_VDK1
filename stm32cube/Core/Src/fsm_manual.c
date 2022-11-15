/*
 * fsm_manual.c
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status) {
		case MAN_RED:

			if(timer1_flag == 1){
				toggle_traffic_red();
				setTimer1(BLINKY_TIME);
			}
			if(isButtonPressed(1) == 1){
				counter_red++;
				if(counter_red > 99) counter_red = 2;
				updateBuffer7SEG(1, counter_red);
			}

			if(isButtonPressed(2) == 1){
				config_red = counter_red;
				if(config_red <= config_green){
					config_green = config_red - 1;
				}
				config_yellow = config_red - config_green;
			}

			if(isButtonPressed(0) == 1){
				status = MAN_GREEN;
				set_traffic1_green();
				set_traffic2_green();
				setTimer1(BLINKY_TIME);
				counter_green = config_green;
				updateBuffer7SEG(2, counter_green);
			}
			break;
		case MAN_GREEN:

			if(timer1_flag == 1){
				toggle_traffic_green();
				setTimer1(BLINKY_TIME);
			}

			if(isButtonPressed(1) == 1){
				counter_green++;
				if(counter_green >= config_red) counter_green = 1;
				updateBuffer7SEG(2, counter_green);
			}

			if(isButtonPressed(2) == 1){
				config_green = counter_green;
				config_yellow = config_red - config_green;
			}

			if(isButtonPressed(0) == 1){
				status = MAN_YELLOW;
				set_traffic1_yellow();
				set_traffic2_yellow();
				setTimer1(BLINKY_TIME);
				counter_yellow = config_yellow;
				updateBuffer7SEG(3, counter_yellow);
			}
			break;
		case MAN_YELLOW:

			if(timer1_flag == 1){
				toggle_traffic_yellow();
				setTimer1(BLINKY_TIME);
			}

			if(isButtonPressed(1) == 1){
				counter_yellow++;
				if(counter_yellow >= config_red) counter_yellow = 1;
				updateBuffer7SEG(3, counter_yellow);
			}

			if(isButtonPressed(2) == 1){
				config_yellow = counter_yellow;
				config_green = config_red - config_yellow;
			}

			if(isButtonPressed(0) == 1){
				status = AUTO_RED1;
				setTimer1(config_green*1000);
				setTimer2(1000);
				counter_red = config_red;
				counter_green = config_green;
				updateBuffer7SEG(counter_red--, counter_green--);
			}
			break;
		default:
			break;
	}
}
