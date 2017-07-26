/*
	ILI9163C - A fast SPI driver for TFT that use Ilitek ILI9163C.

// ILI9163C_Extended_Char
//
// This extends TFT_ILI9163C library by changing the method setCursor(), which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 
//It is no longer possible to position the cursor, by pixel, as before using the setCursor() method.
// Please see also the ILI9163C_Extended library

*/	

#include "TFT_ILI9163C_Extended_Char.h"
#include <limits.h>
#include "pins_arduino.h"
#include "wiring_private.h"
#include <SPI.h>

#if defined(SPI_HAS_TRANSACTION)
	static SPISettings ILI9163C_SPI;
#endif

const int kCharacterWidth = 6;
const int kCharacterHeight = 9;

// TextSize = 1 gives display 20 characters wide, 14 characters high
// TextSize = 2 gives display 10 characters wide, 7 characters high
// TextSize = 3 gives display 7 characters wide, 4 characters high
const int kCharacterSize = 1;


//constructors

#if defined(__MK20DX128__) || defined(__MK20DX256__)
	TFT_ILI9163C_Extended_Char::TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin,uint8_t mosi,uint8_t sclk) : TFT_ILI9163C(_TFTWIDTH,_TFTHEIGHT)
	{
		_cs   = cspin;
		_rs   = dcpin;
		_rst  = rstpin;
		_mosi = mosi;
		_sclk = sclk;
	}
#elif defined(__MKL26Z64__)
	TFT_ILI9163C_Extended_Char::TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin,uint8_t mosi,uint8_t sclk) : TFT_ILI9163C(_TFTWIDTH,_TFTHEIGHT)
	{
		_cs   = cspin;
		_rs   = dcpin;
		_rst  = rstpin;
		_mosi = mosi;
		_sclk = sclk;
		_useSPI1 = false;
		if ((_mosi == 0 || _mosi == 21) && (_sclk == 20)) _useSPI1 = true;
	}
#else
	TFT_ILI9163C_Extended_Char::TFT_ILI9163C_Extended_Char(uint8_t cspin,uint8_t dcpin,uint8_t rstpin) : TFT_ILI9163C(_TFTWIDTH,_TFTHEIGHT)
	{
		_cs   = cspin;
		_rs   = dcpin;
		_rst  = rstpin;
	}
#endif

  void TFT_ILI9163C_Extended_Char::setCursor(int16_t x, int16_t y) {
      TFT_ILI9163C::setCursor(x*kCharacterWidth*kCharacterSize, y*kCharacterHeight*kCharacterSize);
  }

// Delete - used only in Extended, not Extended_Char
//  void TFT_ILI9163C_Extended_Char::setCursorChar(int16_t x, int16_t y) {
//      TFT_ILI9163C::setCursor(x*kCharacterWidth*kCharacterSize, y*kCharacterHeight*kCharacterSize);
//  }
// Delete - used only in Extended, not Extended_Char

//Arduino Uno, Leonardo, Mega, Teensy 2.0, etc




