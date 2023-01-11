#define red_led   9
#define gree_led 10
#define blue_led  11
#define DELAY_DURATION 33
int snd = 2;
int fade_val;
int val;
int ch;
int ledMaxValue;
int color;
int randomMaxColor;
int SOUND_THRESHOLD = 260;
int SOUND_MAX = 500;

void setup() {
    Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(gree_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
 
}
 
void loop() {
     val = analogRead(snd); 
    Serial.println(val);

    ledMaxValue = map(val, 300, 500, 0, 255);
 if (val > SOUND_THRESHOLD)
  {
    color = random(1, 8);
  switch(color)
  {
  case 1://'b' 紅
      digitalWrite(red_led, ledMaxValue);
      digitalWrite(gree_led, LOW);
      digitalWrite(blue_led, LOW);
      delay(50);
      break;
      case 2:// 綠
     digitalWrite(red_led, ledMaxValue);
     digitalWrite(gree_led, LOW);
     digitalWrite(blue_led, LOW);
      delay(50);
      break;
     case 3:// 黃
     digitalWrite(red_led, ledMaxValue);
     digitalWrite(gree_led, ledMaxValue);
     digitalWrite(blue_led, LOW);
      delay(50);
      break;
      
     case 4:// 藍
    digitalWrite(red_led, LOW);
    digitalWrite(gree_led, LOW);
    digitalWrite(blue_led, ledMaxValue);
      delay(50);
      break;
      case 5:// 紫
    digitalWrite(red_led, ledMaxValue);
    digitalWrite(gree_led, LOW);
    digitalWrite(blue_led, ledMaxValue);
      delay(50);
      break;
      case 6:// 青
    digitalWrite(red_led, LOW);
    digitalWrite(gree_led, ledMaxValue);
    digitalWrite(blue_led, ledMaxValue);
      delay(50);
      break;
      case 7:// 青
    digitalWrite(red_led, ledMaxValue);
    digitalWrite(gree_led, ledMaxValue);
    digitalWrite(blue_led, ledMaxValue);
      delay(50);
      break;
   }
   
 }else
  {  
    ch = random(1, 8);
    switch(ch)
  {
    case 1:  
    OneColor(red_led,gree_led,blue_led);
    case 2:
    OneColor(gree_led, red_led, blue_led);
    case 3:
    OneColor(blue_led, red_led, gree_led);
    case 4:
  TwoColor(red_led,gree_led, blue_led); 
  case 5:
  TwoColor(red_led,blue_led,gree_led);
  case 6:
  TwoColor(gree_led,blue_led, red_led);
  case 7:
  ThreeColor(red_led,gree_led,blue_led);
  }
  } 
  
 
}

void OneColor(int _on, int _off1, int _off2)
{
  analogWrite(_on, 0);
  analogWrite(_off1, 0);
  analogWrite(_off2, 0);
  
  for (fade_val=0; fade_val<225; fade_val=fade_val+5)
  {
    analogWrite(_on, fade_val);
    delay(DELAY_DURATION);
  }
}

void TwoColor(int _on1, int _on2, int _off)
{
  analogWrite(_on1, 0);
  analogWrite(_on2, 0);
  analogWrite(_off, 0);
  
  for (fade_val=0; fade_val<225; fade_val=fade_val+5)
  {
    analogWrite(_on1, fade_val);
    analogWrite(_on2, fade_val);
    delay(DELAY_DURATION);
  }
}

void ThreeColor(int _on1, int _on2, int _on3)
{
  analogWrite(_on1, 0);
  analogWrite(_on2, 0);
  analogWrite(_on3, 0);
  for (fade_val=0; fade_val<225; fade_val=fade_val+5)
  {
    analogWrite(_on1, fade_val);
    analogWrite(_on2, fade_val);
    analogWrite(_on3, fade_val);
    delay(DELAY_DURATION);
  }
}
