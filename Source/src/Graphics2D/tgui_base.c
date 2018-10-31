
#include "tgui_base.h"


void TGUI_2DDrawPixe(__IN__ size_t x, 
							__IN__ size_t y, 
							__IN__ TGUI_COLOR color)
{
	gTGUIOpt->TGUI_WritePixeHook(x, y, color);
}

void TGUI_2DDrawLine(__IN__ size_t sx, 
						  __IN__ size_t sy, 
						  __IN__ size_t ex, 
						  __IN__ size_t ey,
						  __IN__ TGUI_COLOR color)
{
	size_t i = 0;

	assert(((sx <= TGUI_LCD_WIDTH) || sx)||\
			((sy <= TGUI_LCD_WIDTH) || sy)||\
			((ex <= TGUI_LCD_HEIGH) || ex)||\
			((ey <= TGUI_LCD_HEIGH) || ey));

	assert((sx<ex)&&(sy<ey));

	for(i=0; i<=(ex-sx); i++)
	{
		gTGUIOpt->TGUI_WritePixeHook(i+sx, (ey-sy)*i/(ex-sx)+sy, color);
	}		
}



