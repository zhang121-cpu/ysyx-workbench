#include <am.h>
#include <nemu.h>
#include <klib.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

static int w = 0;   //  本端写指针

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  w = 0;  
  outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  int len = (uint8_t *)ctl->buf.end - (uint8_t *)ctl->buf.start;   // ① 本次交付的字节数
  if (len <= 0) return;

  int bufsize = inl(AUDIO_SBUF_SIZE_ADDR);                         // ② 65536
  uint8_t *sbuf = (uint8_t *)(uintptr_t)AUDIO_SBUF_ADDR;           // ③ 流缓冲区地址

  while (inl(AUDIO_COUNT_ADDR) + len > bufsize);                   // ④ 水位不够就等

  int first = bufsize - w;                                          // ⑤ 到末尾还剩几格
  if (first > len) 
    first = len;
  memcpy(sbuf + w, ctl->buf.start, first);                          // ⑥ 第一段
  if (len > first)                                                  // ⑦ 绕回的第二段
    memcpy(sbuf, (uint8_t *)ctl->buf.start + first, len - first);
  w = (w + len) % bufsize;                                          // ⑧ 指针前进
}
