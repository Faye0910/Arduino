
#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 

# define ACTIVATED LOW



int buttonNext = 2;
int buttonPause = 3;
boolean isPlaying = false;

unsigned long startTime;      // 按鈕被按下的起始時間
unsigned long duration;       // 持續時間


void setup () {

pinMode(buttonPause, INPUT);
digitalWrite(buttonPause,HIGH);
pinMode(buttonNext, INPUT);
digitalWrite(buttonNext,HIGH);

mySerial.begin (9600);
delay(1000);
playFirst();
isPlaying = true;


}



void loop () { 

startTime = millis();  
 if (digitalRead(buttonPause) == ACTIVATED)
  {

     while (digitalRead(buttonPause)== ACTIVATED)   
     duration = millis() - startTime;      
    if(duration>1000)
    {
      stop();
      isPlaying = false;
      playFirst();
    }
    if(isPlaying)
    {
      pause();
      isPlaying = false;
    }else
    {
      isPlaying = true;
      play();
    }
  }

 if (digitalRead(buttonNext) == ACTIVATED)
  {
    if(isPlaying)
    {
      playNext();
    }
  }
}

void playFirst()
{
  execute_CMD(0x3F, 0, 0);
  delay(500);
  setVolume(25);
  delay(500);
  execute_CMD(0x11,0,1); 
  delay(500);
}

void pause()
{
  execute_CMD(0x0E,0,0);
  delay(500);
}

void stop()
{
  execute_CMD(0x16,0,0);
  delay(500);
}

void play()
{
  execute_CMD(0x0D,0,1); 
  delay(500);
}

void playNext()
{
  execute_CMD(0x01,0,1);
  delay(500);
}

void playPrevious()
{
  execute_CMD(0x02,0,1);
  delay(500);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); 
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
{
word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};
for (byte k=0; k<10; k++)
{
mySerial.write( Command_line[k]);
}
}
