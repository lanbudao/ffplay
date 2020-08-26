cmake_minimum_required(VERSION 3.1.4)
include(3rdparty.cmake)

set(MODULE ffplay)
project(${MODULE})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_BUILD_TYPE Debug)
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

message(${FFMPEG_LIB})
message(${SDL_LIB})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND EXTRA_LIBS avformat avcodec swscale avutil avfilter avdevice swresample)
list(APPEND EXTRA_LIBS SDL2 SDL2main)
link_directories(${FFMPEG_LIB})
link_directories(${SDL_LIB})
target_link_libraries(${MODULE} avformat)
