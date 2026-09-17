/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

enum {
  reg_freq,    //采样率
  reg_channels,    //声道数
  reg_samples,    //每个声道的每次回调的采样点数
  reg_sbuf_size,    //读出流缓冲区的大小
  reg_init,    //用于初始化
  reg_count,    //读出当前流缓冲区已经使用的大小
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;
static int sbuf_r = 0;   //  本端读指针

static void audio_play(void *userdata, uint8_t *stream, int len) {
  int count = audio_base[reg_count];
  int nread = (count < len ? count : len);          // len:我想要多少字节,nread:我能读多少字节
  int first = CONFIG_SB_SIZE - sbuf_r;              // 到末尾还剩几格
  if (first > nread) 
    first = nread;
  memcpy(stream, sbuf + sbuf_r, first);                                  // 第一段
  if (nread > first) 
    memcpy(stream + first, sbuf, nread - first);        // 绕回段
  sbuf_r = (sbuf_r + nread) % CONFIG_SB_SIZE;
  audio_base[reg_count] = count - nread;            
  if (len > nread) 
    memset(stream + nread, 0, len - nread);   // ★ 不够补静音
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (is_write && offset == reg_init * sizeof(uint32_t)) {
    SDL_AudioSpec s = {};
    s.format   = AUDIO_S16SYS;          // 假设系统中音频数据的格式总是使用16位有符号数来表示
    s.userdata = NULL;
    s.freq     = audio_base[reg_freq];
    s.channels = audio_base[reg_channels];
    s.samples  = audio_base[reg_samples];
    s.callback = audio_play; 

    audio_base[reg_init] = 0;
    sbuf_r = 0;  
    audio_base[reg_count] = 0;
    SDL_InitSubSystem(SDL_INIT_AUDIO);//初始化音频子系统（加载驱动、准备好 API）
    SDL_OpenAudio(&s, NULL);//按参数打开设备、注册回调、分配内部缓冲。但设备处于"暂停"状态
    SDL_PauseAudio(0);               //取消暂停 → 音频线程开始周期性地调用 s.callback
  }
}

static void sbuf_io_handler(uint32_t offset, int len, bool is_write) {
  if (is_write) {
    assert(offset + len <= CONFIG_SB_SIZE);
    audio_base[reg_count] += len;   
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, sbuf_io_handler);
}
