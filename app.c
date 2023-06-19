#include<avr/io.h>
#include "Ultrasonic_sensor _HC-SR04.h"
#include "macros.h"
#include <util/delay.h>
#include "uart.h"
#include "MotorDriver.h"
#include "Buzzer.h"
#include "servo.h"
u8 choice;
void rc_car_mode(){
	u8 input;
	input=UART_recieveByte();//change uart make it bluetooth
	switch(input){
	case 'F':
		forward();
		break;
	case 'B':
		backward();
		break;
	case 'L':
		left();
		break;
	case 'R':
		right();
		break;
	case 'G':
		left();
		_delay_ms(50);
		forward();
		_delay_ms(50);
		break;
	case 'I':
		right();
		_delay_ms(50);
		forward();
		_delay_ms(50);
		break;
	case 'H':
		left();
		_delay_ms(50);
		backward();
		_delay_ms(50);
		break;
	case 'J':
		right();
		_delay_ms(50);
		backward();
		_delay_ms(50);
		break;
	case 'S':
		stop();
		break;
	/*case '1':
		T0_PWM(10);-->100;*/
	case 'V':
		Buzzer_on();
		break;
	case 'v':
		Buzzer_off();
		break;
	case'w':
		choice='w';
		break;
	default:
		stop();
		break;

	}

}

int main(){
	UART_init(9600);
	Driver();
	Buzzer_init();
	choice = UART_recieveByte();
	while(1){
		/*switch(choice){
		case'W':
			rc_car_mode();
			break;
		case'w':
///////////////////
			break;
		}*/
		rc_car_mode();

	}
/*
	UART_init(9600);
	DDRC=0XFF;
	PORTC=0XFF;
	_delay_ms(3000);
	PORTC=0;

	while(1){

		if(UART_recieveByte()=='F'){
			PORTC=0XFF;
		}
		else if(UART_recieveByte()=='B'){
			PORTC=0;
		}
	}
	Servo_Init();
	Servo_SetAngle(zero_angle);
	_delay_ms(3000);
	Servo_SetAngle(150);
	_delay_ms(3000);


	while(1){


	}*/

}
