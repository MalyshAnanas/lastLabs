cmake_minimum_required(VERSION 3.24)
project(prak_3)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
link_directories("ext/SFML/lib/")

add_executable(prak_3 prak_3.cpp)

target_link_libraries("prak_3"
#        sfml-graphics-s
#        sfml-window-s
#        sfml-system-s
#        sfml-audio-s
        sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        sfml-audio-s-d
        opengl32
        freetype
        winmm
        gdi32
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)