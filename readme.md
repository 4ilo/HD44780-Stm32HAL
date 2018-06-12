# HD44780 Lcd - stm32 HAL

HD44780 16x2 Lcd library for stm32 using stm32-hal library's.

Library is developed and tested with Stm32F411-discovery and the given example.

Features:
- 4bit & 8bit mode
- Multiple lcd support
- String printing
- Number printing
- Set cursor position


## 8bit example
```c
Lcd_PortType ports[] = {
	D0_GPIO_Port, D1_GPIO_Port, D2_GPIO_Port, D3_GPIO_Port,
	D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
};

Lcd_PinType pins[] = {D0_Pin, D1_Pin, D2_Pin, D3_Pin, D4_Pin, D5_Pin, D6_Pin, D7_Pin};

Lcd_HandleTypeDef lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_8_BIT_MODE);

Lcd_string(&lcd, "4ilo - 8bit");

Lcd_cursor(&lcd, 1,6);
Lcd_int(&lcd, -500);
```

## 4bit example
```c
Lcd_PortType ports[] = {
	D4_GPIO_Port, D5_GPIO_Port, D6_GPIO_Port, D7_GPIO_Port
};

Lcd_PinType pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};

Lcd_HandleTypeDef lcd = Lcd_create(ports, pins, RS_GPIO_Port, RS_Pin, EN_GPIO_Port, EN_Pin, LCD_4_BIT_MODE);

Lcd_string(&lcd, "4ilo - 4bit");

Lcd_cursor(&lcd, 1,6);
Lcd_int(&lcd, -500);
```