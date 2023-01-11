const int a[8]={2,3,4,5,6,7,8,9};
void setup() {
  
for(int i=0;i<8;i++)
 {
  pinMode(a[i],INPUT);
 }
}

void loop() {
  digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);

}
