/*
 * led7seg.c
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */

#include "led7seg.h"

int led_buffer[4] = {0,0,0,0};
int led_index = 0;

void updateBuffer7SEG(int first, int second){
	led_buffer[0] = first/10;
	led_buffer[1] = first%10;
	led_buffer[2] = second/10;
	led_buffer[3] = second%10;
}

void update7SEG(int index){
	if(index < 0 || index >= 4) return;
	HAL_GPIO_WritePin(GPIOB, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
	display7SEG(led_buffer[index]);
	switch(index){
	case 0:
		HAL_GPIO_WritePin(GPIOB, EN0_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, EN1_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, EN2_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, EN3_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void display7SEG(int num){
	HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin|dd_Pin
							|ee_Pin|ff_Pin|gg_Pin, GPIO_PIN_SET);
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin|dd_Pin
								|ee_Pin|ff_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, bb_Pin|cc_Pin, GPIO_PIN_RESET);
	break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|dd_Pin|ee_Pin
								|gg_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin|dd_Pin
								|gg_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, bb_Pin|cc_Pin|ff_Pin|gg_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|cc_Pin|dd_Pin|ff_Pin
								|gg_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|cc_Pin|dd_Pin|ee_Pin
								|ff_Pin|gg_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin|dd_Pin
								|ee_Pin|ff_Pin|gg_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, aa_Pin|bb_Pin|cc_Pin|dd_Pin
								|ff_Pin|gg_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void scan7SEG(){
	if(timer3_flag == 1){
		if(led_index >= 4) led_index = 0;
		update7SEG(led_index++);
		setTimer3(100);
	}
}
