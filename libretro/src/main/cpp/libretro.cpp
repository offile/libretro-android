#include <jni.h>
#include <string>
#include "Core.h"
#include "Retro.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_emulator_libretro_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_emulator_libretro_NativeLib_testCore(JNIEnv *env, jobject thiz, jstring s,
                                              jstring absolute_file) {
    std::string corePath =  env->GetStringUTFChars(s, JNI_FALSE);
    std::string rom = env->GetStringUTFChars(absolute_file, JNI_FALSE);
    auto *retro = new retro::Retro();
    retro->loadCore(corePath);
    retro->loadRom(rom);

}