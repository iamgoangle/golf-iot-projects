#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_PCF8574 lcd(0x27);

void clearScreen() {
  lcd.home();
  lcd.clear();
}

void checkLCD() {
  int error;

  while (! Serial);

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if
}

void setup() {
  Serial.begin(9600);
  checkLCD();

  lcd.begin(16, 2);  // initialize 16x2 pixel
}

void printHello() {
  clearScreen();

  lcd.setCursor(0, 0);
  lcd.setBacklight(255);
  lcd.display();
  lcd.blink();

  String name = "Hello! Golf";
  lcd.print(name);
  delay(3000);
}

void printMedium() {
  clearScreen();

  lcd.setBacklight(255);
  lcd.noBlink();

  // 1st line
  lcd.setCursor(0, 0);
  String blog = "medium.com";
  lcd.print(blog);

  // 2nd line
  lcd.setCursor(0, 1);
  lcd.cursor();
  String user = "/iamgoangle";
  lcd.print(user);
  delay(3000);

  for (int i = 0; i < 5; i++) {
    lcd.scrollDisplayRight();
    delay(300);
  }
}

void loop() {
  printHello();
  printMedium();
}
