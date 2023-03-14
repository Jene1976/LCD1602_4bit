#include "main.h"



void PWM_ini (void) {
	DDRB |= (1<<PB3); //Включаем выход PWM
	TCCR2 = 0;
	TCCR2 |= (1<<WGM20) | (1<<WGM21); // Enable Fast PWM
	TCCR2 |= (1<<COM21); //Clear OC2 on Compare Match, set OC2 at BOTTOM, (non-inverting mode)
	TCCR2 |= (1<<CS22); //Устанавливаем предделитель на 64
	TCNT2 = 0; //Сброс счетчика
	OCR2 = 200; //Не более 200
}

void brightness (uint8_t B)
{
	 OCR2 = B; 
}


int main(void) {
	port_ini ();
	LCD_ini ();
	PWM_ini ();
//	sei ();
	
	locate(0,4);
	print ("Hello12,");
//	send_byte('P',1);
	locate(1,5);
	print("Jene");
	
    while(1)
    {
        shift (3);
		_delay_ms(200);
    }
}