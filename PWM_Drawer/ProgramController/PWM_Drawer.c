/*
 * PWM_Drawer.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Lenovo
 */

#include "PWM_Drawer.h"



const u16 signals_series[LCD_COLS];
u16 duty_cycle = INITIAL_DUTY;


void PWM_Drawer_startProgram(){
	init();

	startDrawing();
	 while (1) {



		 if(isIncreaseDutyCycleButtonClicked()){

			 updateDisplayWithNewDutyCycle(INCREASE);

			 while(isIncreaseDutyCycleButtonClicked());



		 }

		 if (isDecreaseDutyCycleButtonClicked()){

			 updateDisplayWithNewDutyCycle(DECREASE);



			 while(isDecreaseDutyCycleButtonClicked());
		 }



		 if (isReDrawButtonClicked()){

		    updateDisplayWithNewDutyCycle(REDRAW);



			while(isReDrawButtonClicked());
	     }
	 }
}


static void init(){
	WaveDrawer_init();
	PWM_createSignalsSeries(signals_series, LCD_COLS);

	initControllersButtons();
}



static void initControllersButtons(){
	CLR_BIT(CONTROLLERS_DDR, INCREASE_BUTTON_BIT);
	CLR_BIT(CONTROLLERS_DDR, DECREASE_BUTTON_BIT);
	CLR_BIT(REDRAW_BUTTON_DDR, REDRAW_BUTTON_BIT);

	SET_BIT(CONTROLLERS_PORT, INCREASE_BUTTON_BIT);
	SET_BIT(CONTROLLERS_PORT, DECREASE_BUTTON_BIT);
	SET_BIT(REDRAW_BUTTON_PORT, REDRAW_BUTTON_BIT);
}



static u8 isIncreaseDutyCycleButtonClicked(){
	return GET_BIT(CONTROLLERS_PIN, INCREASE_BUTTON_BIT);

}


static u8 isDecreaseDutyCycleButtonClicked(){
	return GET_BIT(CONTROLLERS_PIN, DECREASE_BUTTON_BIT);
}


static u8 isReDrawButtonClicked(){
	return GET_BIT(REDRAW_BUTTON_PIN, REDRAW_BUTTON_BIT);
}


//update duty cycle by percentage for example by 5%
static void updateDisplayWithNewDutyCycle(s8 direction){
	u16 newDuty = PWM_getDutyCycle() +(direction * (MAX_DUTY *(BOOST_STEP/100.0)));

	PWM_SetDutyCycle(newDuty);

	PWM_createSignalsSeries(signals_series, LCD_COLS);
	_delay_ms(1);
	startDrawing();

}





static void startDrawing(){
	WaveDrawer_displayInfo();
	WaveDrawer_draw(signals_series);

}
