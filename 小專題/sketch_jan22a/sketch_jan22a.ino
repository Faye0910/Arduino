#define LEDR 11
#define LEDG 10
#define LEDB 9

void setup() {               
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

int r = 0;
int g = 0;
int b = 0;
void loop() {
  analogWrite(LEDR, r);
  delay(100);
  r++;
  if(r>=255)
  {
    analogWrite(LEDG, g);
    g++;
    if(g>=255)
    {
      analogWrite(LEDB, b);
      b++;
      if(r>=255 && g>=255 &&b>=255 )
      {
        r=0;
        g=0;
        b=0;
      }
      }
  }
}
