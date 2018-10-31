#ifndef _WGUI_H
#define _WGUI_H

//常用颜色定义
#define TGUI_COLOR_WHITE   (0xffff)
#define TGUI_COLOR_BLACK   (0x0000)

#define TGUI_COLOR_RED     (0xf800)
#define TGUI_COLOR_GREEN   (0x07e0)
#define TGUI_COLOR_BLUE    (0x001f)

extern struct TGUI_OPT_HOOK *gTGUIOpt;


void *TGUI_Init(struct TGUI_OPT_HOOK *opt);


#endif

