#include "simulater.h"

#include <stdio.h>  
#include <windows.h>  


HANDLE hMapFile = NULL;
PVOID pView = NULL;

unsigned char g_share_buf[VIEW_SIZE];


static void WriteShare(unsigned int x, unsigned int y,const unsigned char *wbuf)
{
	unsigned char *tm_ptr;

	tm_ptr = (unsigned char *)pView;

	memcpy_s(&tm_ptr[(y*IMAGE_WIDTH + x)*3], 3, &wbuf[(y*IMAGE_WIDTH + x)*3], 3);
}

static void *OpenShare(void)
{
	hMapFile = OpenFileMapping(
		FILE_MAP_WRITE,          // Read access  
		FALSE,                  // Do not inherit the name  
		FULL_MAP_NAME           // File mapping name   
	);

	int res = GetLastError();

	if(!hMapFile)
		return NULL;



	pView = MapViewOfFile(
		hMapFile,               // Handle of the map object  
		FILE_MAP_WRITE,    // Read and write access  
		0,                      // High-order DWORD of the file offset   
		VIEW_OFFSET,            // Low-order DWORD of the file offset   
		VIEW_SIZE               // The number of bytes to map to view  
	);

	return pView;

}



void *SimulaterInit(void)
{
	memset(g_share_buf, 0, VIEW_SIZE);
	return OpenShare();
}


void SimulaterDrawPoint(unsigned int x, unsigned int y, TGUI_COLOR color)
{

	g_share_buf[(y*IMAGE_WIDTH + x)*3] = (unsigned char)((color & (0xff<<16))>>16);
	g_share_buf[(y*IMAGE_WIDTH + x)*3+1] = (unsigned char)((color & (0xff<<8))>>8);
	g_share_buf[(y*IMAGE_WIDTH + x)*3+2] = (unsigned char)((color & (0xff<<0))); 
	WriteShare(x, y, (const unsigned char *)g_share_buf);
}






