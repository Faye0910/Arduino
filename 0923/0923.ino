const int ledR=8; //紅色   //const宣告是固定值，鎖住
const int ledY=9; //黃色
const int ledG=10; //綠色
const int sw=7;   //開關
boolean lastState=LOW;
boolean toggle=LOW;
int clickNum=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(sw,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
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

  if(clickNum==2)
  {
    toggle=!toggle;
    
    digitalWrite(ledR,toggle);   
  }
  if(clickNum==4)
  {
    digitalWrite(ledR,LOW);

    digitalWrite(ledY,HIGH);
  }
  if(clickNum==6)
  {
    digitalWrite(ledY,LOW);

    digitalWrite(ledG,HIGH);
  }
  if(clickNum==8)
  {
    clickNum=0;
    digitalWrite(ledG,LOW);
  }
  Serial.println(clickNum);
}
