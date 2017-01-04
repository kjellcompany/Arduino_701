/*
  Example sketch DrawAnimation.ino version 7.01.
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

// Store text in char arrays
char line1[] = "Do to do,";
char line2[] = "not to try!";

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
  
  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);
  
  // Calculate line height
  int lineHeight = oled.getFontAscent()-oled.getFontDescent();  

  // Calculate starting position
  int line1x = (oled.getWidth() - oled.getStrWidth(line1)) / 2;
  int line2x = (oled.getWidth() - oled.getStrWidth(line2)) / 2;

  // Print text lines
  oled.drawStr(line1x, lineHeight * 2, line1);
  oled.drawStr(line2x, lineHeight * 3, line2);
}

