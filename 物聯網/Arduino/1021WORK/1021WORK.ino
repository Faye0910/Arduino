const int ledY=8; //黃色
const int sw=7;   //開關
boolean lastState=LOW;
boolean toggle=LOW;
int clickNum=0;

void setup() {
  pinMode(ledY,OUTPUT);
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
    toggle=!toggle;
    clickNum=0;
    digitalWrite(ledY,toggle);   
  }
  
}
