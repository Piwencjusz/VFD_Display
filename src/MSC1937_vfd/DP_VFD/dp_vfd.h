/*
 * dp_vfd.h
 *
 *  Created on: 22 lut 2025
 *      Author: Dawid Piwowarski
 */

#ifndef DP_VFD_DP_VFD_H_
#define DP_VFD_DP_VFD_H_

#define POR_PIN (1<<2)
#define VFD_DIR D

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define DELAY_US_VFD_CMD 50 // Time to command execute tBUSY (us) min 40

void VFD_init( uint8_t digits ); // Init VFD with default values

void VFD_putc( char c ); // Char to VFD
void VFD_puts( char *s ); // String to VFD
void VFD_cls( uint8_t digits ); // Clear screen
void VFD_int(int val, int radix); // Int value display

void VFD_DigitCC( uint8_t digits ); // Digit Counter Control
void VFD_DutyCC( uint8_t duty ); // Duty Cycle Control
void VFD_BufferPC( uint8_t x ); // Buffer Pointer Control


#endif /* DP_VFD_DP_VFD_H_ */
