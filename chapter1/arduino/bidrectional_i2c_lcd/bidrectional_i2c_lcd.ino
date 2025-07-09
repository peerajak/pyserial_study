#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0); // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรตำแหน่งที่0 แถวที่ 1 เตรียมพิมพ์ข้อความ
  while(!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String message = Serial.readStringUntil('\n');
    message = message + " " + String(counter);
    counter++;
    delay(100);
    //lcd.clear();
    lcd.print(message); 
    Serial.println(message); 
    
  }else{
    ;//lcd.print("No Serial"); 
  }

}
