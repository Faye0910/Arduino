#include <Enerlib.h>
Energy energy;
const byte LED = 13;
const byte BUTTON = 2;
volatile byte state = 0;   // 暫存執行狀態

// Interrupt Service Routine (ISR)
void switchPressed ()
{
  if (digitalRead (BUTTON) == HIGH)
    digitalWrite (LED, HIGH);
  else
    energy.PowerDown();
}

void setup ()
{
  pinMode (LED, OUTPUT);  // so we can update the LED
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);  // attach interrupt handler

}

void loop ()
{
 
} 
