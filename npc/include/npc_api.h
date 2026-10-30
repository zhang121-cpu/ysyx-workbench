#ifndef NPC_API_H
#define NPC_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <common.h> 

void npc_single_cycle(void);
void npc_reset(int n);
bool npc_in_clk0_eval(void);

#ifdef CONFIG_WAVE_RECORD
void init_wave(const char *log_file);
void npc_wave_record(void);
#endif

void init_monitor(int argc, char *argv[]);
void engine_start(void);
int  is_exit_status_bad(void);

#ifdef __cplusplus
}
#endif

#endif