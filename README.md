# TFT_ILI9163C_Extended_Char
Extends the TFT_ILI9163C Arduino library to provide cursor positioning only using character size.

Inherits	ILI9163C - A fast SPI driver for TFT that use Ilitek ILI9163C.

This library extends [Sumotoy](https://github.com/sumotoy) [TFT_ILI9163C](https://github.com/sumotoy/TFT_ILI9163C) library by changing the method `setCursor()`, which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 

It is no longer possible to position the cursor, by pixel, as before using the `setCursor()` method - no longer true:
It is now possible to position the cursor, by pixel, as before using the `setCursor()` method, by calling `setCursorMode(false)`.
Calling `setCursorMode(true)` will revert the cursor positioning to character resolution. This is the default.

Please see also the [TFT_ILI9163C_Extended](https://github.com/greenonline/TFT_ILI9163C_Extended) library

Note: There is another [TFT_ILI9163](https://github.com/Bodmer/TFT_ILI9163) library, by [Bodmer](https://github.com/Bodmer). I have not tried this library yet.

See the Arduino forums thread [1.44 inch TFT 128x128 GLCD ILI9163](https://forum.arduino.cc/index.php?topic=260605.165) for more information
