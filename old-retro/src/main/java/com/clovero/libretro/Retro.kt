package com.clovero.libretro

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