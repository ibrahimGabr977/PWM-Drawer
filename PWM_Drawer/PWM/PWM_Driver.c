/*
 * PWM_Driver.c
 *
 *  Created on: Sep 30, 2023
 *      Author: Lenovo
 */


#include "PWM_Driver.h"

void PWM_init() {

    // Set OC1A (PD5) as an output
    SET_BIT(OC_DIR, OC);

    // Configure Timer1 for Fast PWM mode, 8-bit
    SET_BIT(TCCRA, WGM1);
    SET_BIT(TCCRB, WGM2);
    SET_BIT(TCCRB, CS);


    // Set OC1A (PB1) to non-inverted PWM
    SET_BIT(TCCRA, COM);
}

void PWM_SetDutyCycle(u8 duty_cycle) {
    // Set the duty cycle by writing to OCR1A
	if(duty_cycle > MAX_DUTY){
			duty_cycle = MAX_DUTY;
	}

    if(duty_cycle < MIN_DUTY){
			duty_cycle = MIN_DUTY;
    }

    OCR = duty_cycle;
}


u8 PWM_isSignalHigh(){
	return GET_BIT(OC_PIN, OC);
}


void PWM_createSignalsSeries(u16* signals_series, u8 series_length){
	for(u8 i = 0; i<series_length; i++){
		signals_series[i] = (PWM_isSignalHigh()? HIGH : LOW);
	}
}


u16 PWM_getDutyCycle(){
	return OCR;
}

f32 PWM_get_frequency(u16 prescaler) {
	 return ((double)F_CPU / (prescaler * 256.0)) / 1000.0;
}

f32 PWM_get_time(u16 prescaler) {
    return 1.0 / PWM_get_frequency(prescaler);
}
