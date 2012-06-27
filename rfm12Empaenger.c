/*
 * rfm12Empaenger.c
 *
 * Created: 22.04.2012 17:33:14
 *  Author: Jasper
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "../../RFM12/RFM12/rfm12.h"
#include "uart.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	struct DataPackage* pkg;
	uint8_t i;
	uint8_t buffer[20];
	
	rfm_init(RX_MODE);
	init_uart();
	
	DDRD &= ~(1<<PD2);
	PORTD |= 1<<PD2;
	
    while(1)
    {
		pkg = receivePackageBlocking();
		
		if(pkg->pkgSize > 0)
		{
			send_string("RICHTIG\r\n");
/*			for(i=0; i<pkg->pkgSize-DATA_PKG_HEAD_SIZE; i++)
			{
				itoa(pkg->pkgData[i], (char*)buffer, 16);
				send_string(buffer);
				send_string("\r\n");
			}*/
		}
		else
		{
			send_string("FALSCH\r\n");
		}
		
		deleteDataPackage(pkg);
    }
}

