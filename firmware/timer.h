#ifndef _timer_h
#define _timer_h
#include"soc.h"
#include"stdbool.h"
void timer_init(int interval_us);
void timerb_init(int interval_us);
bool timer_expired(void);
bool timerb_expired(void);
void delay_ms(uint32_t delay_xms);
void delay_us(uint32_t delay_xus );
#endif