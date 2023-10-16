/*
 * WaveDrawer.c
 *
 *  Created on: Sep 30, 2023
 *      Author: Lenovo
 */



#include "WaveDrawer.h"





const u8 vInver_L[] = {
    0b11111,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000
};


const u8 hInver_vInver_L[] = {
    0b11111,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001
};




const u8 upperscore[] = {
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};


const u8 underscore[] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
	0b11111,
    0b00000

};

const u8 custom_N[] = {
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
	0b10001,
    0b10001

};



void WaveDrawer_init(){

	WaveDrawer_LCD_init();

	PWM_init();

	PWM_SetDutyCycle(INITIAL_DUTY); //test 50%


}



static void WaveDrawer_LCD_init(){
	LCD_init();
	LCD_create_custom_char(VER_INVER_L_ADDRESS, vInver_L);
	LCD_create_custom_char(HORI_INVER_OF0_ADDRESS, hInver_vInver_L);
	LCD_create_custom_char(UPPERSCORE_ADDRESS, upperscore);
	LCD_create_custom_char(MUNDERSCORE_ADDRESS, underscore);
	LCD_create_custom_char(CUSTOM_N_ADDRESS, custom_N);



}

void WaveDrawer_displayInfo(){
	displayWaveFrequency();
	displayWaveDutyCycle();
	displayWaveTime();
}


static void displayWaveFrequency(){
	LCD_set_cursor(0, 0);
	LCD_write_string("F:");
	LCD_write_decimal_number(PWM_get_frequency(1), 2);
	LCD_write_string("KHz");

}
static void displayWaveDutyCycle(){
	LCD_set_cursor(0, 14);
	LCD_write_string("DC:");
	LCD_write_number((u8)round(((PWM_getDutyCycle()*1.0 / MAX_DUTY*1.0))*100.0));
	LCD_write_char('%');
}
static void displayWaveTime(){
	LCD_set_cursor(1, 0);
	LCD_write_string("T:");
	LCD_write_decimal_number(PWM_get_time(1), 3);
	LCD_write_string("ms");
}




//Simulation version for 4*20 LCD
void WaveDrawer_draw(u16* ss){

	LCD_set_cursor(2, 0);
	for(u8 i = 0; i < LCD_COLS; i++){
		LCD_write_char(ss[i] == HIGH? '1' : '0');
	}




	LCD_set_cursor(3, 0);

	for(u8 i = 0; i < LCD_COLS; i++){
		if((ss[i-1] == LOW && ss[i] == HIGH && ss[i+1] == LOW)){     //LOW_TO_HIGH_TO_LOW case on middle of screen

			LCD_write_custom_char(CUSTOM_N_ADDRESS);


		}else if(ss[i] == HIGH && ss[i+1] == LOW){                   //HIGH_TO_LOW case on middle of screen

			LCD_write_custom_char(HORI_INVER_OF0_ADDRESS);


		}else if(ss[i-1] == LOW && ss[i] == HIGH){                   //LOW_TO_HIGH case on middle of the screen
			LCD_write_custom_char(VER_INVER_L_ADDRESS);


		}else if(ss[i] == HIGH){                                     //other HIGH cases
			LCD_write_custom_char(UPPERSCORE_ADDRESS);

		}else{                                                       //other low cases
			LCD_write_custom_char(MUNDERSCORE_ADDRESS);
		}
	}


}





