#include <am.h>
#include <klib-macros.h>

void draw(uint32_t color) {

  uint32_t color_but[400*300];
  
  for (int i = 0; i < 400*300; i++) {
    color_but[i] = color;
  }
  io_write(AM_GPU_FBDRAW, 0, 0, &color_but, 400, 300, true);
}

int main() {
  ioe_init(); // initialization for GUI
  while (1) {
    draw(0x000000ff);
  }
  return 0;
}
