
#include "core.h"


char ptTGUIPrintBuf[TGUI_PRINT_BUF_LEN];
struct TGUI_OPT_HOOK *gTGUIOpt = NULL;


void TGUI_DrawPoint(unsigned int x, unsigned int y, TGUI_COLOR color)
{
	//tGUI_IFWritePointHook(x, y, color);
}

void TGUI_DrawLine(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey,TGUI_COLOR color)
{
	unsigned int i=0;

	for(i=sx; i<ex; i++)
	{
		//tGUI_IFWritePointHook(i, i*(ey-sy)/(ex-sx) + sy, color);
	}
}

#ifdef TGUI_PRINT
int TGUI_Printf(__IN__ char *fmt, ...)
{
	va_list list;
	int revl = -1;
	size_t i = 0;
	
	va_start(list, fmt);
	revl = vsprintf(ptTGUIPrintBuf, fmt, list);
	if(revl > 0)
	{
		for(i=0; i<revl; i++)
		{
			gTGUIOpt->TGUI_Putc(ptTGUIPrintBuf[i]);
		}
	}
	
	va_end(list);
	return revl;
}
#endif

void *TGUI_Init(struct TGUI_OPT_HOOK *opt)
{

	//校验/注册传入方法
	assert(opt);
	if(!opt->TGUI_Malloc)
		opt->TGUI_Malloc = malloc;

	if(!opt->TGUI_Free)
		opt->TGUI_Free = free;

	gTGUIOpt = (struct TGUI_OPT_HOOK *)opt->TGUI_Malloc(sizeof(struct TGUI_OPT_HOOK));
	assert(gTGUIOpt);
	memcpy(gTGUIOpt, opt, sizeof(struct TGUI_OPT_HOOK));	


#ifdef TGUI_PRINT
	assert(gTGUIOpt->TGUI_Putc);
#endif

	if((!gTGUIOpt->TGUI_InitHook)||
		(!gTGUIOpt->TGUI_WritePixeHook)||
		(!gTGUIOpt->TGUI_ReadPixeHook))
	{
	
#ifdef TGUI_PRINT
		TGUI_Printf("TGUI_InitHook()/TGUI_InitHook()/TGUI_InitHook() not filled\n");	
#endif
		return NULL;
	}

	//用户初使化方法
	return gTGUIOpt->TGUI_InitHook();
}

void TGUI_Exit(void)
{
	if(gTGUIOpt)
		gTGUIOpt->TGUI_Free(gTGUIOpt);		
}

