#ifndef AVCLOCK_H
#define AVCLOCK_H

#include "global.h"
#include "SDL_config.h"

/* no AV sync correction is done if below the minimum AV sync threshold */
#define AV_SYNC_THRESHOLD_MIN 0.04
/* AV sync correction is done if above the maximum AV sync threshold */
#define AV_SYNC_THRESHOLD_MAX 0.1
/* If a frame duration is longer than this, it will not be duplicated to compensate AV sync */
#define AV_SYNC_FRAMEDUP_THRESHOLD 0.1
/* no AV correction is done if too big error */
#define AV_NOSYNC_THRESHOLD 10.0

#define EXTERNAL_CLOCK_MIN_FRAMES 2
#define EXTERNAL_CLOCK_MAX_FRAMES 10

/* external clock speed adjustment constants for realtime sources based on buffer fullness */
#define EXTERNAL_CLOCK_SPEED_MIN  0.900
#define EXTERNAL_CLOCK_SPEED_MAX  1.010
#define EXTERNAL_CLOCK_SPEED_STEP 0.001

extern int64_t audio_callback_time;

typedef struct Clock {
    double pts;           /* clock base */
    double pts_drift;     /* clock base minus time at which we updated the clock */
    double last_updated;
    double speed;
    int serial;           /* clock is based on a packet with this serial */
    int paused;
    int *queue_serial;    /* pointer to the current packet queue serial, used for obsolete clock detection */
} Clock;

typedef struct VideoState VideoState;
int get_master_sync_type(VideoState *is);

/* get the current master clock value */
double get_master_clock(VideoState *is);

double get_clock(Clock *c);

void set_clock_at(Clock *c, double pts, int serial, double time);

void set_clock(Clock *c, double pts, int serial);

void set_clock_speed(Clock *c, double speed);

void init_clock(Clock *c, int *queue_serial);

void sync_clock_to_slave(Clock *c, Clock *slave);

void update_video_pts(VideoState *is, double pts, int64_t pos, int serial);

double compute_target_delay(double delay, VideoState *is);

void check_external_clock_speed(VideoState *is);

#endif // AVCLOCK_H
