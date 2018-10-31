#ifndef _TGUI_TYPE_H
#define _TGUI_TYPE_H

#include <stddef.h>
#include <stdbool.h>
#include "tgui_config.h"

#include <assert.h>


#ifdef _MSC_VER
	#define   __STATIC__  static 
	#define   __INLINE__  inline 
	#define    __IN__     const 
	
#elif __GNUC__  
	#define   __STATIC__  static 
	#define   __INLINE__  inline 
	#define    __IN__	  const 

#elif __ICCARM__   
	#define   __STATIC__  static 
	#define   __INLINE__  inline 
	#define    __IN__	  const 

#elif __CC_ARM  
	#define   __STATIC__  static 
	#define   __INLINE__  inline 
	#define    __IN__	  const 


#else
	#error "Compiler not support\n\r"
#endif

#if(TGUI_COLOR_DEPTH == TGUI_COLOR_BITS_8)
	typedef unsigned char TGUI_COLOR;
#elif (TGUI_COLOR_DEPTH == TGUI_COLOR_BITS_16)
	typedef unsigned short TGUI_COLOR;
#elif (TGUI_COLOR_DEPTH == TGUI_COLOR_BITS_24)
	typedef unsigned int TGUI_COLOR;
#else
	#error "\"TGUI_COLOR_DEPTH\" not support\n\r"
#endif


typedef bool         TGUI_BOOL;

typedef enum{
	TGUI_COLOR_BITS_8 = 0,
	TGUI_COLOR_BITS_16 = 1,
	TGUI_COLOR_BITS_24 = 2,
}TGUI_COLOR_DEPTH_Typedef;

typedef enum{
	TGUI_COLOR_STORE_RGB565 = 0,
	TGUI_COLOR_STORE_RGB555  =1,
	TGUI_COLOR_STORE_RGB888  =2,
}TGUI_COLOR_STORE_Typedef;


struct TGUI_OPT_HOOK{
	void *(*TGUI_InitHook)(void);
	void (*TGUI_WritePixeHook)(__IN__ size_t, __IN__ size_t, TGUI_COLOR);	
	TGUI_COLOR (*TGUI_ReadPixeHook)(__IN__ size_t, __IN__ size_t);

	void *(*TGUI_Malloc)(size_t);
	void (*TGUI_Free)(void *);
	int (*TGUI_Putc)(__IN__ char);
};


#endif
