


/**************windowsÈë¿Úº¯Êý*************/
int main(void);
#include <windows.h>
int _stdcall WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow)
{
	main();
}


#include "core.h"
#include "font.h"
#include <stdio.h>

int main(void)
{
	unsigned int i = 0;
	unsigned int j = 0;

	if(WGUI_Init() != WGUI_TRUE)
	{
		while(1);
	}
	
	WGUI_DrawLine(10,10, 100, 150 ,WGUI_COLOR_RED);

	WGUI_DrawRectangle(20,20,100,100,WGUI_COLOR_RED,WGUI_IS_FILL);
	WGUI_DrawRectangle(120, 120, 300, 300, WGUI_COLOR_RED, WGUI_IS_NOT_FILL);

	WGUI_ShowTextAt(50,120,WGUI_COLOR_RED,"aaa");
	while (1);
	
}