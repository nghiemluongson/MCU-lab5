/*
 * command_parser_fsm.h
 *
 *  Created on: Dec 14, 2022
 *      Author: 84336
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_

#include "main.h"
#include "software_timer.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define MAX_BUFFER_SIZE 30

#define COM_INIT		1
#define UART_INIT		11

#define START_CHAR 	2 // !
#define R_CHAR 		3
#define S_CHAR 		4
#define T_CHAR 		5
#define O_CHAR 		6
#define K_CHAR 		7
#define END_CHAR 	8 // #

#define SENDING_MESSAGE 9
#define WAITING 		10
#define ENDING_SYSTEM 	11

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t com_flag;
extern uint8_t com_status;
extern uint8_t uart_status;
extern uint8_t strout[20];

void command_parser_fsm(ADC_HandleTypeDef);

#endif /* INC_COMMAND_PARSER_FSM_H_ */
