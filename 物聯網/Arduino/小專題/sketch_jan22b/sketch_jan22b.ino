int ledPin = 13;
int sensorPin = 7;
boolean val = 0;
boolean ledOn =0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =digitalRead(sensorPin);
     Serial.println (val);
}
