#include"timer.h"

//-----------------------------------------------------------------------------
void timer_init(int interval_us)
{
  TIMER->COUNT = 0;
  TIMER->COMPARE = interval_us * (F_CPU / 1000000);
  TIMER->CSR = TIMER_CSR_ENABLE | TIMER_CSR_OVERFLOW;
}
//-----------------------------------------------------------------------------
void timerb_init(int interval_us)
{
  TIMERB->COUNT = 0;
  TIMERB->COMPARE = interval_us * (F_CPU / 1000000);
  TIMERB->CSR = TIMER_CSR_ENABLE | TIMER_CSR_OVERFLOW;
}
//-----------------------------------------------------------------------------
bool timer_expired(void)
{
  if (TIMER->CSR & TIMER_CSR_OVERFLOW)
  {
    TIMER->CSR = TIMER_CSR_OVERFLOW;
    return true;
  }

  return false;
}
//-----------------------------------------------------------------------------
bool timerb_expired(void)
{
  if (TIMERB->CSR & TIMER_CSR_OVERFLOW)
  {
    TIMERB->CSR = TIMER_CSR_OVERFLOW;
    return true;
  }

  return false;
}

void delay_ms(uint32_t delay_xms)
{
  timerb_init(delay_xms*1000);
  while(timerb_expired()==false);
}
//-----------------------------------------------------------------------------
void delay_us(uint32_t delay_xus )
{
  timerb_init(delay_xus);
  while(timerb_expired()==false);
}