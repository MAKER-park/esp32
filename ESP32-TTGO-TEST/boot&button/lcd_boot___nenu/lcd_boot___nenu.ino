//Checked with evive / Arduino Mega
//Compatible with SPI based TFT (user can modify TFT codes and library)
//Date: 20160623
//Developer: Dhrupal R Shah

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include "bitmaps.h"
#include "bitmapsLarge.h"

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS 16
#define TFT_RST 9  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to -1!
#define TFT_DC 17

// Option 2: use any pins but a little slower!
#define TFT_SCLK 5   // set these to be whatever pins you like!
#define TFT_MOSI 23   // set these to be whatever pins you like!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int pushButtona = 34;//1
int pushButtonb = 35;//2
int pushButtonc = 39;//3

void setup() {
  Serial.begin(9600);
  Serial.print("Hello! ST7735 TFT Test");
  //tft.initR(INITR_BLACKTAB);
  tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab 1.44
  tft.setRotation(0); 
  delay(500);

  tft.fillScreen(ST7735_BLACK);

  Serial.println("Initialized");


 /*bitmapdraw
  tft.drawBitmap(0,0,bell,16,16,ST7735_WHITE);
  tft.drawBitmap(17,17,semiCircle, 50, 25, ST7735_WHITE);
  tft.drawBitmap(65,42,wifi_icon, 20, 15, ST7735_WHITE);
  tft.drawBitmap(85,57,battery_icon, 20, 15, ST7735_WHITE);
  tft.drawBitmap(90,77,evive_logo, 71, 71, ST7735_CYAN);
  delay(10000);
  tft.fillScreen(ST7735_BLACK);
*/

  int h = 115 ,w = 128, row, col, buffidx=0;// SIZE W*H  program INPUT
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row+10, pgm_read_word(setup_image + buffidx));// H,W,IMAGE ALSO USE COL+NUBMER ROW +NUMBER USE MOVE EX ) col+50
      buffidx++;
    } // end pixel
  }

}

void loop() {
}
