/*
 * Ultrasonic_sensor _HC-SR04.c
 *
 *  Created on: Oct 18, 2022
 *      Author: abdoa
 */
#include "macros.h"
#include "ICU.h"
#include "Ultrasonic_sensor _HC-SR04.h"
#include "GPIO.h"
#include "util/delay.h"

ICU_config config ={rising,F_CPU_8};
u8 icu_counter=0;
u16 icu_timer_value=0;

void Ultrasonic_init(){
	ICU_init(&config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	pinMode(Trigger_port_id, Trigger_pin_id, OUTPUT);

}
void Ultrasonic_Trigger(){
	pinWrite(Trigger_port_id, Trigger_pin_id, HIGH);
	_delay_us(11);
	pinWrite(Trigger_port_id, Trigger_pin_id, LOW);
}
u16 Ultrasonic_readDistance(){
	Ultrasonic_Trigger();
	icu_counter=0;
	icu_timer_value=0;
	while(icu_counter!=2){}

	u16 distance = icu_timer_value/117;//
/*Sound velocity = 340.00 m/s = 34000 cm/s The distance of Object (in cm) = (340000∗Time)/2 = 17000 * Time
Total distance is divided by 2 because signal travels from HC-SR04 to object and returns to the module HC-SR-04.
Now, here we have selected an internal 16MHz oscillator frequency for ATmega32, with Prescaler F_CPU/8 for timer frequency.

= 17000 x (TIMER value) x 5 x 10^-7 cm
= 0.0085 x (TIMER value) cm
distance (cm)= (TIMER value) / 117 cm*/
	return distance;
}
void Ultrasonic_edgeProcessing(){
	icu_counter++;
	if(icu_counter==1){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(falling);
	}
	else if(icu_counter==2){
		icu_timer_value=ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(rising);

	}
}
