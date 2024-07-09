#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the library with the I2C address and LCD size
LiquidCrystal_I2C lcd(0x27, 16, 2);

int GAS_VAL = 0;

void setup() {
  pinMode(A0, INPUT);  // MQ-6 A0 Pin
  Serial.begin(9600);
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
  pinMode(2, OUTPUT);  // LED Red
  pinMode(4, OUTPUT);  // LED Green

  lcd.setCursor(0, 0);
  lcd.print("   GAS SENSOR  ");
}

void loop() {
  GAS_VAL = analogRead(A0);  // Read the analog value from the sensor
  Serial.println(GAS_VAL);

  if (GAS_VAL > 500) {
    digitalWrite(4, HIGH);  // Turn on Green LED
    digitalWrite(2, HIGH);  // Turn on Red LED
  } else {
    digitalWrite(4, LOW);  // Turn off Green LED
    digitalWrite(2, LOW);  // Turn off Red LED
  }

  // Display the detection status and gas value on the LCD
  lcd.setCursor(0, 1);
  if (GAS_VAL > 500) {
    lcd.print("LPG Detected: ");
    lcd.print(GAS_VAL);
  } else {
    lcd.print("LPG Not Detected  ");
  }

  delay(1000);  // Short delay before next reading
}
