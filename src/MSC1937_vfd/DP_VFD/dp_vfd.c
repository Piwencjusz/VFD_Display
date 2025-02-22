/*
 * dp_vfd.c
 *
 *  Created on: 22 lut 2025
 *      Author: Dawid Piwowarski
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "dp_vfd.h"

#include "../DP_SPI/dp_spi.h"

// MSC1937-01 driver designed specific for !!!
// MIC10937 driver

//connector
/*
GND
POR
DIN
---
CLK
+5V
*/


void VFD_init( uint8_t digits ) {

	DDR(VFD_DIR) |= POR_PIN;
	PORT(VFD_DIR) |= POR_PIN;

    DDRB |= (1 << 4); // set avr_spi !SS pin to output ?

	SPI_init();
	SPI_setDataMode(SPI_MODE1);
	SPI_setBitOrder(MSBFIRST);
	SPI_setClockDivider(SPI_CLOCK_DIV32); // clk/32 for 16Mhz spi_clk max 500kHz

	PORT(VFD_DIR) &= ~POR_PIN;
    _delay_us(500); // tRESW min 200us
    PORT(VFD_DIR) |= POR_PIN;
    _delay_us(1); // tRESS min 200ns

    VFD_DigitCC( digits );
    VFD_DutyCC(31); // 31/32

    VFD_cls( digits );
}

void VFD_putc( char c ) {

	SPI_transfer( c );
	_delay_us(DELAY_US_VFD_CMD);
}

void VFD_puts( char *s ) {
  	register char c;

  	while ((c = *s++)) VFD_putc(c);
}

void VFD_cls( uint8_t digits ) {
	VFD_BufferPC(0);
	for( uint8_t i= 0; i<digits; i++ ) {
		SPI_transfer( ' ' );
		_delay_us(DELAY_US_VFD_CMD);
	}
}

void VFD_int(int val, int radix) {
	char bufor[17];
	VFD_puts( itoa(val, bufor, radix) );
}

void VFD_DigitCC( uint8_t digits ) {
	// digits 1-16
	// 0 - 16 digits
	if(digits >= 16) SPI_transfer( 0xc0 );
	else SPI_transfer( 0xc0 | (0x0f & digits) );
	_delay_us(DELAY_US_VFD_CMD);
}

void VFD_DutyCC( uint8_t duty ) {
	// This command allows the brightness to be adjusted by 1/32 step
	// 0-31
	// 0 - off display
	SPI_transfer( 0xe0 | (0x1f & duty) );
	_delay_us(DELAY_US_VFD_CMD);
}

void VFD_BufferPC( uint8_t x ) {
	// pos x 0-15
	if(!x) SPI_transfer( 0xa0 | 0x0f );
	else SPI_transfer( 0xa0 | (0x0f & (x-1)) );
	_delay_us(DELAY_US_VFD_CMD);
}


