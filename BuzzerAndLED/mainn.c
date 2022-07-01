#include "lpc17xx.h"

int getPinState(int pinNumber);		

int main(void)
{
	
  LPC_GPIO0->FIODIR &= ~(1 << 17); 	// Set button as input
  LPC_GPIO3->FIODIR |= (1 << 26); 	// Set LED as output
	LPC_GPIO2->FIOPIN |= (1 << 2);  // Turn LED OFF
  LPC_GPIO1->FIOCLR |= (1 << 26); //Turn off buzzer
	
  while (1)
  { 
    if (getPinState(17))  // Check button pressed
    {
      // Turn LED on
      LPC_GPIO3->FIOCLR = (1 << 26);
      
    }
    else
    {
     // Turn LED off
       LPC_GPIO3->FIOSET = (1 << 26);
    }
  }
}

int getPinState(int pinNumber)
{
  
  int pinBlockState = LPC_GPIO0->FIOPIN; // Read current state of pins
  // Read the value of 'pinNumber'
  int pinState = (pinBlockState & (1 << pinNumber)) ? 1 : 0;
  return pinState;	// Return the value of pinState
}


