#ifndef FILTER_H
#define FILTER_H

#include "config.h"
#include "libavfilter/avfilter.h"
#include "video_state.h"

typedef struct TextureFormatEntry {
    enum AVPixelFormat format;
    int texture_fmt;
} TextureFormatEntry;

extern const struct TextureFormatEntry sdl_texture_format_map[];
extern const int texture_fmt_elems;
extern SDL_RendererInfo renderer_info;

#if CONFIG_AVFILTER
int configure_filtergraph(AVFilterGraph *graph, const char *filtergraph,
                                 AVFilterContext *source_ctx, AVFilterContext *sink_ctx);

int configure_video_filters(AVFilterGraph *graph, VideoState *is, const char *vfilters, AVFrame *frame);

int configure_audio_filters(VideoState *is, const char *afilters, int force_output_format);
#endif  /* CONFIG_AVFILTER */

#endif // FILTER_H
