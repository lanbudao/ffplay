cmake_minimum_required(VERSION 3.1.4)
include(3rdparty.cmake)

set(MODULE ffplay)
project(${MODULE})

# Set Version
set(PLAYER_MAJOR 1)
set(PLAYER_MINOR 0)
set(PLAYER_PATCH 0)
set(PROJECT_VERSION ${PLAYER_MAJOR}.${PLAYER_MINOR}.${PLAYER_PATCH})

include_directories(${FFMPEG_INCLUDE} ${SDL_INCLUDE})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/ffplay/*.h)
include_directories(${HEADERS})

aux_source_directory(ffplay/. SOURCES)
add_executable(${MODULE} ${SOURCES} ${HEADERS})

find_library(LIB_AVFORMAT avformat ${FFMPEG_LIB})
find_library(LIB_AVCODEC avcodec ${FFMPEG_LIB})
find_library(LIB_AVUTIL avutil ${FFMPEG_LIB})
find_library(LIB_AVSCALE swscale ${FFMPEG_LIB})
find_library(LIB_AVFILTER avfilter ${FFMPEG_LIB})
find_library(LIB_AVDEVICE avdevice ${FFMPEG_LIB})
find_library(LIB_SWRESAMPLE swresample ${FFMPEG_LIB})
find_library(LIB_SDL2 SDL2 ${SDL_LIB})
find_library(LIB_SD2MAIN SDL2main ${SDLMAIN_LIB})

target_link_libraries(${MODULE} ${LIB_AVFORMAT} ${LIB_AVCODEC} ${LIB_AVUTIL}
                                ${LIB_AVSCALE} ${LIB_AVFILTER} ${LIB_AVDEVICE}
                                ${LIB_SWRESAMPLE} ${LIB_SDL2} ${LIB_SDL2MAIN})

