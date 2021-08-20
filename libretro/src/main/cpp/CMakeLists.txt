# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("libretro")

set(RETRO_LIB_NAME retro)
include_directories(include)
set(RETOR_SRCS Core.cpp)
add_library(${RETRO_LIB_NAME} SHARED ${RETOR_SRCS})

# Include libretro headers
include_directories(libretro-common/include)

# Build the Oboe library
set(OBOE_DIR ./oboe)
add_subdirectory(${OBOE_DIR} ./oboe)

# Make the Oboe public headers available to our app
include_directories(${OBOE_DIR}/include)

# Specify the libraries which our native library is dependent on, including Oboe
target_link_libraries(${RETRO_LIB_NAME} log oboe)