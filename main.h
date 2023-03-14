
#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DDR_LCD DDRB
#define LCD PORTB
#define DDR_E_RS DDRB
#define PORT_E_RS PORTB

#define E 1
#define RS 2
#define E1 PORT_E_RS |= (1<<E)
#define E0 PORT_E_RS &= ~(1<<E)
#define RS1 PORT_E_RS |= (1<<RS)
#define RS0 PORT_E_RS &= ~(1<<RS)
#define D 0b11110000

#include "LCD.h"


#endif /* MAIN_H_ */