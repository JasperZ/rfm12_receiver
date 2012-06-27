#include <avr/io.h>
#include "uart.h"

void init_uart(void)
{
	UCSRB |= 1<<TXEN;
	UCSRC |= 1<<URSEL | 1<<UCSZ1 | 1<<UCSZ0;
	UBRRL = 1;//12;
}

void send_char(uint8_t c)
{
	UDR = c;
		
	while(!(UCSRA & (1<<UDRE)))
	{
		;
	}
}

void send_string(uint8_t* s)
{
	while(*s != '\0')
	{
		send_char(*s);
		s++;
	}
}

