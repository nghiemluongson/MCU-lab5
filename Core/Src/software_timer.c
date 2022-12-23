/*
 * software_timer.c
 *
 *  Created on: Dec 14, 2022
 *      Author: 84336
 */
#include "software_timer.h"

int timer1_flag = 0, timer1_counter = 0;

void SetTimer1 (int duration) {
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

void TimerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}

