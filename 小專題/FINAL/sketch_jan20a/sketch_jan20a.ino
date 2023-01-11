unsigned int snd = 2;
#define red_led 11
#define gree_led 10
#define blue_led 9
int r = 0;
int g = 0;
int b = 0;
int color;
 
void setup() {
    Serial.begin(9600);
      pinMode(red_led, OUTPUT);
      pinMode(gree_led, OUTPUT);
      pinMode(blue_led, OUTPUT);
}
 
void loop() {
    snd = analogRead(A0); 
    Serial.println(snd);
    
    if(snd>=300)
    {
      fast();
    }
    else
    {
     slow();
    }
}

void slow()
{
  analogWrite(red_led, r);
  delay(500);
  r+=10;
  if(r>=255)
  {
    analogWrite(gree_led, g);
    delay(500);
    g+=10;
    if(g>=255)
    {
      analogWrite(blue_led, b);
      delay(500);
      b+=10;

     }
     if(r>=255&&g>=255&&b>=255)
     {
      r=0;
      g=0;
      b=0;
      }
     
  } 
}

void fast()
{
  color = random(1, 8);
  switch(color)
  {
  case 1://'b' 紅
      digitalWrite(red_led, HIGH);
      digitalWrite(gree_led, LOW);
      digitalWrite(blue_led, LOW);
      delay(100);
      break;
      case 2:// 綠
     digitalWrite(red_led, HIGH);
     digitalWrite(gree_led, LOW);
     digitalWrite(blue_led, LOW);
      delay(100);
      break;
     case 3:// 黃
     digitalWrite(red_led, HIGH);
     digitalWrite(gree_led, HIGH);
     digitalWrite(blue_led, LOW);
      delay(100);
      break;
      
     case 4:// 藍
    digitalWrite(red_led, LOW);
    digitalWrite(gree_led, LOW);
    digitalWrite(blue_led, HIGH);
      delay(100);
      break;
      case 5:// 紫
    digitalWrite(red_led, HIGH);
    digitalWrite(gree_led, LOW);
    digitalWrite(blue_led, HIGH);
      delay(100);
      break;
      case 6:// 青
    digitalWrite(red_led, LOW);
    digitalWrite(gree_led, HIGH);
    digitalWrite(blue_led, HIGH);
      delay(100);
      break;
      case 7:// 青
    digitalWrite(red_led, HIGH);
    digitalWrite(gree_led, HIGH);
    digitalWrite(blue_led, HIGH);
      delay(100);
      break;
  }
}
