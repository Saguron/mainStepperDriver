/*
 * funkcje.c
 *
 *  Created on: Nov 17, 2024
 *      Author: milos
 */
#include "funkcje.h"


void ResetDriver(void){
	HAL_GPIO_WritePin(DRV_RESET_GPIO_Port, DRV_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(DRV_RESET_GPIO_Port, DRV_RESET_Pin, GPIO_PIN_RESET);
}
void Write_Reg(uint8_t* reg_in){
//chip select stan niski, koniec transferu
	  HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);//chip select aktywny
		HAL_SPI_Transmit(&hspi1, reg_in, 2, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_RESET);
}
