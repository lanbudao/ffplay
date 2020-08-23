#ifndef DECODER_H
#define DECODER_H

#include "libavformat/avformat.h"
#include "frame_queue.h"

typedef struct Decoder {
    AVPacket pkt;
    PacketQueue *queue;
    AVCodecContext *avctx;
    int pkt_serial;
    int finished;
    int packet_pending;
    SDL_cond *empty_queue_cond;
    int64_t start_pts;
    AVRational start_pts_tb;
    int64_t next_pts;
    AVRational next_pts_tb;
    SDL_Thread *decoder_tid;
} Decoder;

void decoder_init(Decoder *d, AVCodecContext *avctx, PacketQueue *queue, SDL_cond *empty_queue_cond);

int decoder_decode_frame(Decoder *d, AVFrame *frame, AVSubtitle *sub);

void decoder_destroy(Decoder *d);

void decoder_abort(Decoder *d, FrameQueue *fq);

int decoder_start(Decoder *d, int (*fn)(void *), const char *thread_name, void* arg);

#endif // DECODER_H
