#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int sw=7;
const int sw1=6;
const int sw2=5;
const int sw3=4;
boolean laststate=LOW;
boolean toggle=LOW;
int clickNum=0;
int b=0;
boolean laststate1=LOW;
boolean toggle1=LOW;
int clickNum1=0;
boolean laststate2=LOW;
boolean toggle2=LOW;
int clickNum2=0;
boolean laststate3=LOW;
boolean toggle3=LOW;
int clickNum3=0;
int v=15;


unsigned long t1;      // 按鈕被按下的起始時間
unsigned long t2;       // 持續時間
unsigned long t3;
void setup () {
	Serial.begin (9600);
	mySerial.begin (9600);
	mp3_set_serial (mySerial);
	mp3_set_volume (15);
  pinMode(sw,INPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
}


//
void loop () {

boolean b1=digitalRead(sw);

if(b1!=laststate)
{
  delay(20);
  boolean b2=digitalRead(sw);
  if(b1==b2)
  {
    laststate=b1;
    clickNum++;
    if(clickNum==1)
    t1=millis();
    if(clickNum==2)
    t2=millis();

  }

  if(clickNum==2)
  {
    clickNum=0;
    toggle=!toggle;
    b++;
    t3=t2-t1;
    if(t3>1000)
    {
      mp3_stop();
      b=0;
    }
    else
    {
      if(b%2==1)
     {
       if(b==1)
       mp3_play(1);
       else
        mp3_play();
     }
     if(b%2==0)
     {
       mp3_pause ();
     }
    }
  }
}
boolean b3=digitalRead(sw1);

if(b3!=laststate1)
{
  delay(20);
  boolean b4=digitalRead(sw1);
  if(b3==b4)
  {
    laststate1=b3;
    clickNum1++;
  }

  if(clickNum1==2)
  {
    clickNum1=0;
    toggle1=!toggle1;
    mp3_next ();
  }
}

boolean b5=digitalRead(sw2);

if(b5!=laststate2)
{
  delay(20);
  boolean b6=digitalRead(sw2);
  if(b5==b6)
  {
    laststate2=b5;
    clickNum2++;
  }

  if(clickNum2==2)
  {
    clickNum2=0;
    toggle2=!toggle2;
    v+=2;
    mp3_set_volume (v);
  }
}

boolean b7=digitalRead(sw3);

if(b7!=laststate3)
{
  delay(20);
  boolean b8=digitalRead(sw3);
  if(b7==b8)
  {
    laststate3=b7;
    clickNum3++;
  }

  if(clickNum3==2)
  {
    clickNum3=0;
    toggle3=!toggle3;
    v-=2;
    mp3_set_volume (v);
  }
}
}

/*
   mp3_play ();		//start play
   mp3_play (5);	//play "mp3/0005.mp3"
   mp3_next ();		//play next 
   mp3_prev ();		//play previous
   mp3_set_volume (uint16_t volume);	//0~30
   mp3_set_EQ ();	//0~5
   mp3_pause ();
   mp3_stop ();
   void mp3_get_state (); 	//send get state command
   void mp3_get_volume (); 
   void mp3_get_u_sum (); 
   void mp3_get_tf_sum (); 
   void mp3_get_flash_sum (); 
   void mp3_get_tf_current (); 
   void mp3_get_u_current (); 
   void mp3_get_flash_current (); 
   void mp3_single_loop (boolean state);	//set single loop 
   void mp3_DAC (boolean state); 
   void mp3_random_play (); 
 */
