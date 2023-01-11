const int a[7]={2,3,4,5,6,7,8};
const int b=12;
void setup() {
for(int i=0;i<7;i++)
{
  pinMode(a[i],OUTPUT);
 }
  Serial.begin(9600);
//pinMode(b,INPUT);
}

void loop() {
  //d=digitalRead(b);
  //if(d=HIGH)
  //{
    for(int i=0;i<7;i++)
    {
      digitalWrite(a[i],HIGH);
      Serial.println(a[i]);
     }
  //}
  
}
