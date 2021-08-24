package com.offile.libretro

import java.io.File

class Retro {
    companion object{
        init {
            System.loadLibrary("retro")
        }
    }

    private var handle: Long = 0

    external fun loadCore(path: String)

    external fun unLoadCore()

    external fun loadRom(path: String)

    external fun unloadRom()

    external fun start()

    external fun resume()

    external fun pause()

    external fun destroy()
}