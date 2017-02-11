/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
 */
/******************************************************************************/

#include "graphics/graphics.h"

int main() {
  InitWindow(800, 600, "Triangle");

  VkInstanceHandle hInstance;
  InitVulkan(hInstance);
  
  while (!WindowShouldClose())
  {
    PollWindowEvent();
  }

  DestroyWindow();

  return 0;
}
