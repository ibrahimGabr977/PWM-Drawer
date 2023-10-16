/*
 * LCD_Driver.c
 *
 *  Created on: Jun 18, 2023
 *      Author: Lenovo
 */




#include "LCD_Driver.h"

// Function to initialize the LCD
void LCD_init() {
    // Set PC0, PC1, PC2 as output for E, RW, RS
    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);

    // Set PA0 to PA7 as output for data bits
    DDRA = 0xFF;

    // Initialize LCD in 8-bit mode
    _delay_ms(POWER_DELAY);             // Wait for power-up
    LCD_write_command(0x38);   // 8-bit, 4-line
    LCD_write_command(0x0C);   // Display ON, Cursor OFF
    LCD_clearScreen();   // Clear display
    LCD_write_command(0x06);   // Entry mode: Increment cursor, no display shift
}

// Function to write a command to the LCD
void LCD_write_command(u8 command) {
    // RS = 0 for command mode
    PORTB &= ~(1 << PB1);
    // RW = 0 for write mode
    PORTB &= ~(1 << PB2);
    // Enable the E signal
    PORTB |= (1 << PB3);
    // Send the command
    PORTA = command;
    // Disable the E signal
    PORTB &= ~(1 << PB3);
    // Delay to ensure the command is processed
    _delay_us(CMD_DELAY);
}

// Function to write a character to the LCD
void LCD_write_char(u8 character) {
	 // RS = 1 for char mode
	    PORTB |= (1 << PB1);
	    // RW = 0 for write mode
	    PORTB &= ~(1 << PB2);
	    // Enable the E signal
	    PORTB |= (1 << PB3);
    // Send the character
    PORTA = character;
    // Disable the E signal
    PORTB &= ~(1 << PB3);
    // Delay to ensure the character is processed
    _delay_us(CMD_DELAY);
}

// Function to write a string to the LCD
void LCD_write_string(const u8* string) {
    while (*string) {
        LCD_write_char(*string);
        string++;
    }
}

// Function to write a number to the LCD
void LCD_write_number(u16 number) {
    char buffer[16];  // Buffer to hold the converted string
    snprintf(buffer, sizeof(buffer), "%d", number);
    LCD_write_string(buffer);
}

void LCD_write_decimal_number(f64 number, u16 decimalPlaces){
    // Convert the double to a string with the desired number of decimal places
    char buffer[16]; // Adjust the size as needed
    dtostrf(number, 0, decimalPlaces, buffer); // Convert to string

    // Send each character of the string to the LCD
    for (int i = 0; buffer[i] != '\0'; i++) {
        LCD_write_char(buffer[i]);

    }
}



void LCD_set_cursor(u8 row, u8 col) {
    // Calculate the cursor address based on row and col
    uint8_t cursorAddress;
    if (row == 0) {
        cursorAddress = 0x80 + col; // First row
    } else if (row == 1) {
        cursorAddress = 0xC0 + col; // Second row
    } else if (row == 2) {
        cursorAddress = 0x94 + col; // Third row
    } else if (row == 3) {
        cursorAddress = 0xD4 + col; // Fourth row
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

void LCD_clearScreen(){
	LCD_write_command(0x01);   // Clear display
	_delay_ms(CLEAR_DELAY);
}
