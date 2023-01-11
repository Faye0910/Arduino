const int a[8]={2,3,4,5,6,7,8,9};
const int sw=10; //開關
boolean lastState=HIGH;
boolean toggle=LOW;
int clickNum=0;

void setup() {
 for(int i=0;i<8;i++)
 {
  pinMode(a[i],OUTPUT);
 }
 
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
  if(clickNum==2) //顯示0
  {
    toggle=!toggle;

    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,1);
  }
  if(clickNum==4)  //顯示1
  {
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  if(clickNum==6)  //顯示2
  {
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,0);
  }
  if(clickNum==8)  //顯示3
  {
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,0);
  }
  if(clickNum==10) //顯示4
  {
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
  if(clickNum==12)  //顯示5
  {
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
  if(clickNum==14)  //顯示6
  {
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
  if(clickNum==16)  //顯示7
  {
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  if(clickNum==18)  //顯示8
  {
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
  if(clickNum==20)  //顯示9
  {
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
  if(clickNum==22)
  {
    clickNum=2;

    for(int i=0;i<8;i++)
    {
    digitalWrite(a[i],HIGH);
    }
  }
 
}
