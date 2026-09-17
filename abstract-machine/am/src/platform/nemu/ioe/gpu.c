#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t screen = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = screen >> 16, .height = screen & 0xffff,
    .vmemsz = ((screen >> 16) * (screen & 0xffff) * sizeof(uint32_t))
  };
}

//填补帧缓冲区中的一个方块的颜色，完成后根据sync标志决定是否同步刷新屏幕
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y;
  int w = ctl->w, h = ctl->h;
  uint32_t scr_w = inl(VGACTL_ADDR) >> 16;          
  uint32_t *fb  = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *src = (uint32_t *)ctl->pixels;

  for (int j = 0; j < h; j ++) {
    for (int i = 0; i < w; i ++) {
      fb[(y + j) * scr_w + (x + i)] = src[j * w + i];
    }
  }

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
