/*
 * lcd.c
 *
 *  Created on: 10/06/2018
 *      Author: Olivier Van den Eede
 */

#include "lcd.h"

/************************************** Global variables **************************************/

GPIO_TypeDef * LCD_D_PORT[4] = {DATA_PORTS};
uint8_t LCD_D_PIN[4] = {DATA_PINS};


/************************************** Static declarations **************************************/

static void lcd_write_data(uint8_t data);
static void lcd_write_nib(uint8_t command);
static void lcd_write_command(uint8_t command);


/************************************** Function definitions **************************************/

/**
 * Initialize 16x2-lcd in 4-bit mode without cursor
 */
void lcd_init(void)
{
	lcd_write_command(0x33);
	lcd_write_command(0x32);

	lcd_write_command(FUNCTION_SET | OPT_N);				// 4-bit mode
	lcd_write_command(CLEAR_DISPLAY);						// Clear screen
	lcd_write_command(DISPLAY_ON_OFF_CONTROL | OPT_D);		// lcd-on, cursor-on, no-blink
	lcd_write_command(ENTRY_MODE_SET | OPT_INC);			// Increment cursor
}

/**
 * Write a number on the current position
 */
void lcd_int(int number)
{
	char buffer[11];
	sprintf(buffer, "%d", number);

	lcd_string(buffer);
}

/**
 * Write a string on the current position
 */
void lcd_string(char * string)
{
	for(uint8_t i = 0; i < strlen(string); i++)
	{
		lcd_write_data(string[i]);
	}
}

/**
 * Set the current position
 */
void lcd_pos(uint8_t row, uint8_t col)
{
	lcd_write_command(SET_DDRAM_ADDR | ((row * 0x40) + col));
}


/************************************** Static function definition **************************************/

/**
 * Write a byte to the command register
 */
void lcd_write_command(uint8_t command)
{
	COMMAND();		// Write to command register

	lcd_write_nib((command >> 4));
	lcd_write_nib(command & 0x0F);
}

/**
 * Write a byte to the data register
 */
void lcd_write_data(uint8_t data)
{
	DATA();			// Write to data register

	lcd_write_nib(data >> 4);
	lcd_write_nib(data & 0x0F);
}

/**
 * Set 4 bits on the bus and toggle the enable line
 */
void lcd_write_nib(uint8_t command)
{
	for(uint8_t i = 0; i < 4; i++)
	{
		WRITE(LCD_D_PORT[i], LCD_D_PIN[i], (command >> i) & 0x01);
	}

	CLOCK();		// Toggle enable
}
