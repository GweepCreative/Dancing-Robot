#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define PIN D8
#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10  // Number of snowflakes in the animation example
#define sleepTime 150
Servo LeftServo;
Servo RightServo;
#define maxLeft 0
#define maxRight 180
// 'normal3', 16x16px
const unsigned char bitmap_mouth[] PROGMEM = {
  0x00, 0x00, 0x07, 0xe0, 0x0f, 0xf0, 0x0c, 0x30, 0x08, 0x30, 0x00, 0x30, 0x00, 0x70, 0x01, 0xe0,
  0x01, 0xf0, 0x00, 0x30, 0x00, 0x18, 0x18, 0x18, 0x0c, 0x38, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00
};

// 'ters3', 16x16px
const unsigned char bitmap_mouth_reverse[] PROGMEM = {
  0x00, 0x00, 0x07, 0xe0, 0x0f, 0xf0, 0x0c, 0x38, 0x0c, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x07, 0xc0,
  0x0f, 0x80, 0x0c, 0x00, 0x18, 0x00, 0x18, 0x18, 0x1c, 0x38, 0x0e, 0x70, 0x07, 0xe0, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);
  pixels.begin();
  pixels.clear();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  LeftServo.attach(D6);
  RightServo.attach(D7);

  LeftServo.write(90);
  RightServo.write(90);

  display.clearDisplay();
  delay(sleepTime);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setFont(&FreeMonoBoldOblique12pt7b);
}

void loop() {
  TopLeft(sleepTime + 50, 1);
  randomColor();
  delay(sleepTime);
  TopLeft(sleepTime + 50, 1);
  randomColor();
  delay(sleepTime);
randomColor();
  display.clearDisplay();
randomColor();
  TopRight(sleepTime + 50, 1);
  randomColor();
  delay(sleepTime);
  randomColor();
  TopRight(sleepTime + 50, 1);
  randomColor();
  delay(sleepTime);
randomColor();
  display.clearDisplay();
randomColor();
  Middle(sleepTime + 50, 1);
  randomColor();delay(sleepTime);
  randomColor();Middle(sleepTime + 50, 1);
  randomColor();delay(sleepTime);
randomColor();
  display.clearDisplay();
randomColor();
  MiddleSmile(sleepTime + 50);
  randomColor();delay(sleepTime);
  randomColor();MiddleSmile(sleepTime + 50);
  randomColor();delay(sleepTime);
randomColor();
  display.clearDisplay();
randomColor();
  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
randomColor();
  display.clearDisplay();

  randomColor();TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);

  display.clearDisplay();

  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);

  randomColor();display.clearDisplay();

  TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);

  display.clearDisplay();
randomColor();
  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopLeft(sleepTime + 50, 0);
  randomColor();delay(sleepTime);

  randomColor();display.clearDisplay();

  randomColor();TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);
  randomColor();TopRight(sleepTime + 50, 0);
  randomColor();delay(sleepTime);

  randomColor();display.clearDisplay();
}

