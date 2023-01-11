#include <Enerlib.h>

Energy energy;             // 宣告"Energy"程式物件
const byte swPin = 2;      // 開關腳位
const byte ledPin = 8;    // LED腳位
byte times = 0;            // 記錄執行次數
volatile byte state = 0;   // 暫存執行狀態
boolean lastState=HIGH;
int clickNum=0;

void wakeISR() {
   if (energy.WasSleeping()) {
    state = 1;
    Serial.println("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
  } else {
    Serial.println("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    state = 2;
    delay(100);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  attachInterrupt(digitalPinToInterrupt(swPin), wakeISR, RISING);  // 附加中斷服務常式
  Serial.println("Running...");
}

void loop()
{
  boolean b1=digitalRead(swPin);
  if(b1!=lastState)
  {
    delay(20);
    boolean b2=digitalRead(swPin);
    if(b1==b2)
    {
      lastState=b1;
      clickNum++;
    }
  }
  if(clickNum==2)
  {
    clickNum=0;
    times = 0;
    Serial.println("Go to sleep...");
    energy.PowerDown();
    state = 0;
  }
  
  
  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(500);
  times ++;
  Serial.println(times);

 
}
