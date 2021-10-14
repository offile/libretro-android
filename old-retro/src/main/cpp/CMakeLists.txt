# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project(libretro)

set(RETRO_LIB_NAME retro)
set(RETOR_SRCS
        Retro.cpp
        Core.cpp
        Log.cpp
        RetroJNI.cpp)
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


find_package(SWIG REQUIRED 4.0 COMPONENTS java)
include(${SWIG_USE_FILE})
# 设置swig文件 c++模式
set_property(SOURCE Retro.i PROPERTY CPLUSPLUS ON)

set(JAVA_GEN_PACKAGE "com.example.ndk2.jni")
string(REPLACE "." "/" JAVA_GEN_SUBDIR ${JAVA_GEN_PACKAGE})
set(JAVA_GEN_DIR ${PROJECT_SOURCE_DIR}/../java/${JAVA_GEN_SUBDIR})

#文件输出目录
set(CMAKE_SWIG_OUTDIR ${JAVA_GEN_DIR})
set(CMAKE_SWIG_FLAGS -c++ -package ${JAVA_GEN_PACKAGE})

# 开始生成
swig_add_library(appcore LANGUAGE java SOURCES Retro.i)