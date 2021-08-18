package com.offile.libretro

class NativeLib {

    /**
     * A native method that is implemented by the 'libretro' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'libretro' library on application startup.
        init {
            System.loadLibrary("retro")
        }
    }

    fun tt() {
    }
}
