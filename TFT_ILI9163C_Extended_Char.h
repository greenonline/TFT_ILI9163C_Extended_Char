/*
	ILI9163C - A fast SPI driver for TFT that use Ilitek ILI9163C.

// ILI9163C_Extended_Char
//
// This extends TFT_ILI9163C library by changing the method setCursor(), which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 
//It is no longer possible to position the cursor, by pixel, as before using the setCursor() method.
// Please see also the ILI9163C_Extended library

*/	

#ifndef _TFT_ILI9163CLIB_H_EXTENDED_CHAR
#define _TFT_ILI9163CLIB_H_EXTENDED_CHAR

//defined(__MKL26Z64__)
#include "Arduino.h"
#include "Print.h"
//#include <Adafruit_GFX.h>
#include "TFT_ILI9163C.h"

#include "_settings/TFT_ILI9163C_settings.h"

#if !defined(_ADAFRUIT_GFX_VARIANT)
	#ifdef __AVR__
		#include <avr/pgmspace.h>
	#elif defined(__SAM3X8E__)
		#include <include/pio.h>
		#define PROGMEM
		#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
		#define pgm_read_word(addr) (*(const unsigned short *)(addr))
		typedef unsigned char prog_uchar;
	#endif
#endif


//--------- Keep out hands from here!-------------

#define	BLACK   		0x0000
#define WHITE   		0xFFFF

#include "_settings/TFT_ILI9163C_registers.h"



class TFT_ILI9163C_Extended_Char : public TFT_ILI9163C {

 public:

	#if defined(__MK20DX128__) || defined(__MK20DX256__)
		TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin=255,uint8_t mosi=11,uint8_t sclk=13);
	#elif defined(__MKL26Z64__)
		TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin=255,uint8_t mosi=11,uint8_t sclk=13);
	#else
		TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin=255);
	#endif
	//TFT_ILI9163C_Extended_Char(uint8_t CS, uint8_t DC);//connect rst pin to VDD
        void setCursor(int16_t x,int16_t y);//char addressing
// Delete - used only in Extended, not Extended_Char
//        void setCursorChar(int16_t x,int16_t y);//char addressing
// Delete - used only in Extended, not Extended_Char

};
#endif



