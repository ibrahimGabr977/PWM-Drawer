/*
 * PWM_Drawer.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Lenovo
 */

#ifndef PWM_DRAWER_H_
#define PWM_DRAWER_H_

#include "WaveDrawer/WaveDrawer.h"

#define CONTROLLERS_DDR DDRD
#define CONTROLLERS_PIN PIND
#define CONTROLLERS_PORT PORTD
#define INCREASE_BUTTON_BIT PD2
#define DECREASE_BUTTON_BIT PD6

#define REDRAW_BUTTON_DDR DDRB
#define REDRAW_BUTTON_PORT PORTB
#define REDRAW_BUTTON_PIN PINB
#define REDRAW_BUTTON_BIT PB0


#define INCREASE 1
#define DECREASE -1
#define REDRAW 0
#define BOOST_STEP 5.0

void PWM_Drawer_startProgram();
static void init();
static void initControllersButtons();
static u8 isIncreaseDutyCycleButtonClicked();
static u8 isDecreaseDutyCycleButtonClicked();
static u8 isReDrawButtonClicked();
static void updateDisplayWithNewDutyCycle(s8 direction);
static void startDrawing();
#endif /* PWM_DRAWER_H_ */
