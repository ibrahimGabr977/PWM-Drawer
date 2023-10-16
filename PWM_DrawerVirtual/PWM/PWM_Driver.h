/*
 * PWM_Driver.h
 *
 *  Created on: Sep 30, 2023
 *      Author: Lenovo
 */

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include "main.h"


#define OC_DIR DDRD
#define OC PD5
#define OC_PIN PIND

#define TCCRA TCCR1A
#define TCCRB TCCR1B

//PWM mode 2 pins and prescaler
#define WGM1 WGM10      //OC1A
#define WGM2 WGM12      //OC1B
#define CS CS10
#define COM COM1A1
#define OCR OCR1A

#define INITIAL_DUTY 128
#define MIN_DUTY 0
#define MAX_DUTY 256



void PWM_init();
void PWM_SetDutyCycle(u8 duty_cycle);
u8 PWM_isSignalHigh();
void PWM_createSignalsSeries(u16* signals_series, u8 series_length);
u16 PWM_getDutyCycle();
f32 PWM_get_frequency(u16 prescaler);
f32 PWM_get_time(u16 prescaler);


#endif /* PWM_DRIVER_H_ */
