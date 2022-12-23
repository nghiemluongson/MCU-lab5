/*
 * uart_communication_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: 84336
 */
#include "uart_communication_fsm.h"

void uart_communication_fsm(UART_HandleTypeDef huart2) {
	switch (uart_status) {

	case UART_INIT:
		if (com_flag == 1) {
			uart_status = SENDING_MESSAGE;
		}
		break;

	case SENDING_MESSAGE:
		HAL_UART_Transmit(&huart2, (void *) strout, 20, 1000);
		SetTimer1(3000);
		uart_status = WAITING;
		break;

	case WAITING:
		if (timer1_flag == 1) {
			uart_status = SENDING_MESSAGE;
		}
		if (com_flag == 0) {
			uart_status = UART_INIT;
		}
		break;

	default:
		break;
	}
}

