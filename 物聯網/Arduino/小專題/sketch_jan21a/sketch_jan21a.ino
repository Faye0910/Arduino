int Led=13;                                            //設定LED腳位為第13孔
int buttonpin=2;                                    //設定感測器D0腳位為第3孔
int val;                                                     //設定變量val
void setup()
{
Serial.begin(9600);
pinMode(Led,OUTPUT);                     //設定LED为输出
pinMode(buttonpin,INPUT);              //設定感測器D0为輸入
}
void loop()
{
val=digitalRead(buttonpin);              //將感測器的值讀取給给val
Serial.println(val);
if(val==HIGH)                                       //當感測器测有信號時，LED閃爍
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
