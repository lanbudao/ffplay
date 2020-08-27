# ffplay
Disassemble and reconstruct ffplay for beginners to learn.
This project depends on ffmpeg4.0 and SDL2.

# how to build
You need to create a new file which named '3rdparty.cmake' in the current directory,
and set the dir of ffmpeg and sdl2 like this

set(FFMPEG_LIB "/usr/local/ffmpeg/lib")
set(FFMPEG_INCLUDE "/usr/local/ffmpeg/include")
set(SDL_LIB "/usr/local/sdl/lib")
set(SDL_INCLUDE "/usr/local/sdl/include")
