# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.
project("retro")

# Include libretro headers
include_directories(core libretro-common/include)

add_library(dylib STATIC libretro-common/dynamic/dylib.c)
add_compile_definitions(HAVE_DYNAMIC)

# Build the Oboe library
set(OBOE_DIR ./oboe)
add_subdirectory(${OBOE_DIR} ./oboe)
# Make the Oboe public headers available to our app
include_directories(${OBOE_DIR}/include)


add_library(core STATIC Core.cpp Retro.cpp)

target_link_libraries(core dylib)

add_library(retro SHARED libretro.cpp)

target_link_libraries(retro log core)