// This sketch is derived from code taken from both
// http://henrysbench.capnfatz.com/henrys-bench/arduino-displays/arduino-1-44-in-spi-tft-display-tutorial/
// and
// https://www.elecrow.com/wiki/index.php?title=1.44%27%27_128x_128_TFT_LCD_with_SPI_Interface
// 
//  1.44"  128 * 128  SPI  V1.1 Display Tutorial
//
// Filename: Extended_TFT_ILI9163C_Tester.ino
//
// Uses RESET  connected to pin 12, not  to 3.3V

// Read this!!!!!!
// Uncomment only ONE of the following two lines - they are mutually exclusive
// Uncommenting selects the library to test in the example
//Leaving both commented uses the original TFT_ILI9163C library

//#define __Use_Extended_LCD__
//#define __Use_Extended_Char_LCD__

#include <SPI.h>
#include <Adafruit_GFX.h>
#if defined (__Use_Extended_LCD__)
#include <TFT_ILI9163C_Extended.h>
#elif defined (__Use_Extended_Char_LCD__)
#include <TFT_ILI9163C_Extended_Char.h>
#else
#include <TFT_ILI9163C.h>
#endif

// Definition of WHITE
#define WHITE   0xFFFF

/*
Your Connections to an Uno (Through a Level Shifter)

 LED to 3.3V
 SCK to D13
 SDA to D11
 A0 to D8
 RST to D9
 CS to D10
 GND to GND
 VCC to 3.3V 
 */
 
// All wiring required, only 3 defines for hardware SPI on 328P
#define __DC 9
#define __CS 10
// MOSI --> (SDA) --> D11
#define __RST 12
// SCLK --> (SCK) --> D13

// Color definitions
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#if defined (__Use_Extended_LCD__)
TFT_ILI9163C_Extended tft = TFT_ILI9163C_Extended(__CS, __DC, __RST); 
#elif defined (__Use_Extended_Char_LCD__)
TFT_ILI9163C_Extended_Char tft = TFT_ILI9163C_Extended_Char(__CS, __DC, __RST); 
#else
TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC, __RST); 
#endif
const int kCharWidth = 6;
const int kCharHeight = 9;

// TextSize = 1 gives display 20 characters wide, 14 characters high
// TextSize = 2 gives display 10 characters wide, 7 characters high
// TextSize = 3 gives display 7 characters wide, 4 characters high
const int kTestSize = 1;

void setup() {
  tft.begin();
  tft.fillScreen();
}

void loop(){
#if defined (__Use_Extended_LCD__)
  testText_Extended();
#elif defined (__Use_Extended_Char_LCD__)
  testText_Extended_Char();
#else
  testText();
#endif

delay(500);
}

unsigned long testText() {
  
  tft.setCursor(29, 63);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("Hello World!"); 
  
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursor(1*kCharWidth*kTestSize, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursor(2*kCharWidth*kTestSize, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursor(3*kCharWidth*kTestSize, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  tft.setCursor(0, 1*kCharHeight*kTestSize);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursor(1*kCharWidth*kTestSize, 1*kCharHeight*kTestSize);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursor(2*kCharWidth*kTestSize, 1*kCharHeight*kTestSize);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursor(3*kCharWidth*kTestSize, 1*kCharHeight*kTestSize);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  for (int n=0; n<10; n++){
    tft.setCursor(n*kCharWidth*kTestSize, 2*kCharHeight*kTestSize);
    tft.println("o");
  }

  tft.setCursor(0*kCharWidth*kTestSize, 3*kCharHeight*kTestSize);
    tft.println("o");
  tft.setCursor(0*kCharWidth*kTestSize, 4*kCharHeight*kTestSize);
    tft.println("o");
  tft.setCursor(0*kCharWidth*kTestSize, 5*kCharHeight*kTestSize);
    tft.println("o");

  for (int n=6; n<30; n++){
//    tft.setCursor(n*kCharWidth*kTestSize, n*kCharHeight*kTestSize);
    tft.setCursor(0, n*kCharHeight*kTestSize);
    tft.println("O");
  }
}


#if defined (__Use_Extended_LCD__)
unsigned long testText_Extended() {
  tft.setCursor(29, 63);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("Hello World!"); 
  
//  tft.setCursorChar(0, 0);
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursorChar(1, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursorChar(2, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursorChar(3, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  tft.setCursorChar(0, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursorChar(1, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursorChar(2, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursorChar(3, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  for (int n=0; n<10; n++){
    tft.setCursorChar(n, 2);
    tft.println("o");
  }

  tft.setCursorChar(0, 3);
    tft.println("o");
  tft.setCursorChar(0, 4);
    tft.println("o");
  tft.setCursorChar(0, 5);
    tft.println("o");

  for (int n=6; n<30; n++){
//    tft.setCursor(n, n);
    tft.setCursorChar(0, n);
    tft.println("O");
  }
}
#endif

unsigned long testText_Extended_Char() {
  tft.setCursor(29, 63);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("Hello World!"); 
  
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursor(1, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursor(2, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursor(3, 0);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  tft.setCursor(0, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("H");  
  
  tft.setCursor(1, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("e");  
  
  tft.setCursor(2, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("l");  
  
  tft.setCursor(3, 1);
  tft.setTextColor(WHITE);  
  tft.setTextSize(kTestSize);
  tft.println("lo!!!");

  for (int n=0; n<10; n++){
    tft.setCursor(n, 2);
    tft.println("o");
  }

  tft.setCursor(0, 3);
    tft.println("o");
  tft.setCursor(0, 4);
    tft.println("o");
  tft.setCursor(0, 5);
    tft.println("o");

  for (int n=6; n<30; n++){
//    tft.setCursor(n, n);
    tft.setCursor(0, n);
    tft.println("O");
  }
}
