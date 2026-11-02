#include <am.h>
#include <klib-macros.h>

#define FPS 24

uint32_t color;

static inline uint32_t pixel(uint8_t r, uint8_t g, uint8_t b) {
  return (r << 16) | (g << 8) | b;                   // RGB 合成 24 位色
}
static inline uint8_t R(uint32_t p) { return p >> 16; } // 取红色分量
static inline uint8_t G(uint32_t p) { return p >> 8; }  // 取绿色分量
static inline uint8_t B(uint32_t p) { return p; }       // 取蓝色分量

void update(uint32_t color_start, uint32_t color_end) {
  static uint8_t i = 0;
  color = pixel(
    R(color_start) + (R(color_end) - R(color_start)) * i / 255,
    G(color_start) + (G(color_end) - G(color_start)) * i / 255,
    B(color_start) + (B(color_end) - B(color_start)) * i / 255
  );
  i = (i + 1) % 256; // 循环渐变
}

void draw() {
  int w = io_read(AM_GPU_CONFIG).width;
  int h = io_read(AM_GPU_CONFIG).height;
  int block_size = w * h;
  uint32_t color_but[block_size]; // 单色填充缓冲区

  for (int k = 0; k < block_size; k++) {
    color_but[k] = color;
  }  
  io_write(AM_GPU_FBDRAW, 0, 0, color_but, w, h, true);
}

int main() {
  unsigned long last = 0;

  ioe_init(); // initialization for GUI
  while (1) {
    unsigned long upt = io_read(AM_TIMER_UPTIME).us / 1000; // 当前毫秒数
    if (upt - last > 1000 / FPS) {                            // 到帧间隔了
      update(0x00ff00, 0xff00ff); // 从黑色到白色渐变
      draw();
      last = upt;
    }
  }
  return 0;
}
