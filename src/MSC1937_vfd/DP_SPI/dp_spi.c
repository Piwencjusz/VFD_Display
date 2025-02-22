/*
 * dp_spi.c
 *
 *  Created on: 3 lis 2016
 *      Author: Dawid Piwowarski
 */

#include <avr/io.h>

#include "dp_spi.h"

void SPI_init( void ) {

	SPCR |= ( (1<<MSTR)|(1<<SPE) );
	DDR( SPI_DIR ) |= ( SCK_PIN|MOSI_PIN );
}

void SPI_setBitOrder( uint8_t bitOrder ) {

	if( bitOrder == LSBFIRST ) {
		SPCR |= (1<<DORD);
	}else {
		SPCR &= ~(1<<DORD);
	}
}

void SPI_setDataMode( uint8_t mode ) {
	SPCR= ( SPCR & ~( (1<<CPOL)|(1<<CPHA) ) ) | mode;
}

void SPI_setClockDivider( uint8_t rate ) {
	SPCR= ( SPCR & ~( (1<<SPR0)|(1<<SPR1) ) ) | ( rate & ( (1<<SPR0)|(1<<SPR1) ) );
	SPSR= ( SPSR & ~(1<<SPI2X) ) | ( (rate >> 2) & (1<<SPI2X) );
}

void SPI_end( void ) {
	SPCR &= ~(1<<SPE);
}

void SPI_attachInterrupt( void ) {
	SPCR |= (1<<SPIE);
}

void SPI_detachInterrupt( void ) {
	SPCR &= ~(1<<SPIE);
}

uint8_t SPI_transfer( uint8_t data ) {
	SPDR= data;

	while ( !(SPSR & (1<<SPIF) ) );
	return SPDR;
}
