#include <stdio.h>
#include <string.h>

#include "tgui.h"
#include "tgui_type.h"


int Demo_PutC(__IN__ char c)
{
	printf("%c", c);
}



int main(int argc, char *argv[])
{
	struct TGUI_OPT_HOOK opt;

	memset(&opt, 0, sizeof(struct TGUI_OPT_HOOK));

	opt.TGUI_Putc = Demo_PutC;


	TGUI_Init(&opt);

	
}



