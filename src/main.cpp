#include <Arduino.h>

volatile bool on = false;

ISR(PCINT0_vect)
{
  if(on){
    PORTH &= 0 << PORTH4;
    on = false;
    Serial.println("off");
  }
  else
  {
    PORTH |= 1 << PORTH4;
    on = true;
    Serial.println("on");
  }

}

void setup() 
{
  PCICR |= 1 << PCIE0; // set to generate interrupts
  PCMSK0 |= 1 << PCINT5; // enable on pin 5

  DDRH |= 1 << DD4; // set to output
  PORTH &= 0 << DD4;

  DDRB &= 0 << DD5; // set to input with pullup enabled
  PORTB |= 1 << DD5;
}

void loop() 
{
  
}