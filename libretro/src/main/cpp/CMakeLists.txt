# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("libretro")
set(LIB_NAME retro)
add_library(${LIB_NAME} SHARED libretro.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library(log-lib log)

# Build the Oboe library
set(OBOE_DIR ./oboe)
add_subdirectory(${OBOE_DIR} ./oboe)

# Make the Oboe public headers available to our app
include_directories(${OBOE_DIR}/include)

# Specify the libraries which our native library is dependent on, including Oboe
target_link_libraries(${LIB_NAME} ${log-lib} oboe)