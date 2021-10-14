package com.emulator.libretro

object NativeLib {

    /**
     * A native method that is implemented by the 'libretro' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun testCore(s: String, absoluteFile: String)

    init {
        System.loadLibrary("retro")
    }
}