void TopLeft(int timeDelay, int rotate) {
  LeftServo.write(maxRight);
  RightServo.write(maxRight);
  /// 1st FRAME    | TOP-LEFT
  drawCircle(10, 20, 10);  // Draw circles (filled)

  if (rotate == 1) {

    display.setRotation(1);
    // display.setCursor(20, 100);

    // display.println(F("3"));
    display.drawBitmap(20, 87, bitmap_mouth, 16, 16, WHITE);

    display.setRotation(0);
  } else {
    display.setRotation(0);
    display.drawBitmap(23, 20, bitmap_mouth_reverse, 16, 16, WHITE);
    drawCircle(55, 20, 10);  // Draw circles (filled)
    display.display();
    ///////////////
    delay(timeDelay);
    display.clearDisplay();
    return;
  }
  drawCircle(55, 20, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  delay(timeDelay);
  display.clearDisplay();
  LeftServo.write(maxLeft);
  RightServo.write(maxLeft);
  /// 1st FRAME    | TOP-LEFT
  drawCircle(10, 10, 10);  // Draw circles (filled)

  if (rotate == 1) {
    display.setRotation(1);
    display.drawBitmap(10, 87, bitmap_mouth, 16, 16, WHITE);
    display.setRotation(0);
  } else {
    display.setRotation(0);
    display.drawBitmap(10, 10, bitmap_mouth_reverse, 16, 16, WHITE);
  }

  drawCircle(55, 10, 10);  // Draw circles (filled)
  display.display();
  LeftServo.write(maxRight);
  RightServo.write(maxRight);
  ///////////////
  //////MOUNT/////////
  drawTringle(28, 21, 38, 21, 33, 28, WHITE);
  delay(timeDelay);
  ///////////////////
  display.clearDisplay();

  /// 1st FRAME    | TOP-LEFT
  drawCircle(10, 20, 10);  // Draw circles (filled)

  if (rotate == 1) {

    display.setRotation(1);
    // display.setCursor(20, 100);

    // display.println(F("3"));
    display.drawBitmap(20, 87, bitmap_mouth, 16, 16, WHITE);

    display.setRotation(0);
  } else {
    display.setRotation(0);
    display.drawBitmap(20, 20, bitmap_mouth_reverse, 16, 16, WHITE);
  }
  drawCircle(55, 20, 10);  // Draw circles (filled)
  display.display();
  LeftServo.write(maxLeft);
  RightServo.write(maxLeft);
  ///////////////
}

void TopRight(int timeDelay, int rotate) {
  /// 2st FRAME    | TOP-RIGHT
  LeftServo.write(maxLeft);
  RightServo.write(maxLeft);
  drawCircle(70, 20, 10);  // Draw circles (filled)

  if (rotate == 1) {
    display.setRotation(1);
    display.drawBitmap(20, 26, bitmap_mouth, 16, 16, WHITE);
    display.setRotation(0);
  } else {
    display.drawBitmap(85, 26, bitmap_mouth, 16, 16, WHITE);
    drawCircle(115, 20, 10);  // Draw circles (filled)
    display.display();
    ///////////////
    delay(timeDelay);
    display.clearDisplay();
    return;
  }

  drawCircle(115, 20, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  delay(timeDelay);
  display.clearDisplay();
  LeftServo.write(maxRight);
  RightServo.write(maxRight);
  /// 2st FRAME    | TOP-RIGHT
  drawCircle(70, 10, 10);  // Draw circles (filled)
  if (rotate == 1) {

    display.setRotation(1);
    // display.setCursor(10, 100);

    // display.println(F("3"));
    display.drawBitmap(10, 26, bitmap_mouth, 16, 16, WHITE);

    display.setRotation(0);
  } else {

    display.setRotation(1);
    display.setCursor(20, 40);
    display.println(F("3"));
    display.setRotation(0);
  }
  drawCircle(115, 10, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  LeftServo.write(maxLeft);
  RightServo.write(maxLeft);
  //////MOUNT/////////
  drawTringle(88, 21, 100, 21, 94, 27, WHITE);
  delay(timeDelay);
  ///////////////////
  display.clearDisplay();

  /// 2st FRAME    | TOP-RIGHT
  drawCircle(70, 20, 10);  // Draw circles (filled)
  if (rotate == 1) {

    display.setRotation(1);
    // display.setCursor(10, 100);

    // display.println(F("3"));
    display.drawBitmap(20, 26, bitmap_mouth, 16, 16, WHITE);

    display.setRotation(0);
  } else {

    display.setRotation(1);
    display.setCursor(20, 40);
    display.println(F("3"));
    display.setRotation(0);
  }
  drawCircle(115, 20, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  LeftServo.write(maxRight);
  RightServo.write(maxRight);
}

void Middle(int timeDelay, int rotate) {
  LeftServo.write(90);
  RightServo.write(90);
  LeftServo.write(maxRight);
  RightServo.write(maxLeft);
  /// 2st FRAME    | TOP-RIGHT
  drawCircle(display.width() / 2 - 30, display.height() / 2, 10);  // Draw circles (filled)

  if (rotate == 1) {
    display.setRotation(1);
    display.drawBitmap(display.width() / 2, display.height() / 2 - 5, bitmap_mouth, 16, 16, WHITE);
    display.setRotation(0);
  } else {
    display.drawBitmap(display.width() / 2, display.height() / 2 - 5, bitmap_mouth_reverse, 16, 16, WHITE);
  }

  drawCircle(display.width() / 2 + 20, display.height() / 2, 10);  // Draw circles (filled)
  display.display();
  ///////////////

  delay(timeDelay);
  display.clearDisplay();
  LeftServo.write(maxLeft);
  RightServo.write(maxRight);
  /// 2st FRAME    | TOP-RIGHT
  drawCircle(display.width() / 2 - 30, 20, 10);  // Draw circles (filled)

  if (rotate == 1) {
    display.setRotation(1);
    display.drawBitmap(display.width() / 2 - 10, display.height() / 2 - 5, bitmap_mouth, 16, 16, WHITE);
    display.setRotation(0);
  } else {
    display.drawBitmap(display.width() / 2 - 10, display.height() / 2 - 5, bitmap_mouth_reverse, 16, 16, WHITE);
  }

  drawCircle(display.width() / 2 + 20, 20, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  //////MOUNT/////////
  // 12 - 100 - 7
  drawTringle(
    display.width() / 2 - 8, display.height() / 2,
    display.width() / 2 + 3, display.height() / 2,
    display.width() / 2 - 3, display.height() / 2 + 7,
    WHITE);
  delay(timeDelay);
  ///////////////////
  display.clearDisplay();
  LeftServo.write(maxLeft);
  RightServo.write(maxRight);
  /// 2st FRAME    | TOP-RIGHT
  drawCircle(display.width() / 2 - 30, display.height() / 2, 10);  // Draw circles (filled)

  if (rotate == 1) {
    display.setRotation(1);
    display.drawBitmap(display.width() / 2, display.height() / 2 - 5, bitmap_mouth, 16, 16, WHITE);
    display.setRotation(0);
  } else {
    display.drawBitmap(display.width() / 2, display.height() / 2 - 5, bitmap_mouth_reverse, 16, 16, WHITE);
  }

  drawCircle(display.width() / 2 + 20, display.height() / 2, 10);  // Draw circles (filled)
  display.display();
  ///////////////
  LeftServo.write(90);
  RightServo.write(90);
}

void MiddleSmile(int timeDelay) {

  /// 2st FRAME    | TOP-RIGHT
  display.setTextSize(1);
  display.setCursor(display.width() / 2 - 30, display.height() / 2 - 7);
  display.println(F(">"));

  display.setCursor(display.width() / 2 + 10, display.height() / 2 - 2);
  display.println(F("<"));

  display.setRotation(1);
  display.drawBitmap(display.width() / 2 - 2, display.height() / 2 - 6, bitmap_mouth, 16, 16, WHITE);
  display.setRotation(0);
  ///////////////

  // //////MOUNT/////////
  // drawTringle(
  //     display.width() / 2 - 8, display.height() / 2 + 10,
  //     display.width() / 2 + 3, display.height() / 2 + 10,
  //     display.width() / 2 - 3, display.height() / 2 + 16,
  //     WHITE);

  display.display();
  delay(timeDelay);
  LeftServo.write(maxRight);
  RightServo.write(maxLeft);
  ///////////////////
  // display.clearDisplay();
}

void drawTringle(int x0, int y0, int x1, int y1, int x2, int y2, int color) {
  display.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  display.display();
  /*
   x0|y0 ______ x1|y1
     \           /
      \         /
       \       /
        \     /
         \   /
          \ /
         x2|y2
*/
}

void drawCircle(int x, int y, int width) {

  display.fillCircle(x, y, width, WHITE);
  // display.fillCircle(display.width() / 2, display.height() / 2, 10, INVERSE);
  display.display();
}

void randomColor() {

 for(int i = 0; i < pixels.numPixels(); i++)
    {
        pixels.setPixelColor(i, getRandomColor());    
    }
    
    pixels.setBrightness(50);  //0 - 255
    pixels.show();

    delay(50);
}
enum colors { RED = 0, GREEN, BLUE, YELLOW, PURPLE };
uint32_t getRandomColor()
{    
    switch(random(5))
    {
        case RED:    { return pixels.Color(255, 0, 0);   }
        case GREEN:  { return pixels.Color(0, 255, 0);   }
        case BLUE:   { return pixels.Color(0, 0, 255);   }
        case YELLOW: { return pixels.Color(255, 255, 0); }
        case PURPLE: { return pixels.Color(255, 0, 255); }
        
        // should never happen
        default:{ return pixels.Color(255, 255, 255); }
    }  
}