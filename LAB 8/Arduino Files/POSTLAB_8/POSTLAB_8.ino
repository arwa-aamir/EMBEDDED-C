#include<Wire.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


byte sec_bcd, min_bcd, h_bcd, day_bcd, date_bcd, month_bcd, year_bcd, h_val, am_pm_val;
unsigned int seconds_1, minutes_1, hour_1, day_1, date_1, month_1, year_1;

void set_data() {
  Wire.beginTransmission(104); 
  Wire.write(byte(0x00));
  Wire.write(0);
  Wire.write(byte(0x15));
  Wire.write(byte(0x62));
  Wire.write(byte(0x03));
  Wire.write(byte(0x22));
  Wire.write(byte(0x06));
  Wire.write(byte(0x20));
  Wire.endTransmission();
}


void read_data() {
 Wire.beginTransmission(104);
 Wire.write(0x00);
 Wire.endTransmission();
 Wire.requestFrom(104,7);
 sec_bcd=Wire.read() & 0x7f;
 min_bcd=Wire.read() & 0x7f;
 h_bcd=Wire.read() & 0x3f;
 day_bcd=Wire.read() & 0x07;
 date_bcd=Wire.read() & 0x3f;
 month_bcd=Wire.read() & 0x1f; 
 year_bcd=Wire.read() & 0xff; 
 
 seconds_1=(sec_bcd>>4)*10 + (sec_bcd & 0x0f);
 minutes_1=(min_bcd>>4)*10 + (min_bcd & 0x0f);
 h_val=h_bcd & 0x1f;
 hour_1=(h_val>>4)*10 + (h_val & 0x0f);
 am_pm_val = h_bcd>>5; // (0 = AM , 1= PM)
 day_1=day_bcd;
 date_1=(date_bcd>>4)*10 + (date_bcd & 0x0f);
 month_1=(month_bcd>>4)*10 + (month_bcd & 0x0f);
 year_1=(year_bcd>>4)*10 + (year_bcd & 0x0f);
}

void setup(){
Wire.begin();
Serial.begin(9600);
lcd.begin(16,2);

set_data();
}

void loop(){
 read_data();
  
  lcd.print("TIME: ");
  lcd.print(String(hour_1));
  lcd.print(":");
  lcd.print(String(minutes_1));
  lcd.print(":");
  lcd.print(String(seconds_1));
  lcd.print(" ");
  if (am_pm_val>0)
  {
    lcd.print("PM");
    
  }
  else
  {
    lcd.print("AM");
  }
  lcd.setCursor(0,1);
  lcd.print("DATE: ");
  lcd.print(String(date_1));
  lcd.print("-");
  lcd.print(String(month_1));
  lcd.print("-");
  lcd.print(String(year_1));
  delay(1000); 
  lcd.clear(); 
  
}
