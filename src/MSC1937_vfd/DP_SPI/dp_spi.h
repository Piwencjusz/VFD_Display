/*
 * dp_spi.h
 *
 *  Created on: 3 lis 2016
 *      Author: Dawid Piwowarski
 */

#ifndef DP_SPI_DP_SPI_H_
#define DP_SPI_DP_SPI_H_

#define MOSI_PIN (1<<5)
#define MISO_PIN (1<<6)
#define SCK_PIN (1<<7)
#define SPI_DIR B

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define LSBFIRST 0
#define MSBFIRST 1

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

void SPI_init( void );

void SPI_setBitOrder( uint8_t bitOrder );
void SPI_setDataMode( uint8_t mode );
void SPI_setClockDivider( uint8_t rate );

void SPI_end( void );
void SPI_attachInterrupt( void );
void SPI_detachInterrupt( void );

uint8_t SPI_transfer( uint8_t data );

#endif /* DP_SPI_DP_SPI_H_ */
