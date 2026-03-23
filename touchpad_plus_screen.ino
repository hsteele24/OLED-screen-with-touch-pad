// Project 31 and 33 - using OLED screen to display position of my finger on touch screen
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 
#define TFT_DC         8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

float p = 3.1415926;

void setup(void) {
  
  Serial.begin(9600);
  
  tft.init(240, 320);           // Init ST7789 320x240

  delay(500);

  // large block of text
  tft.fillScreen(ST77XX_BLACK);


  delay(500);
}
 int x,y = 0;
 int readX() // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);  // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr=analogRead(0);       // stores the value of the x-axis
  return xr;
}

  int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);  // set A0 to GND
  digitalWrite(16, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1);       // stores the value of the y-axis
  return yr; 
}


void loop() {
  Serial.print(" x = ");
  x=readX();
  Serial.print(x);
  y=readY();
  Serial.print(" y = ");
  Serial.println(y);
  delay (5);

  tft.drawPixel(x/3.425, 320-(y/2.65625-10), ST77XX_GREEN);  //drawing the pixel on the screen

  delay(1); // Wait for 100 ms
}