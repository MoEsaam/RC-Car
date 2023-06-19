/*
 * servo.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_SERVO_H_
#define BASE_SERVO_H_
#include "macros.h"
#define Startup 19999
#define FAST_PWM_ICR1 14
#define FAST_PWM_OCR1A 15
#define Normal 0
#define Toggle 1
#define CLEAR 2
#define SET 3
#define zero_angle 93
#define n_ninty_angle 60
#define p_ninty_angle 125


void Servo_Init();
void Servo_SetAngle(u16 i);


#endif /* BASE_SERVO_H_ */
