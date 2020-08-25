#ifndef PLAYER_H
#define PLAYER_H

#include "options.h"
#include "video_state.h"

extern int64_t audio_callback_time;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

VideoState *stream_open(const char *filename, AVInputFormat *iformat);

void refresh_loop_wait_event(VideoState *is, SDL_Event *event);

/* seek in the stream */
void stream_seek(VideoState *is, int64_t pos, int64_t rel, int seek_by_bytes);
/* pause or resume the video */
void stream_toggle_pause(VideoState *is);

void toggle_pause(VideoState *is);

void toggle_mute(VideoState *is);

void update_volume(VideoState *is, int sign, double step);

void step_to_next_frame(VideoState *is);

void seek_chapter(VideoState *is, int incr);

void seek(VideoState* cur_stream, double incr);

int read_thread(void *arg);

/* open a given stream. Return 0 if OK */
int stream_component_open(VideoState *is, int stream_index);

void stream_cycle_channel(VideoState *is, int codec_type);

//void toggle_full_screen(VideoState *is);

void toggle_audio_display(VideoState *is);

void stream_component_close(VideoState *is, int stream_index);

void stream_close(VideoState *is);

#endif // PLAYER_H
