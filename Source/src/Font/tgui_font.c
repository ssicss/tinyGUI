#include "font.h"

struct WGUI_FONT gWGUI_Font={
	&font_0812_sum[0],
};



static _FontDrawChar(unsigned int x, unsigned int y, WGUI_COLOR color, const char ch)
{
	unsigned int xdst = 0;
	unsigned int ydst = 0;
	unsigned int i = 0;
	unsigned int j = 0;

	//»ñÈ¡×Ö·û¼ä¾à
	xdst = gWGUI_Font.finfo->x;
	ydst = gWGUI_Font.finfo->y;


	

	for(j=y; j<=ydst+y; j++ )
	{
		for(i=x; i<=xdst+x; i++ )
		{
			if(((gWGUI_Font.finfo->db[j-y])&(1<<(i-x))) == 0)
			{
				WGUI_DrawPoint(i,j,WGUI_COLOR_RED);
			}else{
				WGUI_DrawPoint(i,j,WGUI_COLOR_BLUE);
			}
			
		}
	}

	
}

void WGUI_ShowTextAt(unsigned int x, unsigned int y, WGUI_COLOR color, const char *str)
{
	char * tmp_str = (char *)str;

	while(*tmp_str!= '\0')
	{
		_FontDrawChar(x,y,color,*tmp_str);
		x+=gWGUI_Font.finfo->x;
		tmp_str++;
	}

}

