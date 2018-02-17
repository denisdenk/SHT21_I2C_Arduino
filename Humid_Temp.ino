#include <Wire.h>
#include "SparkFunHTU21D.h"
#include <LiquidCrystal_I2C.h>

//Create an instance of the object
HTU21D myHumidity;
LiquidCrystal_I2C lcd(0x3F,16,2);  

void setup()
{
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
  lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
  lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
  lcd.clear();
  
  myHumidity.begin();
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print(" Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  lcd.setCursor(3,0);
  lcd.print("Temp:");
  lcd.setCursor(9,0);
  lcd.print(temp, 1);
  lcd.setCursor(13,0);
  lcd.print("C");

  lcd.setCursor(3,1);
  lcd.print("Humd:");
  lcd.setCursor(9,1);
  lcd.print(humd, 1);
  lcd.setCursor(13,1);
  lcd.print("%");

  
  Serial.println();
  delay(1000);
}
