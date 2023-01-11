#include "motoDHT.h"
DHT A(12,DHT11);
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(12,INPUT);
  A.begin();
}

void loop() {
  int h=A.readHumidity();
  int t=A.readTemperature();
  digitalWrite(2,h<70);
  digitalWrite(5,t>27);
  Serial.print("Humidity");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print("*C\n");
  delay(1000);
  
}
