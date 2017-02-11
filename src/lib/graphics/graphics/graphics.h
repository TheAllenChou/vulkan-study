/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
 */
/******************************************************************************/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "graphics/vulkan-util.h"

void InitWindow(unsigned width, unsigned height, const char* title);
bool WindowShouldClose();
void PollWindowEvent();
void DestroyWindow();

VkResult InitVulkan(VkInstanceHandle& hInstance);

#endif
