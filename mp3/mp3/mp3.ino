#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int sw=7;   //開關停
boolean lastState=LOW;
int clickNum=0;
const int ne=8;   //開關下首
boolean lastState2=LOW;
int clickNum2=0;
int s=0;
boolean isPlaying = false;

void setup() {
  pinMode(sw,INPUT);

  Serial.begin (9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial); 
  
  mp3_set_volume (15);
  isPlaying = true;
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
  if(clickNum==2)
  { 
    s++;
    clickNum=0;   
    if(s%2==1)
    {
      if(isPlaying==true)
      {
        
        mp3_play(2);
       isPlaying=false;
      }
    }
    if(s%2==0)
    {
       if(isPlaying==false)
      {
       mp3_stop();
       isPlaying=true;
      }
    }
  }
Serial.println(clickNum);
Serial.println(isPlaying);
Serial.println(s);
    delay(1000);

    
  boolean b3=digitalRead(ne);

  if(b3!=lastState2)
  {
    delay(20);
    boolean b4=digitalRead(ne);

    if(b3==b4)
    {
      lastState2=b3;
      clickNum2++;
    }
  
if(clickNum2==2)
  {    
    mp3_play (1);
    //delay(3000);
  }
    if(clickNum2==4)
  {
      mp3_play(2);
      clickNum2=0;
  }
    
  }
  }
