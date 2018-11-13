
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

int pushButtona = 34;//2
int pushButtonb = 35;//1
int pushButtonc = 39;//3

int menu = 0;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int lastButtonState1 = 0;     // previous state of the button
int buttonPushCounter1 = 0;   // counter for the number of button presses

int lastButtonState2 = 0;     // previous state of the button
int buttonPushCounter2 = 0;   // counter for the number of button presses

int lastButtonState3 = 0;     // previous state of the button
int buttonPushCounter3 = 0;   // counter for the number of button presses


int count1 = 0;
int count2 = 0;
int count3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButtona, INPUT);
  pinMode(pushButtonb, INPUT);
  pinMode(pushButtonc, INPUT);
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
  delay(3000);
  tft.fillScreen(ST7735_BLACK);
}

void loop() {

   buttonState1 = digitalRead(pushButtonb);
   buttonState2 = digitalRead(pushButtona);
   buttonState3 = digitalRead(pushButtonc);

     // compare the buttonState to its previous state
  if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      menu--;
      tft.fillScreen(ST7735_BLACK);
    } else {
    }
    delay(50);
  }
  lastButtonState1 = buttonState1;
  
  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      //menu++;
      tft.fillScreen(ST7735_BLACK);
      if(count1== 1){
        moni();
      }
      if(count2 == 1){
        moni2();
      }
    } else {
    }
    delay(50);
  }
  lastButtonState2 = buttonState2;

  // compare the buttonState to its previous state
  if (buttonState3 != lastButtonState3) {
    if (buttonState3 == HIGH) {
      menu++;
      tft.fillScreen(ST7735_BLACK);
    } else {
    }
    delay(50);
  }
  lastButtonState3 = buttonState3;


/*
   tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println(menu);
*/


if(menu == -1){
  menu=2;
}

if(menu == 3){
  menu=0;
}

if(menu == 0){
  testhome();
  cc2();
  cc3();
}

if(menu == 1){
  testset();
  cc1();
  cc3();
}

if(menu == 2){
  tft.drawBitmap(50,50,evive_logo, 71, 71, ST7735_CYAN);
  cc1();
  cc2();
}

}

void testset(){  
  if(count2 == 0){
  int h = 128,w = 124, row, col, buffidx=0;// SIZE W*H INPUT
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row, pgm_read_word(setting + buffidx));// H,W,IMAGE ALSO USE COL+NUBMER ROW +NUMBER USE MOVE EX ) col+50
      buffidx++;
    } // end pixel
  }
  count2 = 1;
  }
}

void testhome(){  
  if(count1 == 0){
  int h = 128,w = 128, row, col, buffidx=0;// SIZE W*H INPUT
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row, pgm_read_word(home1 + buffidx));// H,W,IMAGE ALSO USE COL+NUBMER ROW +NUMBER USE MOVE EX ) col+50
      buffidx++;
    } // end pixel
  }
  count1 = 1;
  }
}

void moni(){
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println("temp : 20");
  tft.println("humi : 20");
  tft.println("soli : 20");
}

void moni2(){
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println("temp : 20");
}

void cc1(){
  if(count1 ==1){
    count1 =0;
  }
}
void cc2(){
  if(count2 ==1){
    count2 =0;
  }
}
void cc3(){
  if(count3 ==1){
    count3 =0;
  }
}
