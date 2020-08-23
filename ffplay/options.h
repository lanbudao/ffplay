#ifndef OPTIONS_H
#define OPTIONS_H

#include "libavutil/avutil.h"

#include "global.h"
#include "config.h"

struct AVInputFormat;
/* options specified by the user */
extern struct AVInputFormat *file_iformat;
extern char *input_filename;
extern char *window_title;
extern int default_width;
extern int default_height;
extern int screen_width;
extern int screen_height;
extern int screen_left;
extern int screen_top;
extern int is_full_screen;
extern int audio_disable;
extern int video_disable;
extern int subtitle_disable;
extern char* wanted_stream_spec[AVMEDIA_TYPE_NB];
extern int seek_by_bytes;
extern float seek_interval;
extern int display_disable;
extern int borderless;
extern int alwaysontop;
extern int startup_volume;
extern int show_status;
extern int av_sync_type;
extern int64_t start_time;
extern int64_t duration;
extern int fast;
extern int genpts;
extern int lowres;
extern int decoder_reorder_pts;
extern int autoexit;
extern int exit_on_keydown;
extern int exit_on_mousedown;
extern int loop;
extern int framedrop;
extern int infinite_buffer;
extern enum ShowMode show_mode;
extern const char *audio_codec_name;
extern const char *subtitle_codec_name;
extern const char *video_codec_name;
extern double rdftspeed;
extern int64_t cursor_last_shown;
extern int cursor_hidden;
#if CONFIG_AVFILTER
extern const char **vfilters_list;
extern int nb_vfilters;
extern char *afilters;
#endif
extern int autorotate;
extern int find_stream_info;
extern int filter_nbthreads;

void show_usage(void);

void deal_options(int argc, char** argv);

#endif // OPTIONS_H
