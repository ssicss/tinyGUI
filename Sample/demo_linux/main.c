#include <stdio.h>
#include <string.h>

#include "tgui.h"
#include "tgui_type.h"


int Demo_PutC(__IN__ char c)
{
	printf("%c", c);
}

int test = 1;
int *Demo_InitHook(void)
{


	return &test;
}


void Demo_WritePixeHook(__IN__ size_t x, __IN__ size_t y, TGUI_COLOR color)
{
	printf(">wp:%d, %d, %d\n", x, y, color);
}
TGUI_COLOR Demo_ReadPixeHook(__IN__ size_t x, __IN__ size_t y)
{
	return 0;
}


int main(int argc, char *argv[])
{

	struct TGUI_OPT_HOOK opt;

	memset(&opt, 0, sizeof(struct TGUI_OPT_HOOK));

	opt.TGUI_Putc = Demo_PutC;
	opt.TGUI_InitHook =  (void *(*)(void))Demo_InitHook;
	opt.TGUI_WritePixeHook = Demo_WritePixeHook;
	opt.TGUI_ReadPixeHook = Demo_ReadPixeHook;
	

	if(TGUI_Init(&opt) == NULL)
	{
		printf(">TGUI Init err\n");
		for(;;);
	}

	TGUI_2DDrawLine(1,1, 20,8, TGUI_COLOR_RED);
	
}



