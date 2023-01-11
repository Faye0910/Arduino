#include <Wire.h>
#include <motoLiquidCrystal_I2C.h>
 LiquidCrystal_I2C mylcd(0x27,16,2);
 void setup()
 {
 mylcd.init();//初始化
 mylcd.backlight();//開啟背光
 mylcd.clear();//清除畫面
 mylcd.setCursor(0,0);//設定游標位置
 mylcd.print("hello");
 }
 void loop()
 {
 }
