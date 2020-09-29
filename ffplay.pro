TEMPLATE = app

TARGET = ffplay

DESTDIR = $$PWD/bin
CONFIG -= qt
CONFIG += console
include(.qmake.conf)

#SDL & SDL2 library
LIBS += -lSDL2 -lSDL2main -lSDL2test
#ffmpeg library
LIBS += -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
#LIBS += -llegacy_stdio_definitions

#CONFIG-= windows
#QMAKE_LFLAGS += $$QMAKE_LFLAGS_WINDOWS
#win32: {
QMAKE_LIBS_QT_ENGTRY -= -lqtmain
#DEFINES -= QT_NEEDS_QMAIN
#}

SOURCES += \
    $$PWD/ffplay/ffplay.c \
    ffplay/audio.c \
    ffplay/avclock.c \
    ffplay/cmdutils.c \
    ffplay/decoder.c \
    ffplay/filter.c \
    ffplay/frame_queue.c \
    ffplay/options.c \
    ffplay/packet_queue.c \
    ffplay/player.c \
    ffplay/render.c \
    ffplay/soundtouch/AAFilter.cpp \
    ffplay/soundtouch/BPMDetect.cpp \
    ffplay/soundtouch/FIFOSampleBuffer.cpp \
    ffplay/soundtouch/FIRFilter.cpp \
    ffplay/soundtouch/InterpolateCubic.cpp \
    ffplay/soundtouch/InterpolateLinear.cpp \
    ffplay/soundtouch/InterpolateShannon.cpp \
    ffplay/soundtouch/PeakFinder.cpp \
    ffplay/soundtouch/RateTransposer.cpp \
    ffplay/soundtouch/SoundTouch.cpp \
    ffplay/soundtouch/TDStretch.cpp \
    ffplay/soundtouch/cpu_detect_x86.cpp \
    ffplay/soundtouch/ijksoundtouch_wrap.cpp \
    ffplay/soundtouch/mmx_optimized.cpp \
    ffplay/soundtouch/sse_optimized.cpp \
    ffplay/subtitle.c \
    ffplay/video.c

HEADERS += \
    ffplay/avclock.h \
    ffplay/cmdutils.h \
    ffplay/config.h \
    ffplay/decoder.h \
    ffplay/filter.h \
    ffplay/frame_queue.h \
    ffplay/global.h \
    ffplay/options.h \
    ffplay/packet_queue.h \
    ffplay/player.h \
    ffplay/soundtouch/AAFilter.h \
    ffplay/soundtouch/BPMDetect.h \
    ffplay/soundtouch/FIFOSampleBuffer.h \
    ffplay/soundtouch/FIFOSamplePipe.h \
    ffplay/soundtouch/FIRFilter.h \
    ffplay/soundtouch/InterpolateCubic.h \
    ffplay/soundtouch/InterpolateLinear.h \
    ffplay/soundtouch/InterpolateShannon.h \
    ffplay/soundtouch/PeakFinder.h \
    ffplay/soundtouch/RateTransposer.h \
    ffplay/soundtouch/STTypes.h \
    ffplay/soundtouch/SoundTouch.h \
    ffplay/soundtouch/TDStretch.h \
    ffplay/soundtouch/cpu_detect.h \
    ffplay/soundtouch/ijksoundtouch_log.h \
    ffplay/soundtouch/ijksoundtouch_wrap.h \
    ffplay/video_state.h

DISTFILES += \
    ffplay/soundtouch/Makefile.am
