cmake_minimum_required(VERSION 3.20)

project(money)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets 3.0 REQUIRED core base gl)
include(${wxWidgets_USE_FILE})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(FFMPEG_PKG_CONFIG_SUFFIX "" CACHE STRING
    "This suffix uses for FFmpeg component names searches by pkg-config"
    )
find_package(FFmpeg
    COMPONENTS AVCODEC AVFORMAT AVUTIL AVDEVICE AVFILTER SWSCALE SWRESAMPLE
    REQUIRED)

add_subdirectory(src)
add_subdirectory(example)

execute_process(COMMAND make
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dep/glew/auto
    )
add_subdirectory(dep/glew/build/cmake)

add_subdirectory(dep/openal-soft)
