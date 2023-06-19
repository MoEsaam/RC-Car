/*
 * timer.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */


#include <avr/io.h>
#include "macros.h"
#include "GPIO.h"
#include "timer.h"





void T0_init(){

	OCR0=0;
	DDRB  = DDRB | (1<<PB3);
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<CS01)|(1<<COM01);
}

void T0_PWM(u8 duty_cycle){

	OCR0 = (u8)(((u32)(duty_cycle*255))/100);

}


void T2_init(){

	OCR2=0;
	DDRD  = DDRD | (1<<PD7);
	TCCR2=(1<<WGM20)|(1<<WGM21)|(1<<CS21)|(1<<CS22)|(1<<COM21);
}

void T2_PWM(u8 duty_cycle){

	OCR2 = duty_cycle;

}
