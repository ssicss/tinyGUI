#ifndef _FONT_H
#define _FONT_H


#include "wgui.h"
#include "wgui_config.h"

struct WGUI_FONT_INFO{
	unsigned char ascii;
	unsigned int  x;
	unsigned int  y;
	unsigned char *db;
};

struct WGUI_FONT{
	struct WGUI_FONT_INFO *finfo;
};


extern struct WGUI_FONT_INFO font_0812_sum[1];

void WGUI_ShowTextAt(unsigned int x, unsigned int y, WGUI_COLOR color, const char *str);


#endif
