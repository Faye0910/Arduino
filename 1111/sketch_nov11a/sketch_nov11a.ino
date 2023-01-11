int a = 8;
int sw=11;   //開關
boolean lastState=LOW;
int clickNum=0;
boolean toggle=LOW;

void setup() {
  pinMode(a, OUTPUT);  
  digitalWrite(a, LOW);
  pinMode(sw,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  boolean b1=digitalRead(sw);
  if(b1!=lastState)
  {
    delay(20);
    boolean b2=digitalRead(sw);

    if(b1==b2)
    {
      lastState=b1;
      clickNum++;
    }
  }
  Serial.println(clickNum);
  if(clickNum==2)
  {
    digitalWrite(a, HIGH);
    delay(20);
  }
  if(clickNum==4)
  {
    clickNum=0;
  digitalWrite(a, LOW);
  delay(20);
  }
}
