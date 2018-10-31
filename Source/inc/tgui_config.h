#ifndef _TGUI_CONFIG_H
#define _TGUI_CONFIG_H

#include "tgui_type.h"


#define TGUI_COLOR_DEPTH 		 (TGUI_COLOR_BITS_16)
#define TGUI_COLOR_STORE_METHOD  (TGUI_COLOR_STORE_RGB565)

#define TGUI_PRINT
#define TGUI_PRINT_BUF_LEN  (128)

#undef  NDEBUG        //是否使用断言


#ifndef TGUI_COLOR_DEPTH
	#ifndef TGUI_COLOR_STORE_METHOD	
	#error "TGUI_COLOR_DEPTH or TGUI_COLOR_STORE_METHOD not fit"
	#endif
#endif

#endif
