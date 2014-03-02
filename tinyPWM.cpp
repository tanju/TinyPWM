#include "tinyPWM.h"

void TinyPWM::begin( uint16_t freq ) const
{
  PORTB = 0;
  DDRB |=  0b00000010;   // set PB1 (= OCR1A) to be an output

  uint32_t requiredDivisor = (F_CPU/2)/(uint32_t)freq;

  uint16_t prescalerVal = 1;
  uint8_t prescalerBits = 1;
  while ((requiredDivisor + prescalerVal/2)/prescalerVal > 256)
  {
    ++prescalerBits;
    prescalerVal <<= 1;
  }
  
  uint8_t top = ((requiredDivisor + (prescalerVal/2))/prescalerVal) - 1;
  TCCR1 = (1 << CTC1) | prescalerBits;
  GTCCR = 0;
  OCR1C = top;
}

void TinyPWM::enable( boolean enabled ) const
{
  if( enabled ){
    TCNT1 = 0;
    TCCR1 |= (1 << COM1A0);
  }else{
    TCCR1 &= ~(1 << COM1A0);
  }
}
/*
void TinyPWM::disable() const
{
  enable(false);
}
*/