const int a[8]={2,3,4,5,6,7,8,9};
const int sw=10; //開關
boolean lastState=HIGH;
boolean toggle=HIGH;
int clickNum=0;

void setup() {
 for(int i=0;i<8;i++)
 {
  pinMode(a[i],INPUT);
 }
 pinMode(sw,INPUT);
 Serial.begin(9600);
}

void loop() {

  int tim=0;
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
  if(clickNum/2==0)
  {
    tim=0;
    tim=millis();
    Serial.println(tim);
  
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);

    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
    delay(1000);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,1);
    delay(1000); 
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,1);
    delay(1000);

    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    delay(2000);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,1);
  
    delay(1000);
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    delay(2000);

  digitalWrite(11,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
    delay(1000);
    
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
    
    delay(1000);

    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
  
    delay(1000);
    
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,1);    

    delay(1000);

    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,1);

    delay(1000);
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);

   for(int i=0;i<8;i++)
    {
    digitalWrite(a[i],LOW);

    }
 }
}
