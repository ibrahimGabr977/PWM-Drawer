/*
 * Test_LCD.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Lenovo
 */




#include "LCD_Driver.h"


void LCD_init() {
  // // Set PA4 to PA7 as output for data bits
  SET_REG(LCD_DATA_DDR, LCD_DATA_MASK);

  SET_BIT(LCD_CONFIG_DDR, LCD_RS);
  SET_BIT(LCD_CONFIG_DDR, LCD_Rw);
  SET_BIT(LCD_CONFIG_DDR, LCD_E);


  // Initialize LCD in 4-bit mode
  _delay_ms(POWER_DELAY);             // Wait for power-up
  LCD_write_command(0x02);
  LCD_write_command(0x28); // 4-bit, 2-line mode
  LCD_write_command(0x0C); // Display on, cursor off
  LCD_clearScreen(); // Clear display
  LCD_write_command(0x06); // Entry mode: increment cursor, no shift
}



void LCD_write_command(u8 command) {


	prepareWriting(COMMAND);
	write(command);
  // Wait for the command to complete
	 _delay_us(CMD_DELAY);
}



void LCD_write_char(u8 char0) {

	prepareWriting(DATA);
	write(char0);
  // Wait for the data to be written
	 _delay_us(CMD_DELAY);
}


void LCD_write_string(const u8* str) {
    while (*str) {
        LCD_write_char(*str);
        str++;
    }
}







void LCD_write_number(u16 number) {
    // If the number is zero, send '0' to the LCD
    if (number == 0) {
    	LCD_write_char('0');
        return;
    }

    // Convert the number to a string
    char buffer[6]; // Assuming a 16-bit number can be up to 5 digits
    itoa(number, buffer, 10); // Convert number to ASCII string in base 10

    // Send each character of the string to the LCD
    for (int i = 0; buffer[i] != '\0'; i++) {
    	LCD_write_char(buffer[i]);
    }
}


void LCD_write_decimal_number(f64 number, u16 decimalPlaces){
    // Convert the double to a string with the desired number of decimal places
    char buffer[16]; // Adjust the size as needed
    dtostrf(number, 0, decimalPlaces, buffer); // Convert to string

    // Send each character of the string to the LCD
    for (int i = 0; buffer[i] != '\0'; i++) {

    	if(i == 0 && buffer[i] == '0'){
    	    continue;
    	}

    	LCD_write_char(buffer[i]);


    }
}


void LCD_set_cursor(u8 row, u8 col) {
    // Set the cursor position on the LCD
	uint8_t cursorAddress;
	    if (row == 0) {
	        cursorAddress = 0x80 + col; // First row
	    } else if (row == 1) {
	        cursorAddress = 0xC0 + col; // Second row
	    } else {
	        return;  // Invalid row
	    }
	    // Set the cursor address command
	    LCD_write_command(cursorAddress);
}




void LCD_create_custom_char(u16 char_num, const u8 *char_pattern) {
    // Set CGRAM address for the custom character
	LCD_write_command(0x40 | (char_num << 3));

    // Send the custom character pattern
    for (int i = 0; i < 8; i++) {
        LCD_write_char(char_pattern[i]);
    }

    // Return to DDRAM address
    LCD_write_command(0x80);
}

void LCD_write_custom_char(u16 char_num) {
    // Display the custom character
    LCD_write_char(char_num);
}









void prepareWriting(u8 mode){

	if(mode == DATA){
		SET_BIT(LCD_CONFIG_PORT, LCD_RS);
	}else{
		CLR_BIT(LCD_CONFIG_PORT, LCD_RS);
	}

   // Set R/W to 0 for write mode
	CLR_BIT(LCD_CONFIG_PORT, LCD_Rw);
}










void write(u8 data){

	   //enable writing
	   SET_BIT(LCD_CONFIG_PORT, LCD_E);

	  //send the first part of data
	  LCD_DATA_PORT = (LCD_DATA_PORT & ~LCD_DATA_MASK) | (data & LCD_DATA_MASK);
	  _delay_us(1);

	  //disable writing
	  CLR_BIT(LCD_CONFIG_PORT, LCD_E);


	  // enable writing
	  SET_BIT(LCD_CONFIG_PORT, LCD_E);

	  //send the second part of data
	  LCD_DATA_PORT = (LCD_DATA_PORT & ~LCD_DATA_MASK) | ((data << 4) & LCD_DATA_MASK);
	  _delay_us(1);

	  CLR_BIT(LCD_CONFIG_PORT, LCD_E);
}


void LCD_clearScreen(){
	LCD_write_command(0x01);   // Clear display
	_delay_ms(CLEAR_DELAY);
}

