int a=8;
int b=5;
boolean c;
static int t;
static unsigned long Time;
#define DEBOUNCE_DELAY 200
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, INPUT);
  t=LOW;
  digitalWrite(a,t);
}
void loop() {
  digitalWrite(2,LOW);
  digitalWrite(b,HIGH);
  c=digitalRead(b);
  Serial.println(c);
  
  if(c==LOW)
  {
     unsigned long tt=millis();
     if((tt-Time)>DEBOUNCE_DELAY)
     {
      Time=tt;
      t=t==HIGH?LOW:HIGH;
      digitalWrite(a,t);
     }

  }
}
