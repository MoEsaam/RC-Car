/*
 * Ultrasonic_sensor _HC-SR04.h
 *
 *  Created on: Oct 18, 2022
 *      Author: abdoa
 */

#ifndef ULTRASONIC_SENSOR__HC_SR04_H_
#define ULTRASONIC_SENSOR__HC_SR04_H_
#include "macros.h"

#define Trigger_port_id B
#define Trigger_pin_id PIN5


void Ultrasonic_init();
void Ultrasonic_Trigger();
u16 Ultrasonic_readDistance();
void Ultrasonic_edgeProcessing();


#endif /* ULTRASONIC_SENSOR__HC_SR04_H_ */
