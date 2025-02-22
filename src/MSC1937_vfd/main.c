/*
 * main.c
 *
 *  Created on: 22 lut 2025
 *      Author: Dawid Piwowarski
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "DP_VFD/dp_vfd.h"
#include "DP_SPI/dp_spi.h"

int main(void) {

	VFD_init(16);

	for( uint8_t i= 0; i<32; i++ ) {
		VFD_BufferPC(7);
		VFD_int(i,10);
		VFD_DutyCC(i);
		_delay_ms(50);
	}

	for( uint8_t i= 31; i>0; i-- ) {
		VFD_BufferPC(7);
		VFD_int(i,10);
		if(i<10) VFD_putc(' ');
		VFD_DutyCC(i);
		_delay_ms(200);
	}

	VFD_DutyCC(31);
	VFD_BufferPC(0);
	VFD_puts("TEMP0 21,37'C");

	while(1) {

		VFD_BufferPC(15);
		VFD_putc('-');
		_delay_ms(50);
		VFD_BufferPC(15);
		VFD_putc('/');
		_delay_ms(50);
		VFD_BufferPC(15);
		VFD_putc('1');
		_delay_ms(50);
		VFD_BufferPC(15);
		VFD_putc('\\');
		_delay_ms(50);
	}
}
