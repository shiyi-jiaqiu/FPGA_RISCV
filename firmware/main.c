/*
 * Copyright (c) 2017-2018, Alex Taradov <alex@taradov.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*- Includes ----------------------------------------------------------------*/
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "soc.h"
#include"spi.h"
#include"timer.h"
#include"st7735.h"
/*- Definitions -------------------------------------------------------------*/

/*- Constants ---------------------------------------------------------------*/


/*- Types -------------------------------------------------------------------*/


/*- Variables ---------------------------------------------------------------*/


/*- Prototypes --------------------------------------------------------------*/
int p_vsnprintf(char *buf, size_t size, const char *fmt, va_list ap);
int p_snprintf(char *str, size_t size, const char *fmt, ...);

/*- Implementations ---------------------------------------------------------*/

//-----------------------------------------------------------------------------
void uart_init(int br)
{
  UART->BR = F_CPU / br;
}

//-----------------------------------------------------------------------------
void iputc(int c)
{
  while (0 == (UART->CSR & UART_CSR_TX_READY));
  UART->DATA = c;
}

//-----------------------------------------------------------------------------
int igetc(void)
{
  if (UART->CSR & UART_CSR_RX_READY)
    return UART->DATA;

  return -1;
}

//-----------------------------------------------------------------------------
void iputs(char *s)
{
  while (*s)
    iputc(*s++);
}

//-----------------------------------------------------------------------------
void iprintf(const char *fmt, ...)
{
  char str[200];
  va_list ap;

  va_start(ap, fmt);
  p_vsnprintf(str, sizeof(str), fmt, ap);
  va_end(ap);

  iputs(str);
}






int main(void)
{
  uart_init(115200);
  timer_init(1);
  spi_init();
  GPIO->WRITE=0x00;
  Lcd_Init();
  Lcd_Clear(0);
  float a=5.6,b=2.77;
  iprintf("fp:%.2f\r\n",a+b);
  while(1)
  {
    
   Gui_Circle(50,50,20,0xffff);
   Gui_DrawLine(80,80,100,100,0x00ff);
  }
  return 0;
}

//-----------------------------------------------------------------------------
void entry(void)
{
  extern unsigned int _bss;
  extern unsigned int _ebss;

  for (unsigned int *dst = &_bss; dst < &_ebss; dst++)
    *dst = 0;

  main();
}

