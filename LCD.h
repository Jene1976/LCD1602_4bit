#ifndef LCD_H_
#define LCD_H_

#include "main.h"

void port_ini (void);
void write (uint8_t n);
void send_byte (uint8_t data, uint8_t mode);
void LCD_ini (void);
void locate (uint8_t line, uint8_t pos);
void print (const char* str);
void shift (unsigned char s);
void entry (unsigned char s);

#endif /* LCD_H_ */