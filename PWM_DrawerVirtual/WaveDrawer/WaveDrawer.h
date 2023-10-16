/*
 * WaverDrawer.h
 *
 *  Created on: Oct 5, 2023
 *      Author: Lenovo
 */

#ifndef WAVEDRAWER_WAVEDRAWER_H_
#define WAVEDRAWER_WAVEDRAWER_H_

#include "LCD/LCD_Driver.h"
#include "PWM/PWM_Driver.h"

#define VER_INVER_L_ADDRESS 1030
#define HORI_INVER_OF0_ADDRESS 1031
#define UPPERSCORE_ADDRESS 1032
#define MUNDERSCORE_ADDRESS 1033
#define CUSTOM_N_ADDRESS 1034





void WaveDrawer_init();
static void WaveDrawer_LCD_init();
void WaveDrawer_displayInfo();
static void displayWaveFrequency();
static void displayWaveDutyCycle();
static void displayWaveTime();
void WaveDrawer_draw(u16* signals_series);

#endif /* WAVEDRAWER_WAVEDRAWER_H_ */
