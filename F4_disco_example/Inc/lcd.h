/*
 * lcd.h
 *
 *  Created on: 10/06/2018
 *      Author: Olivier Van den Eede
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"
#include "main.h"
#include "string.h"

/************************************** LCD pinout **************************************/
#define RS_PORT 	RS_GPIO_Port
#define RS_PIN 		RS_Pin

#define EN_PORT 	EN_GPIO_Port
#define EN_PIN 		EN_Pin

#define DATA_PORTS	D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
#define DATA_PINS 	D4_Pin, D5_Pin, D6_Pin, D7_Pin


/************************************** Command register **************************************/
#define CLEAR_DISPLAY 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE_SET 0x04
#define OPT_S	0x01					// Shift entire display to right
#define OPT_INC 0x02					// Cursor increment

#define DISPLAY_ON_OFF_CONTROL 0x08
#define OPT_D	0x04					// Turn on display
#define OPT_C	0x02					// Turn on cursor
#define OPT_B 	0x01					// Turn on cursor blink

#define CURSOR_DISPLAY_SHIFT 0x10		// Move and shift cursor
#define OPT_SC 0x08
#define OPT_RL 0x04

#define FUNCTION_SET 0x20
#define OPT_DL 0x10						// Set interface data length
#define OPT_N 0x08						// Set number of display lines
#define OPT_F 0x04						// Set alternate font

#define SET_DDRAM_ADDR 0x80				// Set DDRAM address


/************************************** Helper macros **************************************/
#define DELAY(X) HAL_Delay(X)
#define WRITE(X,Y,Z) HAL_GPIO_WritePin(X, Y, Z);

#define DATA() HAL_GPIO_WritePin(RS_PORT, RS_PIN, 1)
#define COMMAND() WRITE(RS_PORT, RS_PIN, 0)
#define CLOCK() WRITE(EN_GPIO_Port, EN_Pin, 1); DELAY(1); WRITE(EN_GPIO_Port, EN_Pin, 0)


/************************************** Public functions **************************************/
void lcd_init(void);
void lcd_int(int number);
void lcd_string(char * string);
void lcd_pos(uint8_t row, uint8_t col);

#endif /* LCD_H_ */
