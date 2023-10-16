/*
 * Test_LCD.h
 *
 *  Created on: Jun 18, 2023
 *      Author: Lenovo
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "main.h"

// Set up the pins
#define LCD_CONFIG_DDR DDRB
#define LCD_CONFIG_PORT PORTB
#define LCD_RS PB1
#define LCD_Rw PB2
#define LCD_E PB3
#define LCD_DATA_PORT PORTA
#define LCD_DATA_DDR DDRA
#define LCD_ROWS 2
#define LCD_COLS 16


#define LCD_DATA_MASK 0xF0
#define COMMAND 0
#define DATA 1
#define POWER_DELAY 15
#define CLEAR_DELAY 2
#define CMD_DELAY 1

void LCD_init();
void LCD_write_command(u8 command);
void LCD_write_char(u8 character);
void LCD_write_string(const u8* string);
void LCD_write_number(u16 number);
void LCD_write_decimal_number(f64 number, u16 decimalPlaces);
void LCD_set_cursor(u8 row, u8 col);
void LCD_create_custom_char(u16 char_num, const u8 *char_pattern);
void LCD_write_custom_char(u16 char_num);
void LCD_clearScreen();


static void prepareWriting(u8 mode);
static void write(u8 data);


#endif /* LCD_DRIVER_H_ */
