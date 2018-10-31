#ifndef _FONT_H
#define _FONT_H


#include "Tgui.h"
#include "Tgui_config.h"

struct TGUI_FONT_INFO{
	unsigned char ascii;
	unsigned int  x;
	unsigned int  y;
	unsigned char *db;
};

struct TGUI_FONT{
	struct TGUI_FONT_INFO *finfo;
};


extern struct TGUI_FONT_INFO font_0812_sum[1];


#endif
