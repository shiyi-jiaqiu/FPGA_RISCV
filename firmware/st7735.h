#ifndef _st7735s_h
#define _st7735s_h

#include "stdint.h"
#include"soc.h"
#define WIDTH  128
#define HEIGHT  160 
#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111

void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint16_t Color)   ;
void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint16_t fc) ;
void Lcd_Clear(uint16_t Color)   ;
unsigned int Lcd_ReadPoint(uint16_t x,uint16_t y);
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data);
void Lcd_SetXY(uint16_t x,uint16_t y);
void Lcd_SetRegion(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end);
void Lcd_Init(void);
void Lcd_Reset(void);
void Lcd_WriteReg(uint8_t Index,uint8_t Data);
void LCD_WriteData_16Bit(uint16_t Data);
void Lcd_WriteData(uint8_t Data);
void Lcd_WriteIndex(uint8_t Index);
#endif
