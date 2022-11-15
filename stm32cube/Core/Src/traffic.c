/*
 * traffic.c
 *
 *  Created on: Nov 14, 2022
 *      Author: USER
 */
#include "traffic.h"

void set_traffic1_red(){
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(x1_GPIO_Port, x1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(v1_GPIO_Port, v1_Pin, GPIO_PIN_SET);
}

void set_traffic2_red(){
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(x2_GPIO_Port, x2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(v2_GPIO_Port, v2_Pin, GPIO_PIN_SET);
}

void set_traffic1_green(){
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(x1_GPIO_Port, x1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(v1_GPIO_Port, v1_Pin, GPIO_PIN_SET);
}

void set_traffic2_green(){
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(x2_GPIO_Port, x2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(v2_GPIO_Port, v2_Pin, GPIO_PIN_SET);
}

void set_traffic1_yellow(){
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(x1_GPIO_Port, x1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(v1_GPIO_Port, v1_Pin, GPIO_PIN_RESET);
}

void set_traffic2_yellow(){
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(x2_GPIO_Port, x2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(v2_GPIO_Port, v2_Pin, GPIO_PIN_RESET);
}

void toggle_traffic_red(){
	HAL_GPIO_TogglePin(d1_GPIO_Port, d1_Pin);
	HAL_GPIO_TogglePin(d2_GPIO_Port, d2_Pin);
}

void toggle_traffic_green(){
	HAL_GPIO_TogglePin(x1_GPIO_Port, x1_Pin);
	HAL_GPIO_TogglePin(x2_GPIO_Port, x2_Pin);
}

void toggle_traffic_yellow(){
	HAL_GPIO_TogglePin(v1_GPIO_Port, v1_Pin);
	HAL_GPIO_TogglePin(v2_GPIO_Port, v2_Pin);
}


