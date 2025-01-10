#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH      128   // OLED display width, in pixels
#define SCREEN_HEIGHT     64    // OLED display height, in pixels
#define OLED_RESET        -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS    0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int HelloTimes=0;
// put function declarations here:
int myFunction(int, int);

void setup() {
  Wire.begin();
  OLED.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); 
  OLED.clearDisplay();
  OLED.drawLine(0, 16, 128, 16, WHITE);
  // Show "Hello world!" on the display.
  OLED.setTextSize(1); 
  // set curdor position
  OLED.setCursor(1, 1);  
  OLED.setTextColor(SSD1306_WHITE);  
  OLED.println("Hello, world!");
  OLED.display();
  HelloTimes = myFunction(2, 3);
}


void loop() {
  // put your main code here, to run repeatedly:
  printf("hello world %d\n\n",myFunction(HelloTimes,HelloTimes++));
  delay(1000);
  OLED.setCursor(1, 30);
  OLED.setTextColor(SSD1306_WHITE);
  OLED.println("welcome 2025!");
  OLED.display();
}
 
// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}