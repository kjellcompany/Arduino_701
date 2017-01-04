/*
  Example sketch DrawText.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.

  Using example code from the Universal 8bit Graphics Library
  https://github.com/olikraus/u8glib/

  This code is in the public domain.
*/


// Include the display library
#include "U8glib.h"

// Create new SSD1306 I2C display with 128x64 resolution
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE); 

void setup() {

}

void loop(void) {
  
  // Refresh picture
  oled.firstPage();  
  do {
    draw();
  } while(oled.nextPage());
}

void draw(void) {

  // Draw pixels
  oled.drawPixel(11, 44);
  oled.drawPixel(13, 44);

  // Draw line
  oled.drawLine(12, 28, 12, 60);
  oled.drawLine(12, 60, 128, 60);
  oled.drawLine(12, 60, 128, 30);

  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);

  // Print strings
  oled.drawStr(0, 10, "My Arduino");
  oled.drawStr(0, 23, "knowledge");
  oled.drawStr(0, 60, "0");
  oled.drawStr(0, 40, "1");
}

