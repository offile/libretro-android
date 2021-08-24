#include <jni.h>
#include "Retro.h"

using retro::Retro;

extern "C" {

Retro * get_retro(JNIEnv *env, jobject jRetro){
    jclass retro_class = env->FindClass("com/offile/libretro/Retro");
    jfieldID handle_field = env->GetFieldID(retro_class, "handle", "J");
    jlong handle = env->GetLongField(jRetro, handle_field);
    return reinterpret_cast<Retro *>(handle);
}

JNIEXPORT void JNICALL
Java_com_offile_libretro_Retro_loadCore(JNIEnv *env, jobject thiz, jstring path) {
    Retro *retro = get_retro(env, thiz);
    string core_path = env->GetStringUTFChars(path, JNI_FALSE);
    retro->loadCore(core_path);
}

JNIEXPORT void JNICALL
Java_com_offile_libretro_Retro_unLoadCore(JNIEnv *env, jobject thiz) {
    Retro *retro = get_retro(env, thiz);
    retro->unLoadCore();
}

JNIEXPORT void JNICALL
Java_com_offile_libretro_Retro_loadRom(JNIEnv *env, jobject thiz, jstring path) {
    Retro *retro = get_retro(env, thiz);
    string rom_path = env->GetStringUTFChars(path, JNI_FALSE);
    retro->loadRom(rom_path);
}

JNIEXPORT void JNICALL
Java_com_offile_libretro_Retro_unloadRom(JNIEnv *env, jobject thiz) {
    Retro *retro = get_retro(env, thiz);
    retro->unLoadCore()
}

JNIEXPORT void JNICALL
Java_com_offile_libretro_Retro_destroy(JNIEnv *env, jobject thiz) {

}


}