/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: 84336
 */
#include "command_parser_fsm.h"

uint32_t ADC_value;
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t com_status = 0;
uint8_t uart_status = 0;
uint8_t strout[20];
uint8_t com_flag = 0;

void command_parser_fsm(ADC_HandleTypeDef hadc1) {
	switch (com_status) {

	case COM_INIT:
		if (buffer[index_buffer - 1] == '!') {
			com_status = START_CHAR;
		}
		break;

	case START_CHAR:
		if (buffer[index_buffer - 1] == 'R') {
			com_status = R_CHAR;
		}
		else if (buffer[index_buffer - 1] == 'O') {
			com_status = O_CHAR;
		}
		else if (buffer[index_buffer - 1] == '!') {
			com_status = START_CHAR;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case R_CHAR:
		if (buffer[index_buffer - 1] == 'S') {
			com_status = S_CHAR;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case S_CHAR:
		if (buffer[index_buffer - 1] == 'T') {
			com_status = T_CHAR;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case T_CHAR:
		if (buffer[index_buffer - 1] == '#') {
			com_status = END_CHAR;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case END_CHAR:
		HAL_ADC_Start(&hadc1);
		ADC_value = HAL_ADC_GetValue(&hadc1);
		sprintf(strout, "!ADC=%ld#\r\n", ADC_value);
		com_flag = 1;
		com_status = COM_INIT;
		break;

	case O_CHAR:
		if (buffer[index_buffer - 1] == 'K') {
			com_status = K_CHAR;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case K_CHAR:
		if (buffer[index_buffer - 1] == '#') {
			com_status = ENDING_SYSTEM;
		}
		else {
			com_status = COM_INIT;
		}
		break;

	case ENDING_SYSTEM:
		com_flag = 0;
		buffer_flag = 0;
		com_status = COM_INIT;
		break;

	default:
		break;
	}
}

