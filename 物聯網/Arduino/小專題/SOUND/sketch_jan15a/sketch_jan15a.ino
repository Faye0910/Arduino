#define RED_PIN   9
#define GREEN_PIN 10
#define BLUE_PIN  11
enum
{
  RED = 0,
  GREEN,
  BLUE
};
#define DELAY_DURATION 33
int fade_val;

int SOUND_VOLUME_PIN = 2 ;
int SOUND_THRESHOLD = 270;
int SOUND_MAX = 400;
int soundValue;

int ledMaxValue;
int randomMaxColor;

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  
  randomSeed(analogRead(RED_PIN));
  randomSeed(analogRead(GREEN_PIN));
  randomSeed(analogRead(BLUE_PIN));
  
  OneColor(RED_PIN, GREEN_PIN, BLUE_PIN);
  OneColor(GREEN_PIN, RED_PIN, BLUE_PIN);
  OneColor(BLUE_PIN, RED_PIN, GREEN_PIN);
  TwoColor(RED_PIN, GREEN_PIN, BLUE_PIN); 
  TwoColor(RED_PIN, BLUE_PIN, GREEN_PIN);
  TwoColor(GREEN_PIN, BLUE_PIN, RED_PIN);
  ThreeColor(RED_PIN, GREEN_PIN, BLUE_PIN);
  
  Serial.begin(9600);
}

void loop()
{ 
  soundValue = analogRead(SOUND_VOLUME_PIN);
  Serial.println(soundValue);
  if (soundValue > SOUND_THRESHOLD)
  {
    //Serial.print("Sound Sensor Volume = ");
    

    ledMaxValue = map(soundValue, SOUND_THRESHOLD, SOUND_MAX, 0, 255);
    randomMaxColor = random(0, 3);

    //Serial.print("  PWM = ");
    //Serial.print(ledMaxValue);
    //Serial.print(" , Max Color = ");
    switch(randomMaxColor)
    {
      case RED:
        //Serial.println("Red");
        analogWrite(RED_PIN, ledMaxValue);
        analogWrite(GREEN_PIN, random(0, ledMaxValue));
        analogWrite(BLUE_PIN, random(0, ledMaxValue));
        break;
        
      case GREEN:
        //Serial.println("Green");
        analogWrite(GREEN_PIN, ledMaxValue);
        analogWrite(RED_PIN, random(0, ledMaxValue));
        analogWrite(BLUE_PIN, random(0, ledMaxValue));
        break;
        
      case BLUE:
        //Serial.println("Blue");
        analogWrite(BLUE_PIN, ledMaxValue);
        analogWrite(RED_PIN, random(0, ledMaxValue));
        analogWrite(GREEN_PIN, random(0, ledMaxValue));
        break;
        
      default:
        //Serial.println("White");
        analogWrite(RED_PIN, ledMaxValue);
        analogWrite(GREEN_PIN, ledMaxValue);
        analogWrite(BLUE_PIN, ledMaxValue);
        break;
    }
    delay(DELAY_DURATION); /* no delay, LED will flash quickly */
  }
  else
  {    
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  }
}

void OneColor(int _on, int _off1, int _off2)
{
  analogWrite(_on, 0);
  analogWrite(_off1, 0);
  analogWrite(_off2, 0);
  delay(300);
  
  for (fade_val=0; fade_val<290; fade_val=fade_val+5)
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
  delay(300);
  
  for (fade_val=0; fade_val<290; fade_val=fade_val+5)
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
  for (fade_val=0; fade_val<290; fade_val=fade_val+5)
  {
    analogWrite(_on1, fade_val);
    analogWrite(_on2, fade_val);
    analogWrite(_on3, fade_val);
    delay(DELAY_DURATION);
  }
} 
