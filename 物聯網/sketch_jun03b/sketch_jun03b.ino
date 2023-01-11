#include "motoDHT.h"
DHT d(12, DHT11);
void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(12, INPUT);
d.begin();
Serial.println("Program Start");
}
void loop() {
int t = d.readTemperature();
Serial.print("Now Temperature is:");
Serial.println(t);
if(t>=29){
Serial.println("Temperature is too high");
tone(9,659,300);
}
delay(1000);
}
