
#include <windows.h>

int main(void);
int _stdcall WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow)
{
	main();
}

#include "tgui.h"
#include "tgui_core.h"
#include "tgui_font.h"
#include <stdio.h>


#include "simulater.h"




int Demo_PutC(__IN__ char c)
{
	//printf("%c", c);

	return 0;
}



TGUI_COLOR Demo_ReadPixeHook(__IN__ size_t x, __IN__ size_t y)
{
	return 0;
}
int main(void)
{

	struct TGUI_OPT_HOOK opt;

	memset(&opt, 0, sizeof(struct TGUI_OPT_HOOK));

	opt.TGUI_Putc = Demo_PutC;
	opt.TGUI_InitHook =  (void *(*)(void))SimulaterInit;
	opt.TGUI_WritePixeHook = SimulaterDrawPoint;
	opt.TGUI_ReadPixeHook = Demo_ReadPixeHook;
	

	if(TGUI_Init(&opt) == NULL)
	{
		//printf(">TGUI Init err\n");
		for(;;);
	}

	TGUI_2DDrawLine(1,1, 20,8, TGUI_COLOR_RED);
	
}
