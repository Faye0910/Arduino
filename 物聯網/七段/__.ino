#include <motoTM1637.h>
 TM1637 tm1637led_2_3(2,3);
 void setup()
 {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 }
 void loop()
 {
 for (int i = 0; i <= 9999; i=i+1) {
 tm1637led_2_3.display(i);
 delay(1000);
 }
 }
