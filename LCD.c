#include "LCD.h"

void port_ini (void) {
	DDR_LCD |= D; //
	LCD &= ~D; //
	DDR_E_RS |= (1<<RS) | (1<<E);
	PORT_E_RS &= ~((1<<RS) | (1<<E));
}

void write (uint8_t n) {
	n <<= 4;
	E1; //_delay_us(50);
	LCD &= ~D; //Очистка предідущей отправки
	LCD |= n;
	E0; _delay_us(50);
}

void send_byte (uint8_t data, uint8_t mode) {
	if (mode) RS1;
	else RS0;
	write(data>>4);
	write(data);
}

void LCD_ini (void) {
	_delay_ms(20);
	RS0;
	write(3); _delay_ms(5);
	write(3); _delay_us(200);
	write(3); _delay_us(50);
	write(2); _delay_us(50);
	send_byte(0b00101000,0); _delay_us(50); //Interface data - 8bit, Displey line - 2, Displey font - 5x8
	send_byte(0b00001100,0); _delay_us(50); //DB2 - displey on/off, DB1 - cursor on/off, DB0 - cursor blink on/off
	send_byte(1,0); _delay_ms(2); // Clear display
	send_byte(0b00000110,0); _delay_us(50);	//DB1 - 1:display moves to right, 0:display moves to left ; DB0 - Сдвиг дисплея
}

void locate (uint8_t line, uint8_t pos) {
	send_byte (0x80 | (0x40*line + pos), 0);
}

void print (const char* str) {
		while (*str != '\0') send_byte(*str++, 1);
}

void shift (unsigned char s) { //Сдвиг курсора или дисплея. 1 - сдвиг курсора влево, 2 - сдвиг курсора вправо, 3-сдвиг дисплея влево, 4 -сдвиг дисплея вправо
	switch (s)
	{
		case (1): send_byte (0b00010000, 0); break;
		case (2): send_byte (0b00010100, 0); break;
		case (3): send_byte (0b00011000, 0); break; //Сдвиг экрана влево
		case (4): send_byte (0b00011100, 0); break; //Сдвиг экрана вправо
	}
}
//-------------------------------------------------------------------
void entry (unsigned char s) {
	if (s == 1) send_byte (0b00000110, 0); //Курсор смещается вправо на одну позицию
	if (s == 2) send_byte (0b00000100, 0); //Курсор смещается влево на одну позицию
	if (s == 3) send_byte (0b00000111, 0); //Курсор движеться вправо
	if (s == 4) send_byte (0b00000101, 0); //Курсор движеться влево
}