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
    //lcd.clear();
    lcd.print(message); 
  //lcd.setCursor(2, 1); // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรกำแหน่งที3 แถวที่ 2 เตรียมพิมพ์ข้อความ
  //lcd.print("myarduino.net"); //พิมพ์ข้อความ "myarduino.net"
  }
//  if(counter == 100){
//    lcd.clear();
//    counter = 0;
//  }else{
//    counter++;
//  }
  
}
