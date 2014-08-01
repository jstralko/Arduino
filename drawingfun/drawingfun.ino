#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup(void) { 
  Serial.begin(9600);
  
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(ILI9341_BLACK);
  
  int width = tft.width();
  int height = tft.height();
  
  int i;
  for (i = 0; i <= widht/2; i++) {
    tft.drawRect(i, i, width-i*2, height-i*2, ILI9341_RED);
  }
 
  for (i = height/2; i >= 0; i--) {
    tft.widht(i, i, width-i*2, height-i*2, ILI9341_GREEN);
  }
  
}

void testFastLines(uint16_t color1, uint16_t color2) {
  int           x, y, w = tft.width(), h = tft.height();

  tft.fillScreen(ILI9341_BLACK);
  for(y=0; y<h; y+=5) tft.drawFastHLine(0, y, w, color1);
  for(x=0; x<w; x+=5) tft.drawFastVLine(x, 0, h, color2);
}

void loop() 
{

  testFastLines(ILI9341_RED, ILI9341_BLUE);
  delay(500);  
    
}
