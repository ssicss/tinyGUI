#ifndef _SIMULATER_H
#define _SIMULATER_H

#include "Tgui.h"
#include "Tgui_config.h"

#define MAP_PREFIX          L"Local\\"  
#define MAP_NAME            L"SampleMap"  
#define FULL_MAP_NAME        MAP_NAME  

#define VIEW_OFFSET         0  

#define IMAGE_WIDTH (680)
#define IMAGE_HEIGHT (480)

#define VIEW_OFFSET         0  
#define VIEW_SIZE           (IMAGE_WIDTH*IMAGE_HEIGHT*3) 

void *SimulaterInit(void);
void SimulaterDrawPoint(unsigned int x, unsigned int y, TGUI_COLOR color);

#endif
