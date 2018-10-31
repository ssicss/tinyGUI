#ifndef _TGUI_H
#define _TGUI_H

#include  "tgui_type.h"

//常用颜色定义
#define TGUI_COLOR_WHITE   (0xffff)
#define TGUI_COLOR_BLACK   (0x0000)

#define TGUI_COLOR_RED     (0xf800)
#define TGUI_COLOR_GREEN   (0x07e0)
#define TGUI_COLOR_BLUE    (0x001f)

extern struct TGUI_OPT_HOOK *gTGUIOpt;


void *TGUI_Init(struct TGUI_OPT_HOOK *opt);



/***********************2D图形库******************************/
void TGUI_2DDrawPixe(__IN__ size_t x, 
							__IN__ size_t y, 
							__IN__ TGUI_COLOR color);

void TGUI_2DDrawLine(__IN__ size_t sx, 
						  __IN__ size_t sy, 
						  __IN__ size_t ex, 
						  __IN__ size_t ey,
						  __IN__ TGUI_COLOR color);


#endif

