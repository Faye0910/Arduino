void setup()
 {
 Serial.begin(9600);
 pinMode(2, OUTPUT);
 pinMode(3, INPUT);
 }
 void loop()
 {
 Serial.println(ultrasonic_distance_2_3( ));
 delay(20);
}
float ultrasonic_distance_2_3() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
delayMicroseconds(5);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);
unsigned long sonic_duration = pulseIn(3, HIGH);
float distance_cm = (sonic_duration / 2.0) / 29.1;
return distance_cm;
}
